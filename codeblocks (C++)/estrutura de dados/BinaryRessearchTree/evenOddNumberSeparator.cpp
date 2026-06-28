#include <iostream>
#include "BinaryRessearchTree.h"
using namespace std;

int main()
{
    BinaryRessearchTree<int> A1;
    BinaryRessearchTree<int> A2;

    create(A1);
    create(A2);

    int value;

    cout << "Digite valores inteiros entre 10 e 80." << endl;
    cout << "Digite um valor fora do intervalo para encerrar." << endl;

    cin >> value;

    while(value >= 10 && value <= 80)
    {
        if(value % 2 == 0)
        {
            insert(A1, value);
        }
        else
        {
            insert(A2, value);
        }

        cin >> value;
    }

    cout << endl;

    cout << "Elementos da arvore A1 (pares):" << endl;
    show(A1);

    cout << endl << endl;

    cout << "Elementos da arvore A2 (impares):" << endl;
    show(A2);
    cout << endl << endl;
    cout<<"Nivel das arvores: "<<height(A1)<<", "<<height(A2)<<endl;

    destroy(A1);
    destroy(A2);
    return 0;
}
