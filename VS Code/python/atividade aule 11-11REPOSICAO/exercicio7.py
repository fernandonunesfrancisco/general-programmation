def soma_numeros(arquivo: str = "numeros.txt") -> int:
    total = 0
    try:
        with open(arquivo, "r", encoding="utf-8") as f:
            for linha in f:
                t = linha.strip()
                if t.lower() == "fim":
                    break
                try:
                    total += int(t)
                except ValueError:
                    pass
        return total
    except FileNotFoundError:
        print("Arquivo não encontrado.")
        return 0

if __name__ == "__main__":
    print("Soma =", soma_numeros())
