valor_compra=float(input("Qual o valor da compra?"))
if valor_compra>200:
    desconto=0.2
else:
    if valor_compra>=100:
        desconto=0.1
    else:
        desconto=0
print("Valor final com desconto: R$", valor_compra-valor_compra*desconto)