#include <iostream>
using namespace std;
#define nmax 100

int main() {
    int inscricao[nmax];
    float altura[nmax];
    int n;

    do {
        cout << "Quantos atletas? (max " << nmax << "): ";
        cin >> n;
    } while (n < 1 || n > nmax);

    cout << "Digite o numero de inscricao e a altura (em cm) de cada atleta:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Atleta " << i + 1 << " - Inscricao: ";
        cin >> inscricao[i];
        cout << "Atleta " << i + 1 << " - Altura: ";
        cin >> altura[i];
    }

    int maior = 0, menor = 0;
    float soma_alturas = altura[0];

    for (int i = 1; i < n; i++) {
        soma_alturas += altura[i];
        if (altura[i] > altura[maior]) {
            maior = i;
        }
        if (altura[i] < altura[menor]) {
            menor = i;
        }
    }

    float media = soma_alturas / n;

    cout << "\nAtleta mais alto:" << endl;
    cout << "Inscricao: " << inscricao[maior] << ", Altura: " << altura[maior] << " cm" << endl;

    cout << "Atleta mais baixo:" << endl;
    cout << "Inscricao: " << inscricao[menor] << ", Altura: " << altura[menor] << " cm" << endl;

    cout << "Altura media do grupo: " << media << " cm" << endl;

    return 0;
}
