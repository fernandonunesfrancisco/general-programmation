#include <iostream>
#include <fstream>   // para ifstream
#include <string>    // para getline e string
#include <cstdlib>   // para exit()
using namespace std;

int main() {
    string nomeArquivo, linha;
    int contador = 0;
    char tecla;

    cout << "Nome do arquivo texto: ";
    cin >> nomeArquivo;

    ifstream fin(nomeArquivo.c_str());  // abre o arquivo informado

    if (fin.fail()) {
        cout << endl << "Erro: nao foi possivel abrir o arquivo " << nomeArquivo << endl;
        exit(0);   // encerra o programa se o arquivo nao for encontrado
    }

    cout << endl << ">>> CONTEUDO DO ARQUIVO <<<" << endl << endl;

    // leitura linha a linha
    while (getline(fin, linha)) {
        cout << linha << endl;
        contador++;

        // a cada 20 linhas, pausa e aguarda ENTER
        if (contador == 20) {
            cout << endl << "[Pressione <ENTER> para continuar...]" << endl;
            cin.ignore();    // ignora o ENTER pendente no buffer (caso tenha vindo do nome do arquivo)
            cin.get();       // aguarda o ENTER do usuário
            contador = 0;    // zera o contador para o próximo bloco
            cout << endl;
        }
    }

    fin.close();
    cout << endl << ">>> Fim do arquivo <<<" << endl;
    return 0;
}
