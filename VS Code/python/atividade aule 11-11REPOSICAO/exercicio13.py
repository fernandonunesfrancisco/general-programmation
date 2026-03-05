import json

config = {"usuario": "admin", "tema": "dark", "idioma": "pt-br"}

with open("config.json","w",encoding="utf-8") as f:
    json.dump(config, f, ensure_ascii=False, indent=2)

with open("config.json","r",encoding="utf-8") as f:
    novo = json.load(f)

print("Carregado:", novo)
print("Tema:", novo.get("tema"))
