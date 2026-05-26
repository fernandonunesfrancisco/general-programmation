#include <iostream>
#include<fstream>
using namespace std;

typedef struct Nodo{
    char codigo[10], nome[51];
    float preco, vEstoq;
    int quant;
    struct Nodo *proximo;
}ListaProdutos;

void insereNoFinal(ListaProdutos* &);
void preencheArquivoBin(ListaProdutos*);
void procuraEmostraValorMaiorQueX(float);
void destroiLista(ListaProdutos* &);

int main()
{
    ListaProdutos *pLista=NULL;
    insereNoFinal(pLista);
    preencheArquivoBin(pLista);
    procuraEmostraValorMaiorQueX(1000.0);
    destroiLista(pLista);


    return 0;
}

void insereNoFinal(ListaProdutos* &ptr_lista){
    char resp;
    do{
        ListaProdutos *p, *pant;
        p= new ListaProdutos;
        if(p==NULL){
            cout<<"Sem memoria."; return;
        }
        cout<<"Codigo: "; cin>>p->codigo;
        cout<<"Nome: "; cin>>p->nome;
        cout<<"Preco: "; cin>>p->preco;
        cout<<"Quantidade em estoque: "; cin>>p->quant;
        p->vEstoq=p->preco*p->quant;
        p->proximo=NULL;

        if(ptr_lista==NULL){
                ptr_lista=p;
        }
        else{
            pant=ptr_lista;
            while(pant->proximo!=NULL){
                pant=pant->proximo;
            }
            pant->proximo=p;
        }
        cout<<"Mais um?"; cin>>resp;
    }while(toupper(resp)=='S');
}

void preencheArquivoBin(ListaProdutos *ptr_lista){
    ofstream fout("PRODUTOS.dat", ios::binary);
    if(!fout){
        cout<<"Erro ao abrir."; return;
    }
    ListaProdutos *p= ptr_lista;
    while(p!=NULL){
        fout.write((char*)p, sizeof(ListaProdutos));
        p=p->proximo;
    }
    fout.close();
}

void procuraEmostraValorMaiorQueX(float x){
    ifstream fin("PRODUTOS.dat", ios::binary);
    if(!fin){
        cout<<"Erro ao abrir arquivo para leitura."; return;
    }
    ListaProdutos aux;
    while(fin.read((char*)&aux, sizeof(ListaProdutos))){
        if(aux.vEstoq>x){
            cout<<"Codigo: "<<aux.codigo<<endl;
            cout<<"Nome: "<<aux.nome<<endl;
            cout<<"Valor em estoque R$ "<<aux.vEstoq<<endl;
        }
    }
    fin.close();
}
void destroiLista(ListaProdutos* &ptr_lista){
    ListaProdutos *p;
    while(ptr_lista != NULL){
        p = ptr_lista;
        ptr_lista = ptr_lista->proximo;
        delete p;
    }
}
