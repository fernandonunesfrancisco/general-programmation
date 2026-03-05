#include<iostream>
using namespace std;
#define TMAX 50
void leituraDados(int, Profissao);

int main(){
    Profissao profissoes[TMAX];
    int n;
    cout<<"Quantas profissoes?";
    cin>>n;
    cin.ignore();
    for(unsigned i=0; i<n; i++){
        leituraDados(i, profissoes);
    }
    

    return 0;
}
typedef struct{
    string codigo, nome;
}Profissao;
void leituraDados(int i, Profissao profissao[]){
    cout<<"Insira codigo da profissao: ";
    getline(cin, profissao[i].codigo);
    cout<<"\nInsira nome da profissao";
    getline(cin, profissao[i].nome);
}
void lerCodigoMostrarNome(int n, Profissao profissao){
    string codigo;
    cout<<"Insira o codigo da profissao que sera pesquisada: ";
    getline(cin, codigo);
    acharNomeProfissao(n, codigo);
}
void acharNomeProfissao(int n, string nomeRecebido){
    for(unsigned i=0; i<n; i++){
        if(nomeRecebido==)
    }
}
