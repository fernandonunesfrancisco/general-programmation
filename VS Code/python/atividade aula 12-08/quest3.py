preco_original=float(input("Qual o preço original?"))
desconto=int(input("Qual o percentual de desconto?"))
preco_final=preco_original-0.01*desconto*preco_original
print("Valor do produto com desconto: R$", preco_final)