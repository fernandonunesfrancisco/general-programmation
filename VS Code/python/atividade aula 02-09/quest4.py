numero_celular=input("Digite número de celular (apenas dígitos): ")
if not numero_celular.isdigit:
    print("Número inválido. Digite apenas números.")
elif len(numero_celular)>9:
    print("Número inválido!")
elif len(numero_celular)<9:
    print("Número inválido. O número deverá ter 9 digitos.")
else:
    print(numero_celular)