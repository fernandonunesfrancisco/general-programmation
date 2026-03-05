cont=0
vogais="aeiou"
frase=input("Insira palavra: ").lower()
for letra in frase:
    if letra in vogais:
        cont+=1
print("A frase possui ", cont, "vogais.")