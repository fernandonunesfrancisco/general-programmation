#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

typedef struct {
    char codigo[10], nome[51];
    float preco, vEstoq;
    int quant;
} Produto;

void insereProdutoDireto();
void mostraMaiorQueX(float x);
int contaRegistros();

int main() {

    insereProdutoDireto();           // cadastra produtos diretamente no arquivo
    mostraMaiorQueX(1000.0);         // procura produtos com valor > X

    return 0;
}
void insereProdutoDireto() {
    fstream arq("PRODUTOS.dat", ios::binary | ios::in | ios::out | ios::app);

    if (!arq) {
        // Se arquivo não existir, cria
        arq.open("PRODUTOS.dat", ios::binary | ios::out);
        arq.close();
        arq.open("PRODUTOS.dat", ios::binary | ios::in | ios::out | ios::app);
    }

    char resp;
    do {
        Produto p;

        cout << "Codigo: "; cin >> p.codigo;
        cout << "Nome: "; cin >> p.nome;
        cout << "Preco: "; cin >> p.preco;
        cout << "Quantidade: "; cin >> p.quant;

        p.vEstoq = p.preco * p.quant;

        // Posiciona o ponteiro de escrita no FINAL do arquivo
        arq.seekp(0, ios::end);

        // Escreve o registro diretamente
        arq.write((char*)&p, sizeof(Produto));

        cout << "Mais um? (S/N): ";
        cin >> resp;

    } while (toupper(resp) == 'S');

    arq.close();
}
