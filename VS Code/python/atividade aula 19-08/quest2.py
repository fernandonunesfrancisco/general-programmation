numero=int(input("Digite um numero: "))
mod= numero%5
eh_multiplho = "é" if mod == 0 else "não é"

if mod==0:
    print(numero, "é múltiplo de 5")
else:
    print(numero, "não é múltiplo de 5")