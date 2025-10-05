while True:
    numero=int(input("Digite um número para acessar sua tabuada (0 para sair): "))
    if numero == 0:
        print("Saindo...")
        break
    for i in range(10):
        print("\n", numero," x ", i+1, "= ", numero*(i+1))