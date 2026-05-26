#include <iostream>
#include <fstream>   // para ifstream
#include <cstdlib>   // para exit
using namespace std;

int main() {
    string nomeArquivo;
    char ch;
    int abreChave = 0, fechaChave = 0;

    cout << "Nome do arquivo fonte C++: ";
    cin >> nomeArquivo;

    ifstream fin(nomeArquivo.c_str());  // abre o arquivo informado

    if (fin.fail()) {
        cout << endl << "Erro: nao foi possivel abrir o arquivo " << nomeArquivo << endl;
        exit(0);   // encerra o programa se o arquivo nao for encontrado
    }

    // Leitura caractere a caractere
    while (fin.get(ch)) {
        if (ch == '{')
            abreChave++;
        else if (ch == '}')
            fechaChave++;
    }

    fin.close();

    cout << endl << "Numero de '{' encontrados: " << abreChave;
    cout << endl << "Numero de '}' encontrados: " << fechaChave << endl;

    if (abreChave == fechaChave)
        cout << endl << "As chaves estao balanceadas." << endl;
    else if (abreChave > fechaChave)
        cout << endl << "Faltam " << (abreChave - fechaChave)
             << " chaves de fechamento '}'." << endl;
    else
        cout << endl << "Faltam " << (fechaChave - abreChave)
             << " chaves de abertura '{'." << endl;

    return 0;
}
