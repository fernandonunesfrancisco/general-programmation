def ler_config(nome: str = "config.txt") -> str:
    try:
        with open(nome, "r", encoding="utf-8") as f:
            return f.read()
    except FileNotFoundError:
        padrao = "tema=claro\n"
        with open(nome, "w", encoding="utf-8") as f:
            f.write(padrao)
        return padrao

if __name__ == "__main__":
    print(ler_config())
