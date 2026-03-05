import os

path = "C:/Windows/teste.txt" if os.name == "nt" else "/etc/teste.txt"

try:
    with open(path, "w", encoding="utf-8") as f:
        f.write("Teste de escrita.")
    print("Escrita concluída (inesperado em local protegido).")
except PermissionError:
    print("Permissão negada.")
except FileNotFoundError:
    print("Caminho não encontrado.")
finally:
    print("Finalizado.")
