#include<iostream>
using namespace std;

typedef struct Nodo{
    int valor;
    struct Nodo *proximo;
}Tipolista;






void insereDps80(Tipolista* &ptr_lista, int novoInt){
    Tipolista *p=new Tipolista, *pAUX=NULL;
    if(p==NULL) {
    cout << "Sem memoria";
    cin.get();
    return;
    }
    
    p->proximo=NULL;
    p->valor=novoInt;
    if(ptr_lista->valor==80){
        pAUX=ptr_lista; ptr_lista->proximo=p; p->proximo=pAUX->proximo; return;
    }
}