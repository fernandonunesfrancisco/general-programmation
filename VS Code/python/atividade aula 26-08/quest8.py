while True:
    while True:
        idade=int(input("Qual a idade?"))
        if idade==-1:
            break
        elif 120>=idade>=0:
            break
        else:
            print("Idade inválida.")
    if idade==-1:
        break
    elif idade<13:
        print("Criança.")
    elif idade<18:
        print("Adolescente.")
    elif idade<59:
        print("Adulto.")
    else:
        print("Idoso.")