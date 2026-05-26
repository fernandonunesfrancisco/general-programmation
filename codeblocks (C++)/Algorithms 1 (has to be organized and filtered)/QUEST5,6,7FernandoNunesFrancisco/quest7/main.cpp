
#include <iostream>
using namespace std;
#define TMAX 10
int main()
{
	int n, matriz[TMAX][TMAX], produto[TMAX], soma[TMAX], numero, somaDiag=0, somaAcima=0;
	do{
		cout<<"Digite a ordem da matriz (3 a 10):"<<endl;
		cin>>n;
	} while(n<3 or n>10);

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<"Digite o elemento ["<<i<<"]["<<j<<"]:"<<endl;
			cin>>matriz[i][j];
		}
	}
	for(int i=0; i<n; i++){
		produto[i]=1;
		soma[i]=0;
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i==j)
				somaDiag += matriz[i][j];
			if(j>i)
				somaAcima += matriz[i][j];
			produto[i] *= matriz[i][j];
			soma[j] += matriz[i][j];
		}
	}
	cout<<"Soma diagonal principal: "<<somaDiag<<endl;
	cout<<"Soma acima da diagonal principal: "<<somaAcima<<endl;
	cout<<"Produto dos elementos de cada linha:"<<endl;
	for(int i=0; i<n; i++)
		cout<<produto[i]<<endl;
	cout<<"Soma dos elementos de cada coluna:"<<endl;
	for(int i=0; i<n; i++)
		cout<<soma[i]<<endl;
	cout<<"Matriz transposta:"<<endl;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<matriz[j][i]<<" ";
		}
		cout<<endl;
	}

	return 0;
}
