nota_menor=10
nota_maior=0
soma_notas=0
contador=0
while True:
    while True:
        x=float(input("Insira nota: "))
        if 0<=x<=10:
            break
        else:
            if x==-1:
                break
            else:
                print("Nota inválida.")
    if x==-1:
        break
    if x>nota_maior:
        nota_maior=x
    if x<nota_menor:
        nota_menor=x
    soma_notas+=x
    contador+=1
media=soma_notas/contador
print("Maior nota: ", nota_maior, "\nMenor nota: ", nota_menor, "\nMédia: ", media)