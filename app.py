import os
import platform
import re
import subprocess

import streamlit as st
from transformers import pipeline


st.set_page_config(
    page_title="DataFlow Sense - SQL Translator",
    page_icon="random",
    layout="centered",
)


cmd_backend = "./sql_parser_linux" if platform.system() == "Linux" else "sql_parser.exe"
FLAN_T5_LOCAL_PATH = "./flan_t5_small"
FLAN_T5_MODEL_NAME = "google/flan-t5-small"


@st.cache_resource
def load_ai_model():
    """Incarca modelul local, daca exista."""
    model_path = "./sql_model_local"
    if os.path.exists(model_path) and "config.json" in os.listdir(model_path):
        try:
            return pipeline("text-classification", model=model_path, tokenizer=model_path)
        except Exception as exc:
            st.warning(f"Modelul local nu a putut fi incarcat: {exc}")
            return None

    st.warning("Modelul local nu a fost gasit. Aplicatia foloseste agentul SQL bazat pe reguli.")
    return None


@st.cache_resource
def load_llm_translator():
    """Incarca FLAN-T5 pentru traduceri fallback cand parserul Lex/Yacc esueaza."""
    model_ref = FLAN_T5_LOCAL_PATH if os.path.exists(FLAN_T5_LOCAL_PATH) else FLAN_T5_MODEL_NAME
    return pipeline("text-generation", model=model_ref, tokenizer=model_ref)


def translate_with_llm(query):
    """Genereaza o explicatie aproximativa in romana pentru query-uri neacoperite de gramatica."""
    normalized_query = " ".join(query.split())
    prompt = (
        "Tradu in romana urmatoarea interogare SQL. "
        "Daca sintaxa nu este standard, explica intentia probabila. "
        "Raspunde doar cu traducerea, fara sa repeti cerinta.\n\n"
        f"SQL: {normalized_query}\n"
        "Traducere:"
    )

    translator = load_llm_translator()
    result = translator(
        prompt,
        max_new_tokens=120,
        do_sample=False,
        return_full_text=False,
    )
    generated_text = result[0]["generated_text"].strip()

    if "Traducere:" in generated_text:
        generated_text = generated_text.split("Traducere:", 1)[1].strip()
    if not generated_text or generated_text == prompt.strip():
        generated_text = fallback_sql_translation(normalized_query)

    return generated_text


def fallback_sql_translation(query):
    """Fallback simplu cand LLM-ul intoarce promptul in loc de raspuns."""
    upper_query = query.upper()

    if " UNION " in upper_query:
        return "Interpretare aproximativa: query-ul combina rezultatele a doua interogari folosind UNION."
    if upper_query.startswith("SELECT") and " FROM " in upper_query:
        return "Interpretare aproximativa: query-ul selecteaza date dintr-un tabel, posibil folosind o sintaxa neacoperita de parser."
    if upper_query.startswith("INSERT"):
        return "Interpretare aproximativa: query-ul insereaza date intr-un tabel."
    if upper_query.startswith("UPDATE"):
        return "Interpretare aproximativa: query-ul actualizeaza date dintr-un tabel."
    if upper_query.startswith("DELETE"):
        return "Interpretare aproximativa: query-ul sterge date dintr-un tabel."
    if upper_query.startswith("CREATE"):
        return "Interpretare aproximativa: query-ul creeaza un obiect in baza de date."

    return "Interpretare aproximativa: query-ul SQL nu este acoperit complet de gramatica Lex/Yacc."


class SQLInsightAgent:
    """Agent local pentru analiza de intentie, risc si calitate a interogarilor SQL."""

    SUPPORTED_OPERATIONS = {
        "SELECT",
        "INSERT",
        "UPDATE",
        "DELETE",
        "CREATE",
        "DROP",
        "ALTER",
    }

    RISK_PATTERNS = [
        (r"(--|/\*|\*/)", 18, "contine comentarii SQL, folosite frecvent in injection"),
        (r"\bUNION\s+SELECT\b", 25, "foloseste UNION SELECT, tipar sensibil pentru exfiltrare"),
        (r"\bOR\s+1\s*=\s*1\b|\bAND\s+1\s*=\s*1\b", 30, "contine conditie tautologica"),
        (r";\s*(DROP|DELETE|UPDATE|INSERT|ALTER|CREATE)\b", 28, "contine comenzi concatenate dupa punct si virgula"),
        (r"\b(SLEEP|BENCHMARK|WAITFOR|XP_CMDSHELL)\s*\(", 35, "apeleaza functii periculoase sau de intarziere"),
        (r"\bDROP\s+TABLE\b", 22, "sterge un tabel complet"),
        (r"\bDELETE\s+FROM\b(?![\s\S]*\bWHERE\b)", 26, "DELETE fara WHERE poate sterge toate randurile"),
        (r"\bUPDATE\b(?![\s\S]*\bWHERE\b)", 24, "UPDATE fara WHERE poate modifica toate randurile"),
    ]

    CLAUSE_PATTERNS = {
        "JOIN": r"\b(?:INNER|LEFT|RIGHT|FULL|CROSS)?\s*JOIN\b",
        "WHERE": r"\bWHERE\b",
        "GROUP BY": r"\bGROUP\s+BY\b",
        "HAVING": r"\bHAVING\b",
        "ORDER BY": r"\bORDER\s+BY\b",
        "LIMIT": r"\bLIMIT\b",
        "SUBQUERY": r"\(\s*SELECT\b",
        "AGGREGATE": r"\b(COUNT|SUM|AVG|MIN|MAX)\s*\(",
    }

    def __init__(self, classifier=None):
        self.classifier = classifier

    def analyze(self, query):
        normalized = " ".join(query.split())
        upper_query = normalized.upper()

        operation = self._detect_operation(upper_query)
        clauses = self._detect_clauses(upper_query)
        risk_score, reasons = self._rule_based_risk(upper_query)
        model_payload = self._model_score(query)

        if model_payload:
            model_risk = model_payload["risk_score"]
            risk_score = round((risk_score * 0.65) + (model_risk * 0.35))
            reasons.append(
                f"modelul local estimeaza risc {model_risk}% ({model_payload['label']}, incredere {model_payload['confidence']:.2f})"
            )

        suggestions = self._suggestions(operation, clauses, upper_query, risk_score)

        return {
            "operation": operation,
            "clauses": clauses,
            "risk_score": min(risk_score, 100),
            "risk_level": self._risk_level(risk_score),
            "reasons": reasons or ["nu au fost gasite tipare evidente de risc"],
            "suggestions": suggestions,
            "model": model_payload,
        }

    def _detect_operation(self, upper_query):
        match = re.match(r"^\s*([A-Z]+)", upper_query)
        if not match:
            return "NECUNOSCUT"
        operation = match.group(1)
        return operation if operation in self.SUPPORTED_OPERATIONS else operation

    def _detect_clauses(self, upper_query):
        return [
            name
            for name, pattern in self.CLAUSE_PATTERNS.items()
            if re.search(pattern, upper_query)
        ]

    def _rule_based_risk(self, upper_query):
        score = 8
        reasons = []

        for pattern, points, reason in self.RISK_PATTERNS:
            if re.search(pattern, upper_query):
                score += points
                reasons.append(reason)

        if upper_query.startswith(("DROP", "ALTER", "DELETE", "UPDATE")):
            score += 8
            reasons.append("operatia modifica sau sterge date/schema")

        if upper_query.count(";") > 1:
            score += 20
            reasons.append("contine mai multe instructiuni SQL in acelasi input")

        return min(score, 100), reasons

    def _model_score(self, query):
        if not self.classifier:
            return None

        try:
            raw_results = self.classifier(query, top_k=None)
            best = sorted(raw_results, key=lambda item: item["score"], reverse=True)[0]
            label = best["label"]
            confidence = float(best["score"])
            risk_score = round(confidence * 100) if label == "LABEL_1" else round((1 - confidence) * 100)
            return {
                "label": label,
                "confidence": confidence,
                "risk_score": risk_score,
                "raw": raw_results,
            }
        except Exception:
            return None

    def _suggestions(self, operation, clauses, upper_query, risk_score):
        suggestions = []

        if operation == "SELECT" and "WHERE" not in clauses and "LIMIT" not in clauses:
            suggestions.append("Pentru tabele mari, adauga WHERE sau LIMIT.")

        if operation in {"UPDATE", "DELETE"} and "WHERE" not in clauses:
            suggestions.append("Adauga WHERE pentru a evita modificarea tuturor randurilor.")

        if operation == "CREATE" and "PRIMARY KEY" not in upper_query:
            suggestions.append("Pentru CREATE TABLE, adauga o cheie primara.")

        if "SUBQUERY" in clauses:
            suggestions.append("Parserul Lex/Yacc actual nu traduce complet subquery-uri; foloseste JOIN daca vrei suport stabil.")

        if risk_score >= 50:
            suggestions.append("Verifica manual interogarea inainte de executie.")

        return suggestions or ["Interogarea pare potrivita pentru parserul proiectului."]

    def _risk_level(self, risk_score):
        if risk_score >= 70:
            return "ridicat"
        if risk_score >= 35:
            return "mediu"
        return "scazut"


classifier = load_ai_model()
sql_agent = SQLInsightAgent(classifier)


st.sidebar.title("Detalii tehnice")
st.sidebar.markdown(
    """
### Componente proiect
- **Analiza sintactica:** C, Flex si Bison
- **Interfata:** Python si Streamlit
- **Agent AI:** SQLInsightAgent + model local optional
- **LLM fallback:** FLAN-T5 Small pentru sintaxe neacoperite
- **Deployment:** Docker si Railway
"""
)

st.sidebar.divider()
st.sidebar.info(
    "DataFlow Sense combina parserul determinist Lex/Yacc cu un agent local de risc si un LLM fallback pentru query-uri neacoperite de gramatica."
)
st.sidebar.caption("Proiect realizat pentru disciplina LFT")


st.title("DataFlow Sense")
st.subheader("Translator SQL Hibrid (Deterministic + AI)")

st.markdown(
    """
Introduceti o interogare SQL pentru a obtine traducerea acesteia in limbaj natural, analiza de siguranta si, la nevoie, o traducere aproximativa cu FLAN-T5.
"""
)

query = st.text_area(
    "Interogare SQL:",
    placeholder="Ex: SELECT nume FROM angajati WHERE salariu > 5000",
    height=150,
)


if st.button("Translateaza si Analizeaza"):
    if query.strip():
        with st.status("Agentul SQL analizeaza interogarea...", expanded=True) as status:
            analysis = sql_agent.analyze(query)

            st.write("### Analiza agent SQL")
            col1, col2, col3 = st.columns(3)
            col1.metric("Operatie", analysis["operation"])
            col2.metric("Risc", analysis["risk_level"].capitalize())
            col3.metric("Scor risc", f"{analysis['risk_score']}%")

            if analysis["risk_level"] == "ridicat":
                st.error("Interogare cu risc ridicat.")
            elif analysis["risk_level"] == "mediu":
                st.warning("Interogare cu risc mediu.")
            else:
                st.success("Interogare cu risc scazut.")

            st.markdown("**Motive detectate:**")
            for reason in analysis["reasons"]:
                st.caption(f"- {reason}")

            st.markdown("**Sugestii:**")
            for suggestion in analysis["suggestions"]:
                st.caption(f"- {suggestion}")

            if analysis["model"]:
                with st.expander("Scoruri brute model local"):
                    st.json(analysis["model"]["raw"])

            status.update(label="Analiza agent finalizata!", state="complete", expanded=False)

        st.divider()

        try:
            process = subprocess.Popen(
                [cmd_backend],
                stdin=subprocess.PIPE,
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
                text=True,
            )

            stdout, stderr = process.communicate(input=query + "\n")

            if "TRADUCERE ANALITICA:" in stdout:
                traducere = stdout.split("TRADUCERE ANALITICA:")[1].strip()

                st.write("### Traducere in limbaj natural")
                st.info(f"**Explicatie:** {traducere}")

                with st.expander("Detalii analiza sintactica"):
                    st.code(stdout)
            else:
                st.error("Eroare de sintaxa detectata de parserul Lex/Yacc.")
                if stderr:
                    st.markdown("**Detalii eroare:**")
                    st.caption(stderr)
                else:
                    st.caption("Verifica daca interogarea respecta gramatica SQL suportata.")

                st.write("### Traducere aproximativa cu FLAN-T5")
                try:
                    with st.spinner("FLAN-T5 incearca sa interpreteze query-ul..."):
                        llm_translation = translate_with_llm(query)
                    st.info(f"**Interpretare LLM:** {llm_translation}")
                    st.caption(
                        "Aceasta traducere este generata de LLM si poate fi aproximativa; parserul Lex/Yacc ramane validatorul sintactic strict."
                    )
                except Exception as llm_exc:
                    st.warning(
                        "FLAN-T5 nu a putut fi incarcat. Descarca modelul local in folderul "
                        "'flan_t5_small' sau ruleaza aplicatia cu acces la internet pentru prima incarcare."
                    )
                    st.caption(f"Detalii LLM: {llm_exc}")

        except FileNotFoundError:
            st.error(f"Eroare critica: executabilul '{cmd_backend}' nu a fost gasit.")
        except Exception as exc:
            st.error(f"A aparut o eroare neasteptata: {exc}")
    else:
        st.warning("Introdu o interogare inainte de a apasa butonul.")
