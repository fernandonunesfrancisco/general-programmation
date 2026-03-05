#include<iostream>
#define TMAX 40
using namespace std;
void menu(int, string[], float[][TMAX]);
void lerNcidades(int&, string[]);
void lerFormarMatrizDistancias(int, string[], float[][TMAX]);
void relatorio(int, string[], float[][TMAX]);
void apresentacao(int, string[], float[][TMAX]);
bool ehCidadeVizinha(int, int, int, float[][TMAX]);
void calculadoraPercurso(int, string[], float[][TMAX]);


int main(){
    string vetorCidades[TMAX]; float distanciaCidades[TMAX][TMAX]={0};
    int n;
    menu(n,vetorCidades,distanciaCidades);
    return 0;
}
void menu(int n, string vetor[], float matriz[TMAX][TMAX]){
    int resp;
    do{
        cout<<"\n------PRE-CADASTRO INICIAL------"<<endl;
        cout<<"1-Inserir lista de cidades."<<endl;
        cout<<"2-Sair do Programa."<<endl;
        cin>>resp;
    }while(resp!=1 and resp!=2);
    if(resp==1){
        resp=0;
        lerNcidades(n, vetor);
        do{
            cout<<"\nPROTOTIPO DE CALCULADORA GEOGRAFICA."<<endl;
            cout<<"\n------MENU PRINCIPAL------"<<endl;
            cout<<"1-Informar todas as distancias entre duas cidades vizinhas (admite-se apenas uma aplicacao deste comando por executacao do programa)."<<endl;
            cout<<"2-Mostras todos os nomes das cidades e todas as respectivas distancias."<<endl;
            cout<<"3-Mostrar a distancia entre duas cidades."<<endl;
            cout<<"4-Calcular e apresentar distancia total de um percurso."<<endl;
            cout<<"5-Sair do programa."<<endl;
        cin>>resp;
        }while(resp<1 or resp>5);
        switch(resp){
            case 1:
                lerFormarMatrizDistancias(n, vetor, matriz);
                break;            
            case 2:
                relatorio(n, vetor, matriz);
                break;
            case 3:
                apresentacao(n, vetor, matriz);
                break;
            case 4:
                calculadoraPercurso(n, vetor, matriz);
                break;
            case 5:
                cout<<"Programa finalizado."<<endl;
                break;
        }
    }

}
void lerNcidades(int &n, string vetor[]){
    cout<<"Quantas cidades?"<<endl;
    cin>>n;
    cout<<"Digite seus nomes: "<<endl;
    cin.ignore();
    for(int i=0; i<n; i++){
        getline(cin, vetor[i]);
    }
}
void lerFormarMatrizDistancias(int n, string vetor[], float matriz[TMAX][TMAX]){
    string cidade1, cidade2;
    int auxI1, auxI2;
    float distancia;
    char resp;
    cout<<"As distancias serao requesitadas para cidades vizinhas (portanto, uma distancia entre duas cidades implicara que sao vizinhas e se nao for informado a distancia entre duas cidades, sera tratado como se nao fossem vizinhas)"<<endl;
    do{
        cout<<"Informar nova distancia? S(im) ou N(ao)"<<endl;
        cin>>resp;
        if(toupper(resp)=='N') break;

        cout<<"Qual o nome da primeira cidade?"<<endl;
        cin>>cidade1;
        cout<<"E da segunda cidade."<<endl;
        cin>>cidade2;
        cout<<"Qual a distancia entre "<<cidade1<<" e "<<cidade2<<"?"<<endl;
        cin>>distancia;

        bool achou1=false, achou2=false;
        for(unsigned i=0; i<n; i++){
            if(vetor[i]==cidade1){
                auxI1=i;
                achou1=true;
            }
            if(vetor[i]==cidade2){
                auxI2=i;
                achou2=true;
            }
        }

        if(achou1 and achou2){
            matriz[auxI1][auxI2]=distancia;
            matriz[auxI2][auxI1]=distancia;
            cout<<"Distancia registrada/atualizada com sucesso!"<<endl;
        }
        else{
            cout<<"Alguma cidade nao foi encontrada."<<endl;
        }

    }while(toupper(resp)=='S');
}
void relatorio(int n, string vetor[], float matriz[TMAX][TMAX]){
    cout<<"Vetor dos Nomes das Cidades:"<<endl;
    for(unsigned i=0; i<n; i++){
        cout<<"["<<i+1<<"]:"<<vetor[i];
    }
    cout<<"\nMatriz das distancias"<<endl;
    for(unsigned i=0; i<n; i++){
        for(unsigned j=0; j<n; j++){
            if(i==j)
            cout<<"["<<i+1<<"]["<<j+1<<":"<<" ";
            else
            cout<<"["<<i+1<<"]["<<j+1<<":"<<matriz[i][j];
        }
        cout<<endl;
    }
}
void apresentacao(int n, string vetor[], float matriz[TMAX][TMAX]){
    string cidade1, cidade2;
    int auxI1, auxI2, auxJ;
    float distancia;
    char resp;
    do{
        cout<<"Apresentar nova distancia entre duas cidades? S(im) ou N(ao)"<<endl;
        cin>>resp;
        cout<<"Qual o nome da primeira cidade?"<<endl;
        cin>>cidade1;
        cout<<"E da segunda cidade."<<endl;
        cin>>cidade2;
        
        for(unsigned i=0; i<n; i++){
            if(vetor[i]==cidade1)
                auxI1=i;
            else if(vetor[i]==cidade2)
            auxI2=i;
            if(auxI1>=0 and auxI2>=0){
                if(ehCidadeVizinha(n, auxI1, auxI2, matriz)){
                    for(unsigned i=0;i<n;i++){
                        for(unsigned j=0; j<n; j++){
                            if(i==auxI1 and j==auxI2){
                                cout<<"A distancia eh de "<<matriz[i][j]<<"KM."<<endl; break;
                            }
                        }
                    }
                }
                else cout<<"Estas cidades nao sao vizinhas";
            }
        }
    }while(toupper(resp)=='S');
}
bool ehCidadeVizinha(int n, int i, int j, float matriz[TMAX][TMAX]){
    if(matriz[i][j] > 0)
        return true;
    else
        return false;
}
void calculadoraPercurso(int n, string vetor[], float matriz[TMAX][TMAX]){
    int nCidades;
    cout << "Quantas cidades tem o percurso? ";
    cin >> nCidades;

    string cidades[TMAX];
    cout << "Digite os nomes das cidades na ordem do percurso:" << endl;
    for(int i=0; i<nCidades; i++){
        cin >> cidades[i];
    }

    float total = 0;
    bool valido = true;

    for(int i=0; i<nCidades-1; i++){
        int auxI1, auxI2;
        bool achou1 = false, achou2 = false;

        // procurar índices das cidades
        for(int j=0; j<n; j++){
            if(vetor[j] == cidades[i]) {
                auxI1 = j;
                achou1 = true;
            }
            if(vetor[j] == cidades[i+1]) {
                auxI2 = j;
                achou2 = true;
            }
        }

        if(!achou1 || !achou2){
            cout << "Cidade não encontrada no cadastro!" << endl;
            valido = false;
            break;
        }

        if(matriz[auxI1][auxI2] == 0){
            cout << "Percurso inválido: " << cidades[i]
                 << " e " << cidades[i+1]
                 << " não são vizinhas." << endl;
            valido = false;
            break;
        } else {
            total += matriz[auxI1][auxI2];
        }
    }

    if(valido){
        cout << "Distância total do percurso: " << total << " km" << endl;
    }
}