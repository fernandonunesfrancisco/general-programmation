# Supermercado Python - Davi Waltrick de Souza 8417512, Fernando Nunes Francisco 8460280, João Vitor Steiner 8577960

total_nomes = ["arroz", "feijao", "oleo", "cafe", "leite"]
total_precos = [25.50, 8.90, 7.00, 50.00, 4.50]

quantidade = [0, 0, 0, 0, 0]
subtotal = [0, 0, 0, 0, 0]

while True:
    while True:
        print("**** Supermercado Python ****")
        print("1. Adicionar item ao carrinho")
        print("2. Ver total da compra")
        print("3. Finalizar compra")
        resp = input()
        if resp.isdigit():
            resp = int(resp)
            if 0 < resp < 4:
                break
        print("Opção inválida.")

    if resp == 1:
        while True:
            print("Qual o nome do produto?")
            nome_produto = input().lower().strip()

            if nome_produto == "óleo de soja" or nome_produto == "oleo de soja" or nome_produto == "óleo" or nome_produto == "oleo":
                nome_produto = "oleo"

            encontrado = False
            for i in range(5):
                if nome_produto == total_nomes[i]:
                    while True:
                        print("Qual a quantidade desejada de", total_nomes[i], "?")
                        qtd = input()
                        if qtd.isdigit() and int(qtd) > 0:
                            qtd = int(qtd)
                            quantidade[i] += qtd
                            subtotal_item = qtd * total_precos[i]
                            if qtd > 3:
                                desconto = subtotal_item * 0.03
                                subtotal_item -= desconto
                                print("-> Desconto de 3% por volume aplicado.")

                            subtotal[i] += subtotal_item
                            print("Produto adicionado com sucesso!")
                            break
                        else:
                            print("Quantidade inválida.")
                    encontrado = True
                    break

            if not encontrado:
                print("Produto inválido.")
            break  

    elif resp == 2:
        total = 0
        for i in range(5):
            total += subtotal[i]
        print("Total parcial: R$")
        print(total)

    elif resp == 3:
        print("==================== RECIBO ===================")
        print("--------------- ITENS COMPRADOS ---------------")
        print("Qtd. Produto (Preco Un.) Subtotal")
        print("-----------------------------------------------")

        total_bruto = 0
        for i in range(5):
            if quantidade[i] > 0:
                subtotal_item = subtotal[i]
                total_bruto += subtotal_item
                print(quantidade[i], "x", total_nomes[i], "(R$", total_precos[i], "/un) R$", subtotal_item)

        print("-----------------------------------------------")
        print("Total Bruto: R$")
        print(total_bruto)

        desconto_final = 0
        if total_bruto > 200:
            desconto_final = total_bruto * 0.15
            print("Desconto da Compra (15%): R$")
            print(desconto_final)
        elif total_bruto >= 100:
            desconto_final = total_bruto * 0.10
            print("Desconto da Compra (10%): R$")
            print(desconto_final)

        valor_final = total_bruto - desconto_final
        print("-----------------------------------------------")
        print("Valor Final a Pagar: R$")
        print(valor_final)
        print("===============================================")
        print("Obrigado pela sua compra!\n")
        break