import math

try:
    r = float(input("Raio: "))
    area = math.pi * r*r
    circ = 2 * math.pi * r
except ValueError:
    print("Valor inválido.")
else:
    print("Área =", area)
    print("Circunferência =", circ)
