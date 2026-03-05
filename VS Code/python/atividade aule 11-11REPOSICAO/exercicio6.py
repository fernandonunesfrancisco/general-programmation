def definir_senha(senha: str) -> None:
    if len(senha) < 8:
        raise ValueError("A senha deve ter pelo menos 8 caracteres.")
    print("Senha definida com sucesso!")

if __name__ == "__main__":
    s = input("Senha: ")
    try:
        definir_senha(s)
    except ValueError as e:
        print("Erro:", e)
