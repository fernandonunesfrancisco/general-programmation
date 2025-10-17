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
            matricula=input("Insira a matrícula: ")


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