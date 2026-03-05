#include<iostream>
using namespace std;
#include<cmath>
void geradorCondicao(int, string);
void imprimeResultado(int);
int main(){
    string vetorCondicao[];
    int n;
    geradorCondicao(n, vetorCondicao);
    imprimeResultado(n);
    return 0;
}
void imprimeResultado(int tamanhoMat){
    cout<<"Numeros que atendem a condicao: "<<endl;
    for(int i=0; i<tamanhoMat; i++){
        cout<<"["<<i+1<<"]:"<<i<<endl;
    }
}
void geradorCondicao(int tamanhoMat, string numerosEmCondicao[]){
    for(int c=1000; c<9999;c++){
        string n=c;
        int i;
        if(pow((n[0]-'0')*10+(n[1]-'0')+(n[3]-'0'), 2)==n){
            numerosEmCondicao[i]=n;
            i++;
            tamanhoMat=i+1;
        }
    }
}