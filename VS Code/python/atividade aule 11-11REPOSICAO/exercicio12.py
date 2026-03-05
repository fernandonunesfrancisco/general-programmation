from datetime import datetime

data = input("Data de nascimento (DD/MM/AAAA): ")

try:
    n = datetime.strptime(data, "%d/%m/%Y")
    hoje = datetime.now()
    print("Dias vividos:", (hoje - n).days)
except ValueError:
    print("Formato inválido.")
