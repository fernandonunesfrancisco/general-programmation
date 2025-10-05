#include <iostream>
using namespace std;

#define nmax 15

int main() {
    float v[nmax], w[nmax], soma[nmax], difer[nmax], multi[nmax], divis[nmax];
    float prodescal = 0;
    int n;

    do {
        cout << "Quantos numeros terao os vetores V e W? ";
        cin >> n;
    } while (n < 1 || n > nmax);
    cout << "Informe " << n << " valores para V:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << "Informe " << n << " valores para W:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    for (int i = 0; i < n; i++) {
        soma[i] = v[i] + w[i];
        difer[i] = v[i] - w[i];
        multi[i] = v[i] * w[i];
        if (w[i] != 0) {
            divis[i] = v[i] / w[i];
        } else {
            divis[i] = 0;
        }
        prodescal += v[i] * w[i];
    }
    cout << "\nSoma de V e W: ";
    for (int i = 0; i < n; i++) {
        cout << soma[i] << " ";
    }
    cout << "\nSubtracao de V e W: ";
    for (int i = 0; i < n; i++) {
        cout << difer[i] << " ";
    }
    cout << "\nMultiplicacao de V e W: ";
    for (int i = 0; i < n; i++) {
        cout << multi[i] << " ";
    }
    cout << "\nDivisao de V e W: ";
    for (int i = 0; i < n; i++) {
        cout << divis[i] << " ";
    }
    cout << "\nProduto escalar de V e W: " << prodescal << endl;
    if (prodescal == 0) {
        cout << "Vetores ORTOGONAIS." << endl;
    }

    return 0;
}
