#include <iostream>
#include <time.h>
#include "FilaEstaticaGenerica.h"

using namespace std;

int main()
{
    FilaEstaticaGenerica<int, 100> fila[3];
    int i, j, numero, processosExecutados[3];
    bool particao[3];

    srand(time(NULL));

    for (i = 0; i < 3; i++)
    {
        cria(fila[i]);
        particao[i] = false;
        processosExecutados[i] = 0;
    }

    for (i = 1; i <= 100; i++)
    {
        numero = rand() % 101;

        if (numero <= 25)
            insere(fila[0], 1);
        else if (numero <= 39)
            insere(fila[1], 1);
        else if (numero <= 49)
            insere(fila[2], 1);
        else if (numero <= 75)
        {
            particao[0] = false;
            if (!ehVazia(fila[0]))
            {
                retira(fila[0]);
                particao[0] = true;
                processosExecutados[0]++;
            }
        }
        else if (numero <= 89)
        {
            particao[1] = false;
            if (!ehVazia(fila[1]))
            {
                retira(fila[1]);
                particao[1] = true;
                processosExecutados[1]++;
            }
        }
        else
        {
            particao[2] = false;
            if (!ehVazia(fila[2]))
            {
                retira(fila[2]);
                particao[2] = true;
                processosExecutados[2]++;
            }
        }

        if (i % 5 == 0)
        {
            for (j = 0; j < 3; j++)

                cout << "fila " << j + 1 << " = " << numeroDeElementos(fila[j]) << endl;

            for (j = 0; j < 3; j++)
            {
                cout << "particao ";
                switch (j)
                {
                case 0:
                    cout << "A ";
                    break;
                case 1:
                    cout << "B ";
                    break;
                case 2:
                    cout << "C ";
                    break;
                }
                particao[j] == false ? cout << "livre" : cout << "ocupada";
                cout << endl;
            }

            for (j = 0; j < 3; j++)
            {
                cout << "processos executados pela particao ";
                switch (j)
                {
                case 0:
                    cout << "A = ";
                    break;
                case 1:
                    cout << "B = ";
                    break;
                case 2:
                    cout << "C = ";
                    break;
                }
                cout << processosExecutados[j] << endl;
            }

            cout << endl;
        }
    }

    return 0;
}
