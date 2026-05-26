#include <iostream>
#include<fstream>
#include<iomanip>
#include<cstring>
using namespace std;

typedef struct{
    int code, qtt;
    char name[51];
}Product;

void storeProducts(string fileName){
    Product p; string name; char ans; int i=0;
    ofstream fout(fileName.c_str(), ios::binary);
    if(fout.fail()){
        cout<<"Arquivo "<<fileName<<" nao pode ser aberto."; return;
    }
    do{
        cout<<"Produto "<<++i<<endl;
        p.code = i;
        cout<<"Informe nome ";
        getline(cin, name); strcpy(p.name, name.c_str());
        cout<<"Informe quantidade do produto: "; cin>> p.qtt; cin.ignore();
        fout.write((const char*)(&p), sizeof(Product));
        cout<<"Outro S/N";
        ans = toupper(cin.get()); cin.ignore();
    }while(ans=='S');
    fout.close();
}


void updateProducts(string fileChange, string fileCommand){
    ifstream fin(fileCommand);
    fstream fchange(fileChange, ios::binary | ios::in | ios::out | ios::ate);
    Product p; string stg; char type; int value, code;
    cout<<endl<<"Iniciando atualizacao de produtos"<<endl;
    if(fchange.fail()){
        cout<<"problema com "<<fileChange<<endl; return;
    }
    if(fin.fail()){
        cout<<"problema com "<<fileCommand<<endl; return;
    }
    while(getline(fin,stg)){
        code=stoi(stg.substr(0,1));
        type=toupper(stg.at(2));
        value=stoi(stg.substr(4,2));
        cout<<code<<" "<<type<<" "<<value<<endl;
        fchange.seekg(0,ios::beg);
        while(fin.read((char*)(&p),sizeof(Product))){
            cout<<p.code<<endl;
            if(p.code==code){
                cout<<"atualizando "<<p.code<<endl;
                if(type=='C') p.qtt+=value;
                else p.qtt-=value;
                fchange.seekp(-sizeof(Product),ios::cur);
                fchange.write((const char*)(&p), sizeof(Product));
                break;
            }
        }
    }
    fin.close();
    fchange.close();
}

void showProducts(string fileName){
    ifstream fin(fileName.c_str(), ios::binary);
    Product pp;
    if(fin.fail()){
        cout<<"arquivo nao pode ser aberto"; return;
    }
    fin.seekg(0, ios::end);
    int n= fin.tellg()/sizeof(Product);
    fin.seekg(0,ios::beg);
    cout<<endl<<"Relatorio de produtos"<<endl;
    for(int i=0; i<n; i++){
        fin.read((char*)(&pp),sizeof(Product));
        cout<<pp.code<<" "<<pp.name<<" "<<pp.qtt<<endl;
    }
}

int main()
{

    string fileName;
    cout<<"Nome do arquivo: "<<endl;
    cin>>fileName; cin.ignore();
    storeProducts(fileName);

    updateProducts("produtos.dat","comandos.txt");
    showProducts("produtos.dat");
    return 0;
}
