import random
numero_aleatorio=random.randint(1, 50)
#numero_aleatorio=4 (teste)
cont=5
while True:
    numero_chutado=int(input("Chute um número de 1 a 50: "))
    if numero_chutado==numero_aleatorio:
        print("Venceu! O número correto era ", numero_aleatorio)
        break
    else:
        cont-=1
        print("Número errado.", cont, " tentativas sobrando")
    if cont==0:
        print("Perdeu!")
        break