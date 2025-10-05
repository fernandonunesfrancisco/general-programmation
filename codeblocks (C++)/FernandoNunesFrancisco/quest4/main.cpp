#include <iostream>
using namespace std;
#define nmax 15

int main() {
    int V[nmax];
    int n;

    do {
        cout << "Quantos numeros tera o vetor V? (max " << nmax << "): ";
        cin >> n;
    } while (n < 1 || n > nmax);

    cout << "Informe " << n << " valores inteiros para V:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> V[i];
    }

    int menor = V[0];
    int maior = V[0];

    for (int i = 1; i < n; i++) {
        if (V[i] < menor) {
            menor = V[i];
        }
        if (V[i] > maior) {
            maior = V[i];
        }
    }

    cout << "Menor elemento: " << menor << endl;
    cout << "Maior elemento: " << maior << endl;

    return 0;
}
