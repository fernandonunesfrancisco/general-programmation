config = {"host": "localhost", "user": "admin"}

chave = input("Chave desejada: ").strip()

try:
    print(chave, "=", config[chave])
except KeyError:
    print("Chave inexistente.")
