#include<iostream>
using namespace std;
Tipolista* retornaEnderecoElemento(Tipolista*, string);



typedef struct Nodo{
    string corda;
    struct Nodo *proximo;
}Tipolista;

Tipolista* retornaEnderecoElemento(Tipolista* p, string elemento){
    while(p!=NULL){
        if(p->corda==elemento){
            return p; p=p->proximo;
        }
    }
    return NULL;
}