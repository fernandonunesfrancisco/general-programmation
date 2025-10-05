#include <iostream>
using namespace std;
#define tamanhomax 10

int main() {
    int X[tamanhomax];
    int n;

    do {
        cout << "Quantos numeros deseja inserir? (1 a 10): ";
        cin >> n;
    } while (n < 1 || n > tamanhomax);

    cout << "Digite " << n << " numeros inteiros:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> X[i];
    }

    for (int i = 0; i < n / 2; i++) {
        int temp = X[i];
        X[i] = X[n - 1 - i];
        X[n - 1 - i] = temp;
    }

    cout << "Vetor invertido:" << endl;
    for (int i = 0; i < n; i++) {
        cout << X[i] << " ";
    }
    cout << endl;

    return 0;
}
