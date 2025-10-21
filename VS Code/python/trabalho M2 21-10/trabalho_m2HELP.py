# =============================================================
# Sistema de Gestão Acadêmica - Universidade Python
# Projeto M2 - UNIVALI
# =============================================================

import os

# "Banco de dados" em memória
alunos: dict = {}
disciplinas: dict = {}
matriculas: list = []

# --------------------------
# Funções de validação
# --------------------------
def validar_matricula(matricula: str) -> bool:
    """Valida o formato de matrícula.

    O formato exigido é uma string numérica de 7 dígitos.
    Os 4 primeiros dígitos representam o ano de ingresso (entre 1900 e 2100).

    Args:
        matricula (str): Matrícula informada pelo usuário.

    Returns:
        bool: True se a matrícula estiver no formato correto, False caso contrário.
    """
    if len(matricula) != 7:
        return False
    if not matricula.isdigit():
        return False
    ano = matricula[:4]
    try:
        ano_int = int(ano)
    except ValueError:
        return False
    if not (1900 <= ano_int <= 2100):
        return False
    return True


def validar_codigo_disciplina(codigo: str) -> bool:
    """Valida o formato do código da disciplina.

    O formato exigido é LLNNN: duas letras maiúsculas seguidas de três dígitos.
    Exemplo válido: "SI100".

    Args:
        codigo (str): Código informado pelo usuário.

    Returns:
        bool: True se o código estiver no formato correto, False caso contrário.
    """
    if len(codigo) != 5:
        return False
    if not (codigo[0].isalpha() and codigo[1].isalpha()):
        return False
    if not (codigo[0].isupper() and codigo[1].isupper()):
        return False
    if not codigo[2:].isdigit():
        return False
    return True


# --------------------------
# Gestão de alunos
# --------------------------
def cadastrar_aluno() -> None:
    """Solicita dados e cadastra um novo aluno no sistema.

    Realiza validação de formato da matrícula e checa duplicidade.
    Atualiza a estrutura global `alunos` em memória.

    Returns:
        None
    """
    os.system("cls")
    print("=== Cadastrar Aluno ===")
    matricula = input("Matrícula (7 dígitos, ex: 2025001): ").strip()
    if not validar_matricula(matricula):
        print("Matrícula inválida!")
        os.system("pause")
        return
    if matricula in alunos:
        print("Matrícula já cadastrada!")
        os.system("pause")
        return
    nome = input("Nome do aluno: ").strip()
    if nome == "":
        print("Nome inválido!")
        os.system("pause")
        return
    alunos[matricula] = {"nome": nome}
    print("Aluno cadastrado com sucesso!")
    os.system("pause")


def listar_alunos() -> None:
    """Exibe a lista de alunos cadastrados (matrícula e nome).

    Se não houver alunos cadastrados, informa ao usuário.

    Returns:
        None
    """
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


def buscar_aluno() -> None:
    """Busca e exibe informações de um aluno pela matrícula.

    Solicita a matrícula e, se encontrada, exibe o nome; caso contrário,
    informa que o aluno não foi encontrado.

    Returns:
        None
    """
    os.system("cls")
    print("=== Buscar Aluno por Matrícula ===")
    matricula = input("Informe a matrícula: ").strip()
    if matricula in alunos:
        print(f"Nome: {alunos[matricula]['nome']}")
    else:
        print("Aluno não encontrado.")
    os.system("pause")


def menu_alunos() -> None:
    """Loop do submenu de gestão de alunos.

    Mostra opções de cadastro, listagem e busca e roteia para as funções
    correspondentes até o usuário escolher voltar.

    Returns:
        None
    """
    while True:
        os.system("cls")
        print("=== Gestão de Alunos ===")
        print("[1] Cadastrar Aluno")
        print("[2] Listar Alunos")
        print("[3] Buscar Aluno por Matrícula")
        print("[4] Voltar")
        opc = input("Escolha: ")
        if opc == "1":
            cadastrar_aluno()
        elif opc == "2":
            listar_alunos()
        elif opc == "3":
            buscar_aluno()
        elif opc == "4":
            break
        else:
            print("Opção inválida!")
            os.system("pause")


# --------------------------
# Gestão de disciplinas
# --------------------------
def cadastrar_disciplina() -> None:
    """Solicita dados e cadastra uma nova disciplina no sistema.

    Valida o formato do código (LLNNN) e o número de vagas.
    Atualiza a estrutura global `disciplinas`.

    Returns:
        None
    """
    os.system("cls")
    print("=== Cadastrar Disciplina ===")
    codigo = input("Código (LLNNN, ex: SI100): ").strip().upper()
    if not validar_codigo_disciplina(codigo):
        print("Código inválido!")
        os.system("pause")
        return
    if codigo in disciplinas:
        print("Disciplina já cadastrada!")
        os.system("pause")
        return
    nome = input("Nome da disciplina: ").strip()
    vagas_input = input("Número de vagas: ").strip()
    if not vagas_input.isdigit():
        print("Número inválido de vagas!")
        os.system("pause")
        return
    vagas = int(vagas_input)
    disciplinas[codigo] = {"nome": nome, "vagas": vagas}
    print("Disciplina cadastrada com sucesso!")
    os.system("pause")


def listar_disciplinas() -> None:
    """Exibe a lista de disciplinas cadastradas com código, nome e vagas.

    Returns:
        None
    """
    os.system("cls")
    print("=== Lista de Disciplinas ===")
    if len(disciplinas) == 0:
        print("Nenhuma disciplina cadastrada.")
    else:
        print("Código\tNome\t\tVagas")
        print("-" * 40)
        for cod, info in disciplinas.items():
            print(f"{cod}\t{info['nome']}\t\t{info['vagas']}")
    os.system("pause")


def buscar_disciplina() -> None:
    """Busca e exibe detalhes de uma disciplina pelo código.

    Solicita o código e, se encontrado, mostra nome e vagas.

    Returns:
        None
    """
    os.system("cls")
    print("=== Buscar Disciplina ===")
    codigo = input("Informe o código: ").strip().upper()
    if codigo in disciplinas:
        print(f"Nome: {disciplinas[codigo]['nome']}")
        print(f"Vagas: {disciplinas[codigo]['vagas']}")
    else:
        print("Disciplina não encontrada.")
    os.system("pause")


def menu_disciplinas() -> None:
    """Loop do submenu de gestão de disciplinas.

    Permite cadastrar, listar e buscar disciplinas até o usuário voltar.

    Returns:
        None
    """
    while True:
        os.system("cls")
        print("=== Gestão de Disciplinas ===")
        print("[1] Cadastrar Disciplina")
        print("[2] Listar Disciplinas")
        print("[3] Buscar Disciplina por Código")
        print("[4] Voltar")
        opc = input("Escolha: ")
        if opc == "1":
            cadastrar_disciplina()
        elif opc == "2":
            listar_disciplinas()
        elif opc == "3":
            buscar_disciplina()
        elif opc == "4":
            break
        else:
            print("Opção inválida!")
            os.system("pause")


# --------------------------
# Gestão de matrículas
# --------------------------
def realizar_inscricao() -> None:
    """Realiza a inscrição de um aluno em uma disciplina.

    Verifica existência do aluno e da disciplina, checa se o aluno já está
    inscrito e se há vagas antes de registrar a matrícula e decrementar vagas.

    Returns:
        None
    """
    os.system("cls")
    print("=== Realizar Inscrição ===")
    matricula = input("Matrícula do aluno: ").strip()
    codigo = input("Código da disciplina: ").strip().upper()

    if matricula not in alunos:
        print("Aluno não cadastrado.")
        os.system("pause")
        return
    if codigo not in disciplinas:
        print("Disciplina não cadastrada.")
        os.system("pause")
        return
    for m in matriculas:
        if m["matricula"] == matricula and m["codigo"] == codigo:
            print("Aluno já inscrito nesta disciplina.")
            os.system("pause")
            return
    if disciplinas[codigo]["vagas"] <= 0:
        print("Não há vagas disponíveis.")
        os.system("pause")
        return
    disciplinas[codigo]["vagas"] -= 1
    matriculas.append({"matricula": matricula, "codigo": codigo})
    print("Inscrição realizada com sucesso!")
    os.system("pause")


def listar_inscricoes() -> None:
    """Lista todas as inscrições mostrando nome do aluno, matrícula e disciplina.

    Returns:
        None
    """
    os.system("cls")
    print("=== Lista de Inscrições ===")
    if len(matriculas) == 0:
        print("Nenhuma inscrição realizada.")
    else:
        for m in matriculas:
            aluno = alunos[m["matricula"]]["nome"]
            disciplina = disciplinas[m["codigo"]]["nome"]
            print(f"{aluno} ({m['matricula']}) -> {m['codigo']} - {disciplina}")
    os.system("pause")


def menu_matriculas() -> None:
    """Loop do submenu de matrículas.

    Possibilita realizar inscrições e listar inscrições até o usuário voltar.

    Returns:
        None
    """
    while True:
        os.system("cls")
        print("=== Gestão de Matrículas ===")
        print("[1] Realizar Inscrição")
        print("[2] Listar Inscrições")
        print("[3] Voltar")
        opc = input("Escolha: ")
        if opc == "1":
            realizar_inscricao()
        elif opc == "2":
            listar_inscricoes()
        elif opc == "3":
            break
        else:
            print("Opção inválida!")
            os.system("pause")


# --------------------------
# Relatórios
# --------------------------
def relatorio_alunos_por_disciplina() -> None:
    """Gera relatório com matrícula e nome de alunos inscritos em uma disciplina.

    Solicita o código da disciplina e lista os alunos inscritos; caso não haja
    inscrições, informa que não há alunos.

    Returns:
        None
    """
    os.system("cls")
    print("=== Relatório: Alunos por Disciplina ===")
    codigo = input("Código da disciplina: ").strip().upper()
    if codigo not in disciplinas:
        print("Disciplina não encontrada.")
        os.system("pause")
        return
    print(f"Alunos inscritos em {codigo} - {disciplinas[codigo]['nome']}:")
    encontrou = False
    for m in matriculas:
        if m["codigo"] == codigo:
            print(f"{m['matricula']} - {alunos[m['matricula']]['nome']}")
            encontrou = True
    if not encontrou:
        print("Nenhum aluno inscrito.")
    os.system("pause")


def relatorio_disciplinas_por_aluno() -> None:
    """Gera relatório com as disciplinas em que um aluno está inscrito.

    Solicita matrícula e lista códigos e nomes das disciplinas em que o aluno
    está matriculado. Se o aluno não possuir inscrições, informa isso.

    Returns:
        None
    """
    os.system("cls")
    print("=== Relatório: Disciplinas por Aluno ===")
    matricula = input("Matrícula do aluno: ").strip()
    if matricula not in alunos:
        print("Aluno não encontrado.")
        os.system("pause")
        return
    print(f"Disciplinas do aluno {alunos[matricula]['nome']}:")
    encontrou = False
    for m in matriculas:
        if m["matricula"] == matricula:
            print(f"{m['codigo']} - {disciplinas[m['codigo']]['nome']}")
            encontrou = True
    if not encontrou:
        print("Nenhuma disciplina encontrada.")
    os.system("pause")


def relatorio_disciplinas_sem_vagas() -> None:
    """Lista as disciplinas com vagas esgotadas (vagas == 0).

    Returns:
        None
    """
    os.system("cls")
    print("=== Relatório: Disciplinas com Vagas Esgotadas ===")
    encontrou = False
    for cod, info in disciplinas.items():
        if info["vagas"] == 0:
            print(f"{cod} - {info['nome']}")
            encontrou = True
    if not encontrou:
        print("Nenhuma disciplina esgotada.")
    os.system("pause")


def menu_relatorios() -> None:
    """Loop do submenu de relatórios.

    Oferece três relatórios conforme o enunciado até o usuário voltar.

    Returns:
        None
    """
    while True:
        os.system("cls")
        print("=== Relatórios ===")
        print("[1] Alunos por Disciplina")
        print("[2] Disciplinas por Aluno")
        print("[3] Disciplinas com Vagas Esgotadas")
        print("[4] Voltar")
        opc = input("Escolha: ")
        if opc == "1":
            relatorio_alunos_por_disciplina()
        elif opc == "2":
            relatorio_disciplinas_por_aluno()
        elif opc == "3":
            relatorio_disciplinas_sem_vagas()
        elif opc == "4":
            break
        else:
            print("Opção inválida!")
            os.system("pause")


# --------------------------
# Menu principal
# --------------------------
def menu_principal() -> None:
    """Loop principal do sistema com o menu e roteamento para submenus.

    Exibe o menu principal até o usuário escolher encerrar o programa.

    Returns:
        None
    """
    while True:
        os.system("cls")
        print("====== Sistema de Gestão Acadêmica - Universidade Python ======")
        print("[1] Gestão de Alunos")
        print("[2] Gestão de Disciplinas")
        print("[3] Gestão de Matrículas")
        print("[4] Relatórios")
        print("[5] Sair")
        print("===============================================================")
        opc = input("Escolha: ")
        if opc == "1":
            menu_alunos()
        elif opc == "2":
            menu_disciplinas()
        elif opc == "3":
            menu_matriculas()
        elif opc == "4":
            menu_relatorios()
        elif opc == "5":
            os.system("cls")
            print("Encerrando o programa...")
            break
        else:
            print("Opção inválida!")
            os.system("pause")


# --------------------------
# Execução
# --------------------------
if __name__ == "__main__":
    menu_principal()
