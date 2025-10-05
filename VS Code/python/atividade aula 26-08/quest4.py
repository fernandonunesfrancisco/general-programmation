contador_par=0
contador_impar=0
for i in range(4):
    numero=int(input("Insira o número: "))
    if numero % 2==0:
        contador_par+=1
    else:
        contador_impar+=1
print("Número de pares: ", contador_par, "\nNúmero de ímpares: ", contador_impar)