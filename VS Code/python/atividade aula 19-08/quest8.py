a=float(input("Insira lado a do triângulo: "))
b=float(input("Insira lado b do triângulo: "))
c=float(input("Insira lado c do triângulo: "))
if a<b+c and b<a+c and c<a+b:
    print("Forma um triângulo.")
else:
    print("Não forma um triângulo.")