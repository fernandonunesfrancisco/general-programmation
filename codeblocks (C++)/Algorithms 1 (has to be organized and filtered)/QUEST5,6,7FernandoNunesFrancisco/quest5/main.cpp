#include <iostream>
using namespace std;
#define TMAX 10
int main()
{
	float vetor[TMAX], pos;
	do {
		cout<<"Qual sera o numero n de elementos do vetor?"<<endl;
		cin>>n;
	} while(n<0 or n>10);
	for(int i=0; i<n; i++) {
		cout<<"Insira o elemento "<<i+1<<":"<<endl;
		cin>>vetor[i];
	}
	for(int i=0; i<n; i++) {
		pos=i;
		for(int j=i+1; j<n; j++) {
			if(vetor[j]<vetor[pos]) {
				pos=j;
				swap(vet[i], vet[pos]);
			}
		}
	}
	cout<<"Vetor ordenado:"<<endl;
	for(int i=0; i<n; i++)
		cout<<"["<<i<<"]";
	return 0;
}
