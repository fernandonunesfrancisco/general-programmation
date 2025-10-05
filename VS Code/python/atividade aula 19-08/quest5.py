anos=int(input("Quantos anos de serviço?"))
anos_status="Sênior" if anos>10 else "Pleno" if anos>=6 else "Júnior"
print(anos_status)