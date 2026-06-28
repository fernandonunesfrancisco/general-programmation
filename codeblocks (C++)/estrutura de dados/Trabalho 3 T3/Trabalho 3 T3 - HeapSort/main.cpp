#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

#include "HeapSort.h"

using namespace std;

void fazerTeste(int dados[], int quantidade, int tipo)
{
    int v[10000];

    long long c = 0;
    long long m = 0;

    montarVetor(dados, v, quantidade, tipo);

    heapSort(v, quantidade, c, m);

    cout << "\nTipo inicial: "
         << nomeTipo(tipo);

    cout << "\nQuantidade: "
         << quantidade;

    cout << "\nC(n): "
         << c;

    cout << "\nM(n): "
         << m;

    cout << "\nOrdenado: ";

    if (estaOrdenado(v, quantidade))
    {
        cout << "sim\n";
    }
    else
    {
        cout << "nao\n";
    }
}

void testesAutomaticos(int dados[])
{
    int quantidades[5] ={100, 500, 1000, 5000, 10000};

    cout << "\nTestes automaticos\n";

    cout << left << setw(14)
         << "Tipo"
         << right << setw(10)
         << "Qtd"
         << setw(15)
         << "C(n)"
         << setw(15)
         << "M(n)"
         << endl;

    cout << "------------------------------------------------------\n";

    for (int tipo = 1; tipo <= 3; tipo++)
    {
        for (int i = 0; i < 5; i++)
        {
            int v[10000];

            long long c = 0;
            long long m = 0;

            int quantidade = quantidades[i];

            montarVetor(dados,v,quantidade,tipo);

            heapSort(v,quantidade,c,m);

            cout << left
                 << setw(14)
                 << nomeTipo(tipo);

            cout << right
                 << setw(10)
                 << quantidade
                 << setw(15)
                 << c
                 << setw(15)
                 << m
                 << endl;
        }
    }
}

int main()
{
    int dados[10000];
    int total = 0;

    int opcao;
    int quantidade;
    int tipo;

    string pasta;
    string nomeArquivo;
    string caminho;

    cout << "Trabalho T3 - Heap Sort\n";

    cout << "Digite a pasta do arquivo: ";
    getline(cin, pasta);

    cout << "Digite o nome do arquivo: ";
    getline(cin, nomeArquivo);

    if (pasta.size() == 0)
    {
        caminho = nomeArquivo;
    }
    else if (
        pasta[pasta.size() - 1] == '\\' ||
        pasta[pasta.size() - 1] == '/'
    )
    {
        caminho = pasta + nomeArquivo;
    }
    else
    {
        caminho = pasta + "\\" + nomeArquivo;
    }

    ifstream arquivo(caminho.c_str());

    if (!arquivo)
    {
        cout << "Nao foi possivel abrir o arquivo.\n";
        return 0;
    }

    while (total < 10000 && arquivo >> dados[total])
    {
        total++;
    }

    arquivo.close();

    cout << "\nForam lidos "
         << total
         << " numeros.\n";

    do
    {
        cout << "\nMenu\n";
        cout << "1 - Fazer um teste\n";
        cout << "2 - Fazer testes automaticos\n";
        cout << "0 - Sair\n";
        cout << "Opcao: ";

        cin >> opcao;

        if (opcao == 1)
        {
            cout << "Quantidade de dados: ";
            cin >> quantidade;

            cout << "\nTipo inicial\n";
            cout << "1 - Crescente\n";
            cout << "2 - Decrescente\n";
            cout << "3 - Aleatoria\n";
            cout << "Opcao: ";
            cin >> tipo;

            if (quantidade >= 1 && quantidade <= total && tipo >= 1 && tipo <= 3)
            {
                fazerTeste(dados,quantidade,tipo);
            }
            else
            {
                cout << "Opcao invalida.\n";
            }
        }
        else if (opcao == 2)
        {
            testesAutomaticos(dados);
        }
        else if (opcao != 0)
        {
            cout << "Opcao invalida.\n";
        }

    } while (opcao != 0);

    cout << "\nFim do programa.\n";

    return 0;
}
