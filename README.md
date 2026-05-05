DataFlow Sense: Translator SQL Hibrid
DataFlow Sense este un ecosistem hibrid dezvoltat pentru disciplina Limbaje Formale și Tehnici de Compilare (LFT). Aplicația realizează traducerea interogărilor SQL în limbaj natural (Română), combinând rigoarea analizei sintactice clasice cu flexibilitatea procesării limbajului natural (NLP).

Arhitectura Sistemului
Proiectul integrează două metodologii distincte pentru a asigura o procesare robustă:

1. Componenta Deterministă (Lex & Yacc)
Lexer (Flex): Realizează analiza lexicală, identificând token-uri precum SELECT, FROM, WHERE, identificatori de tabele și operatori.

Parser (Bison/Yacc): Verifică gramatica SQL (LALR) și generează o traducere analitică pe baza structurii ierarhice a interogării.

Backend: Nucleul de procesare este scris în C, compilat sub formă de executabil nativ pentru performanță maximă.

2. Componenta Probabilistică (AI - Hugging Face)
Model: DistilBERT (stocat local în ./sql_model_local).

Rol: Analizează contextul interogării, clasifică tipul de operație și oferă un scor de încredere, detectând potențiale riscuri de securitate sau anomalii de performanță.

3. Interfața Utilizator (Streamlit)
Tehnologie: Python & Streamlit.

Rol: Servește drept punct de legătură (orchestrator) între utilizator, modelul AI și executabilul C.
