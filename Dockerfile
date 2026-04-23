
FROM python:3.9-slim

RUN apt-get update && apt-get install -y \
    build-essential \
    flex \
    bison \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY requirements.txt .
RUN pip install --no-cache-dir -r requirements.txt

COPY . .

RUN flex sql.l && \
    bison -d sql.y && \
    gcc lex.yy.c sql.tab.c -o sql_parser_linux

EXPOSE 8501

CMD ["streamlit", "run", "app.py", "--server.port=8501", "--server.address=0.0.0.0"]