n=int(input("Quantos números N serão digitados?"))
soma=0.0
zero=False
for i in range(n):
    print("Insira número ", i+1, ":")
    numero=float(input())
    if soma==0.0 and numero==0:
        zero=True
    if numero%5==0:
        soma+=numero
if soma==0.0 and zero==False:
    print("Nenhum múltiplo de 5")
else:
    print("Dos ", n, "números dados, a soma dos múltiplos de 5 é ", soma)