# Universidade Python - Davi Waltrick de Souza 8417512, Fernando Nunes Francisco 8460280, João Vitor Steiner 8577960
import os

alunos={}
disciplinas={}
matriculas=[]



def submenu_alunos():
    while True:
        print("=== Gestão de Alunos ===")
        print("[1] Cadastrar Aluno")
        print("[2] Listar Alunos")
        print("[3] Buscar Aluno por Matrícula")
        print("[4] Voltar ao Menu Principal")
        opcao=input()
        if opcao=="1":
            os.system("clr")
            matricula=input("Insira a matrícula: ").strip()
            if not validar_matricula(matricula):
                print("Matrícula inválida!")
                os.system("pause")
                return
            if matricula in alunos:
                print("Matrícula já cadastrada.")
                os.system("pause")
                return
            nome=input("Nome do Aluno: ")
            if nome == "":
                print("Nome inváldo")
                os.system("pause")
                return
            alunos[matricula]={"nome": nome}
            print("Aluno cadastrado.")
            os.system("pause")
        elif opcao =="2":
            os.system("clr")
            print("=== Lista de Alunos ===")
            if len(alunos)==0:
                print("Nenhum aluno cadastrado.")
            else:
                print("Matricula\tNome")
                print("-"*40)
                for mat, info in alunos.itens():
                    print(f"{mat}\t{info['nome']}")
            os.system("pause")
        elif opcao =="3":
            os.system("clr")
            matricula=input("Informe a matrícula: ").strip()
            if matricula in alunos:
                print(f"Nome: {alunos[matricula]['nom']}")
            else:
                print("Aluno não encontrado.")
            os.system("pause")
        elif opcao =="4":
            break
        else:
            print("Opção inválida.")
            os.system("pause")



def menu_principal():
    while True:
        os.system("cls")
        print("====== Sistema de Gestão Acadêmica - Universidade Python ======")
        print("[1] Gestão de Alunos")
        print("[2] Gestão de Disciplinas")
        print("[3] Gestão de Matrículas")
        print("[4] Geração de Relatórios")
        print("[5] Sair")
        print("===============================================================")
        opcao=input()
        if opcao == "1":
            submenu_alunos()
        elif opcao == "2":
            submenu_disciplinas()
        elif opcao == "3":
            submenu_matriculas()
        elif opcao == "4":
            submenu_relatorios()
        elif opcao == "5":
            os.system("clr")
            print("Programa encerrado")
            break
        else:
            print("Opção inválida")
            os.system("pause")