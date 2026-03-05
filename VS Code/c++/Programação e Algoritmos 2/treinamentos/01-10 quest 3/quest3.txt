#include<iostream>
using namespace std;
#define TMAX 50

void lerFuncionario(int &, Funcionario[], bool &);
void calcularMediaSalarial(int, float &, Funcionario[]);
void mostrarFuncionarioMaiorQmediaSalarial(int, float, Funcionario[]);

int main(){
    Funcionario funcionarios[TMAX];
    char resp;
    int n=0;
    bool limiteEstourado=false;
    float mediaSalarial=0;
    do{
        lerFuncionario(n, funcionarios, limiteEstourado);
        if(limiteEstourado==true){
            cout<<"Limite atingido ("<<TMAX<<")."<<endl; break;
        }
        cout<<"\nMais um funcionario: "; cin>>resp;
    }while(resp=='s' or resp=='S');
    calcularMediaSalarial(n, mediaSalarial, funcionarios);
    mostrarFuncionarioMaiorQmediaSalarial(n, mediaSalarial, funcionarios);
    return 0;
}

typedef struct{
    int ano, mes, dia;
}DataComposta;

typedef struct{
    int matricula, departamento;
    string nome, cargo;
    float salario;
    DataComposta data;
}Funcionario;


void lerFuncionario(int &n, Funcionario vetor[], bool &limiteEstourado){
    cin.ignore();
    cout<<"Insira as informações do funcionario:"<<endl;
    cout<<"Matricula: "; cin>>vetor[n].matricula; cin.ignore();
    cout<<"\nNome: "; getline(cin, vetor[n].nome);
    cout<<"\nCargo: "; getline(cin, vetor[n].cargo);
    cout<<"\nDepartamento: "; cin>>vetor[n].departamento; cin.ignore();
    cout<<"\nData de admissao (dia/mes/ano):"<<endl;
    cout<<"Dia: "; cin>>vetor[n].data.dia;
    cout<<"\nMes: "; cin>>vetor[n].data.mes;
    cout<<"\nAno: "; cin>>vetor[n].data.ano;
    cout<<"\nSalario: "; cin>>vetor[n].salario;
    n++;
    if(n==TMAX)
        limiteEstourado=true;
}
void calcularMediaSalarial(int n, float &mediaSalarial, Funcionario vetor[]){
    for(unsigned i=0; i<n; i++)
        mediaSalarial+=vetor[i].salario;
    mediaSalarial/=n;
}
void mostrarFuncionarioMaiorQmediaSalarial(int n, float mediaSalarial, Funcionario vetor[]){
    bool funcionarioSalarioMaior=false;
    cout<<"Funcionarios como salario maior que a media:"<<endl;
    for(unsigned i=0; i<n; i++){
        if(vetor[i].salario>mediaSalarial){
        cout<<"Funcionario "<<vetor[i].nome<<":"<<endl;
        cout<<"Cargo: "<<vetor[i].cargo<<endl;
        cout<<"Departamento: "<<vetor[i].departamento<<endl;
        cout<<"Data de Admissao: "<<vetor[i].data.dia<<"/"<<vetor[i].data.mes<<"/"<<vetor[i].data.ano<<endl;
        cout<<"Salario: "<<vetor[i].salario<<endl;
        funcionarioSalarioMaior=true;
        }
    }
    if(funcionarioSalarioMaior==false)
    cout<<"Nenhum funcionario com salario maior que a media, pois todos os salarios sao iguais."<<endl;
}