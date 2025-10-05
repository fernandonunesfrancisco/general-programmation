#include <iostream>
using namespace std;
#define TMAX 10

int main()
{
    bool encontrado;
	int vetor[TMAX], n, numero;
	do{
		cout<<"Qual sera o numero n de elementos do vetor?"<<endl;
		cin>>n;
	} while(n<1 or n>10);

	for(int i=0; i<n; i++){
		cout << "Insira o elemento "<<i+1<<":"<<endl;
		cin>>vetor[i];
	}

	cout<<"Digite um numero para pesquisar no vetor (ou -1 para sair):"<<endl;
	cin>>numero;

	while(numero!=-1){
		encontrado=false;
		cout<<"Numero "<<numero<<" encontrado nas posicoes: ";
		for(int i = 0; i < n; i++){
			if(vetor[i] == numero){
				cout<<"["<< i<<"] ";
				encontrado=true;
			}
		}
		if(!encontrado)
			cout<<"Nenhuma";
		cout<<endl<<"Digite outro numero para pesquisar (ou -1 para sair):"<<endl;
		cin>>numero;
	}

	cout<<"Programa encerrado."<<endl;
	return 0;
}
