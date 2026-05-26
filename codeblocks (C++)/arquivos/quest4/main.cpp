#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string nomeEntrada;
    cout << "Nome do arquivo .cpp para ler: ";
    getline(cin, nomeEntrada);

    ifstream fin(nomeEntrada);
    if (!fin) {
        cout << "Erro ao abrir arquivo de entrada.\n";
        return 1;
    }

    // Gerar nome do arquivo de saída com extensão .xxx
    string nomeSaida = nomeEntrada;
    int pos = nomeSaida.rfind('.');
    if (pos == -1)
        nomeSaida += ".xxx";
    else
        nomeSaida = nomeSaida.substr(0, pos) + ".xxx";

    ofstream fout(nomeSaida);
    if (!fout) {
        cout << "Erro ao criar arquivo de saída.\n";
        return 1;
    }

    char c, prox;
    bool dentroComentarioLinha = false;
    bool dentroComentarioBloco = false;

    while (fin.get(c)) {

        if (dentroComentarioLinha) {
            // fim do comentário de linha?
            if (c == '\n') {
                dentroComentarioLinha = false;
                fout.put('\n');
            }
            continue; // ignora caracteres do comentário
        }

        if (dentroComentarioBloco) {
            // fim do comentário de bloco?
            if (c == '*') {
                if (fin.peek() == '/') {
                    fin.get(); // consome '/'
                    dentroComentarioBloco = false;
                }
            }
            if (c == '\n')
                fout.put('\n'); // mantém quebras de linha
            continue;
        }

        // Estamos fora de comentário: verificar se começou um
        if (c == '/') {
            prox = fin.peek();

            if (prox == '/') {
                fin.get(); // consome o segundo '/'
                dentroComentarioLinha = true;
                continue;
            }
            if (prox == '*') {
                fin.get(); // consome '*'
                dentroComentarioBloco = true;
                continue;
            }

            // não é comentário → imprime /
            fout.put(c);
        }
        else {
            fout.put(c);
        }
    }

    fin.close();
    fout.close();

    cout << "Arquivo gerado: " << nomeSaida << endl;
    return 0;
}
