import streamlit as st
import subprocess
import platform
import os
from transformers import pipeline

cmd_backend = './sql_parser_linux' if platform.system() == 'Linux' else 'sql_parser.exe'

@st.cache_resource
def load_ai_model():
    return pipeline(
        "text-classification", 
        model="./sql_model_local", 
        tokenizer="./sql_model_local"
    )

classifier = load_ai_model()

st.set_page_config(page_title="DataFlow Sense - SQL Translator", page_icon="🔍")

st.title("🔍 DataFlow Sense")
st.subheader("Translator SQL Hibrid (Deterministic + AI)")

st.markdown("""
Această aplicație combină rigoarea **Analizei Sintactice (Lex & Yacc)** cu puterea **AI (Hugging Face)**.
""")

query = st.text_area("Introduceți interogarea SQL aici:",
                     placeholder="SELECT nume FROM angajati WHERE salariu > 5000",
                     height=150)

if st.button("Translatează"):
    if query.strip():
        with st.status("🤖 AI-ul analizează tipul interogării...", expanded=True) as status:
            ai_result = classifier(query)
            label = ai_result[0]['label']
            score = ai_result[0]['score']

            st.write(f"### 📊 Clasificare AI:")
            st.info(f"Tip detectat: **{label}** (Siguranță: {score:.2f})")

            if "JOIN" in query.upper() and "ON" not in query.upper():
                st.error("💡 Sfat AI: Pare că lipsește clauza ON pentru JOIN.")
            elif "*" in query and "SELECT" in query.upper():
                st.warning("💡 Sfat Optimizare: Evitați SELECT *.")
            else:
                st.success("💡 Sfat AI: Structură optimă detectată.")

            status.update(label="Analiză AI Finalizată!", state="complete", expanded=False)

        try:
            process = subprocess.Popen(
                [cmd_backend],  
                stdin=subprocess.PIPE,
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
                text=True
            )

            stdout, stderr = process.communicate(input=query + "\n")

            if "TRADUCERE ANALITICA:" in stdout:
                traducere = stdout.split("TRADUCERE ANALITICA:")[1].strip()
                st.success("✅ Analiză Sintactică Reușită!")
                st.info(traducere)

                with st.expander("🔬 Detalii tehnice"):
                    st.code(stdout)
            else:
                st.error("❌ Eroare de sintaxă detectată!")
                if stderr:
                    st.text(f"Detalii: {stderr}")

        except FileNotFoundError:
            st.error(f"Eroare: Executabilul '{cmd_backend}' nu a fost găsit!")
    else:
        st.warning("Vă rugăm să introduceți o interogare.")

st.sidebar.info("Proiect LFT - Dockerized")