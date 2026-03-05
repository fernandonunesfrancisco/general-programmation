from datetime import datetime

def log(msg: str, arquivo: str = "app.log"):
    ts = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    with open(arquivo, "a", encoding="utf-8") as f:
        f.write(f"[{ts}] {msg}\n")

if __name__ == "__main__":
    m = input("Mensagem para o log: ")
    log(m)
    print("Mensagem registrada!")
