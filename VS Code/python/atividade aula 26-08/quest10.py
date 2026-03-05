total=0
while True:
    print("Menu:")
    print("1. Adicionar")
    print("2. Subtrair")
    print("3. Mostrar total")
    print("4. Sair")
    escolha=int(input("Escolha: "))
    if escolha ==1:
        add=int(input("Digite o valor: "))
        total+=add
    elif escolha ==2:
        sub=int(input("Digite o valor: "))
        total-=sub
    elif escolha ==3:
        print("Total atual: ", total)
    else:
        break