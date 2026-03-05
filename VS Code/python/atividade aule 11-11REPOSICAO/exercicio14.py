import os

itens = os.listdir(".")
print("Itens no diretório:", itens)

print("Apenas arquivos:")
for i in itens:
    if os.path.isfile(i):
        print(i)
