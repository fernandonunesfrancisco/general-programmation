print("Divisão segura:")
try:
    a = float(input("Primeiro número: "))
    b = float(input("Segundo número: "))
    r = a / b
except ValueError:
    print("Erro: valor inválido.")
except ZeroDivisionError:
    print("Erro: divisão por zero.")
else:
    print("Resultado =", r)
