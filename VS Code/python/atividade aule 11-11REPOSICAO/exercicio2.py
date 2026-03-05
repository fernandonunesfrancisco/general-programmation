def copiar_arquivo(origem: str, destino: str) -> None:
    try:
        with open(origem, "rb") as f1:
            data = f1.read()
        with open(destino, "wb") as f2:
            f2.write(data)
        print("Cópia concluída com sucesso.")
    except FileNotFoundError:
        print("Erro: arquivo de origem não encontrado.")

if __name__ == "__main__":
    o = input("Arquivo de origem: ").strip()
    d = input("Arquivo de destino: ").strip()
    copiar_arquivo(o, d)
