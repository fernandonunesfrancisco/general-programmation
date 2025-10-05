idade=int(input("Qual sua idade?"))
idade_status="Idoso" if idade>=60 else "Adulto" if idade>13 else "Criança"
print(idade_status)