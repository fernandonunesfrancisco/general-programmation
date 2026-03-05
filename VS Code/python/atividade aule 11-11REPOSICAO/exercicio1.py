def contar_linhas(nome_arquivo: str) -> int:
    try:
        with open(nome_arquivo, "r", encoding="utf-8") as f:
            return sum(1 for _ in f)
    except FileNotFoundError:
        return 0

if __name__ == "__main__":
    nome = input("Nome do arquivo: ").strip()
    print(f"Total de linhas: {contar_linhas(nome)}")
