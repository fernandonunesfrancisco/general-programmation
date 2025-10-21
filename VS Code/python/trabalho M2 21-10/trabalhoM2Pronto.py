# Universidade Python - Davi Waltrick de Souza 8417512, Fernando Nunes Francisco 8460280, João Vitor Steiner 8577960
import os

alunos: dict = {}
disciplinas: dict = {}
matriculas: list = []


def validar_matricula(matricula: str) -> bool:
    """Valida o formato da matrícula.

    Args:
        matricula (str): Número da matrícula.

    Returns:
        bool: True se válida, False caso contrário.
    """
    if len(matricula) != 7:
        return False
    if not matricula.isdigit():
        return False
    ano = matricula[:4]
    if not (1900 <= int(ano) <= 2100):
        return False
    return True


def validar_codigo_disciplina(codigo: str) -> bool:
    """Valida o formato do código da disciplina.

    Args:
        codigo (str): Código informado.

    Returns:
        bool: True se válido, False caso contrário.
    """
    if len(codigo) != 5:
        return False
    if not (codigo[0].isupper() and codigo[1].isupper()):
        return False
    if not codigo[2:].isdigit():
        return False
    return True


def submenu_alunos() -> None:
    """Submenu de gestão de alunos."""
    while True:
        os.system("cls")
        print("=== Gestão de Alunos ===")
        print("[1] Cadastrar Aluno")
        print("[2] Listar Alunos")
        print("[3] Buscar Aluno por Matrícula")
        print("[4] Voltar ao Menu Principal")
        opcao = input()
        if opcao == "1":
            os.system("cls")
            matricula = input("Insira a matrícula: ").strip()
            if not validar_matricula(matricula):
                print("Matrícula inválida!")
                os.system("pause")
                continue
            if matricula in alunos:
                print("Matrícula já cadastrada.")
                os.system("pause")
                continue
            nome = input("Nome do Aluno: ").strip()
            if nome == "":
                print("Nome inválido.")
                os.system("pause")
                continue
            alunos[matricula] = {"nome": nome}
            print("Aluno cadastrado.")
            os.system("pause")
        elif opcao == "2":
            os.system("cls")
            print("=== Lista de Alunos ===")
            if len(alunos) == 0:
                print("Nenhum aluno cadastrado.")
            else:
                print("Matrícula\tNome")
                print("-" * 40)
                for mat, info in alunos.items():
                    print(f"{mat}\t{info['nome']}")
            os.system("pause")
        elif opcao == "3":
            os.system("cls")
            matricula = input("Informe a matrícula: ").strip()
            if matricula in alunos:
                print(f"Nome: {alunos[matricula]['nome']}")
            else:
                print("Aluno não encontrado.")
            os.system("pause")
        elif opcao == "4":
            break
        else:
            print("Opção inválida.")
            os.system("pause")


def submenu_disciplinas() -> None:
    """Submenu de gestão de disciplinas."""
    while True:
        os.system("cls")
        print("=== Gestão de Disciplinas ===")
        print("[1] Cadastrar Disciplina")
        print("[2] Listar Disciplinas")
        print("[3] Buscar Disciplina por Código")
        print("[4] Voltar ao Menu Principal")
        opcao = input()
        if opcao == "1":
            os.system("cls")
            codigo = input("Código (LLNNN): ").strip()
            if not validar_codigo_disciplina(codigo):
                print("Código inválido.")
                os.system("pause")
                continue
            if codigo in disciplinas:
                print("Disciplina já cadastrada.")
                os.system("pause")
                continue
            nome = input("Nome da disciplina: ").strip()
            vagas_str = input("Número de vagas: ").strip()
            if not vagas_str.isdigit():
                print("Número inválido.")
                os.system("pause")
                continue
            disciplinas[codigo] = {"nome": nome, "vagas": int(vagas_str)}
            print("Disciplina cadastrada.")
            os.system("pause")
        elif opcao == "2":
            os.system("cls")
            print("=== Lista de Disciplinas ===")
            if len(disciplinas) == 0:
                print("Nenhuma disciplina cadastrada.")
            else:
                print("Código\tNome\tVagas")
                print("-" * 40)
                for cod, info in disciplinas.items():
                    print(f"{cod}\t{info['nome']}\t{info['vagas']}")
            os.system("pause")
        elif opcao == "3":
            os.system("cls")
            codigo = input("Informe o código: ").strip().upper()
            if codigo in disciplinas:
                print(f"Nome: {disciplinas[codigo]['nome']}")
                print(f"Vagas: {disciplinas[codigo]['vagas']}")
            else:
                print("Disciplina não encontrada.")
            os.system("pause")
        elif opcao == "4":
            break
        else:
            print("Opção inválida.")
            os.system("pause")


def submenu_matriculas() -> None:
    """Submenu de gestão de matrículas."""
    while True:
        os.system("cls")
        print("=== Gestão de Matrículas ===")
        print("[1] Realizar Inscrição")
        print("[2] Listar Inscrições")
        print("[3] Voltar ao Menu Principal")
        opcao = input()
        if opcao == "1":
            os.system("cls")
            matricula = input("Matrícula do aluno: ").strip()
            codigo = input("Código da disciplina: ").strip().upper()
            if matricula not in alunos:
                print("Aluno não cadastrado.")
                os.system("pause")
                continue
            if codigo not in disciplinas:
                print("Disciplina não cadastrada.")
                os.system("pause")
                continue
            for m in matriculas:
                if m["matricula"] == matricula and m["codigo"] == codigo:
                    print("Aluno já inscrito nesta disciplina.")
                    os.system("pause")
                    break
            else:
                if disciplinas[codigo]["vagas"] <= 0:
                    print("Não há vagas disponíveis.")
                    os.system("pause")
                    continue
                disciplinas[codigo]["vagas"] -= 1
                matriculas.append({"matricula": matricula, "codigo": codigo})
                print("Inscrição realizada.")
                os.system("pause")
        elif opcao == "2":
            os.system("cls")
            print("=== Lista de Inscrições ===")
            if len(matriculas) == 0:
                print("Nenhuma inscrição registrada.")
            else:
                for m in matriculas:
                    nome_aluno = alunos[m["matricula"]]["nome"]
                    nome_disc = disciplinas[m["codigo"]]["nome"]
                    print(f"{nome_aluno} ({m['matricula']}) -> {m['codigo']} - {nome_disc}")
            os.system("pause")
        elif opcao == "3":
            break
        else:
            print("Opção inválida.")
            os.system("pause")


def submenu_relatorios() -> None:
    """Submenu de geração de relatórios."""
    while True:
        os.system("cls")
        print("=== Geração de Relatórios ===")
        print("[1] Listar Alunos por Disciplina")
        print("[2] Listar Disciplinas por Aluno")
        print("[3] Listar Disciplinas com Vagas Esgotadas")
        print("[4] Voltar ao Menu Principal")
        opcao = input()
        if opcao == "1":
            os.system("cls")
            codigo = input("Código da disciplina: ").strip().upper()
            if codigo not in disciplinas:
                print("Disciplina não encontrada.")
                os.system("pause")
                continue
            print(f"Alunos inscritos em {codigo} - {disciplinas[codigo]['nome']}:")
            encontrou = False
            for m in matriculas:
                if m["codigo"] == codigo:
                    print(f"{m['matricula']} - {alunos[m['matricula']]['nome']}")
                    encontrou = True
            if not encontrou:
                print("Nenhum aluno inscrito.")
            os.system("pause")
        elif opcao == "2":
            os.system("cls")
            matricula = input("Matrícula do aluno: ").strip()
            if matricula not in alunos:
                print("Aluno não encontrado.")
                os.system("pause")
                continue
            print(f"Disciplinas do aluno {alunos[matricula]['nome']}:")
            encontrou = False
            for m in matriculas:
                if m["matricula"] == matricula:
                    print(f"{m['codigo']} - {disciplinas[m['codigo']]['nome']}")
                    encontrou = True
            if not encontrou:
                print("Nenhuma disciplina encontrada.")
            os.system("pause")
        elif opcao == "3":
            os.system("cls")
            encontrou = False
            for cod, info in disciplinas.items():
                if info["vagas"] == 0:
                    print(f"{cod} - {info['nome']}")
                    encontrou = True
            if not encontrou:
                print("Nenhuma disciplina esgotada.")
            os.system("pause")
        elif opcao == "4":
            break
        else:
            print("Opção inválida.")
            os.system("pause")


def menu_principal() -> None:
    """Menu principal do sistema."""
    while True:
        os.system("cls")
        print("====== Sistema de Gestão Acadêmica - Universidade Python ======")
        print("[1] Gestão de Alunos")
        print("[2] Gestão de Disciplinas")
        print("[3] Gestão de Matrículas")
        print("[4] Geração de Relatórios")
        print("[5] Sair")
        print("===============================================================")
        opcao = input()
        if opcao == "1":
            submenu_alunos()
        elif opcao == "2":
            submenu_disciplinas()
        elif opcao == "3":
            submenu_matriculas()
        elif opcao == "4":
            submenu_relatorios()
        elif opcao == "5":
            os.system("cls")
            print("Programa encerrado.")
            os.system("pause")
            break
        else:
            print("Opção inválida.")
            os.system("pause")


menu_principal()