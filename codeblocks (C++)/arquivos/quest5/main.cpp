#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>   // para exit()
using namespace std;

// Estrutura para armazenar dados de cada aluno
struct Aluno {
    string nome;
    string disciplina;
    float nota;
    Aluno *prox;
};

// Função que insere um novo aluno na lista de forma ordenada (por nome)
void insereOrdenado(Aluno* &inicio, Aluno* novo) {
    Aluno *ant = NULL, *p = inicio;

    // procura posição correta (ordem alfabética crescente)
    while (p != NULL && p->nome < novo->nome) {
        ant = p;
        p = p->prox;
    }

    // insere no início da lista
    if (ant == NULL) {
        novo->prox = inicio;
        inicio = novo;
    }
    else { // insere no meio ou no final
        ant->prox = novo;
        novo->prox = p;
    }
}

int main() {
    ifstream fin("alunos1.txt");   // abre arquivo de entrada
    ofstream fout("alunos2.txt");  // cria arquivo de saída

    string nome, disciplina;
    float nota;
    Aluno *inicio = NULL, *novo, *p;

    if (fin.fail()) {
        cout << "Erro ao abrir o arquivo alunos1.txt" << endl;
        exit(0);
    }

    if (fout.fail()) {
        cout << "Erro ao criar o arquivo alunos2.txt" << endl;
        exit(0);
    }

    // leitura única do arquivo de entrada
    while (fin >> nome >> disciplina >> nota) {
        novo = new Aluno;
        novo->nome = nome;
        novo->disciplina = disciplina;
        novo->nota = nota;
        novo->prox = NULL;

        insereOrdenado(inicio, novo);
    }

    fin.close();

    cout << endl << "Relação de alunos ordenada alfabeticamente:" << endl << endl;

    // percorre a lista e grava no arquivo de saída
    p = inicio;
    while (p != NULL) {
        cout << p->nome << "  " << p->disciplina << "  " << p->nota << endl;
        fout << p->nome << " " << p->disciplina << " " << p->nota << endl;
        p = p->prox;
    }

    fout.close();

    cout << endl << "Arquivo alunos2.txt gerado com sucesso!" << endl;

    // libera memória da lista
    while (inicio != NULL) {
        p = inicio;
        inicio = inicio->prox;
        delete p;
    }

    return 0;
}
