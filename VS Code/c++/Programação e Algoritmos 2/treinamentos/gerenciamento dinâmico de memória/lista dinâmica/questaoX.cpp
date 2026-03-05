#include<iostream>
using namespace std;

typedef struct Nodo{
    int valor;
    struct Nodo *proximo;
} Tipolista;


void inserenofinal(Tipolista* &, int);
void excluiTodoElemento(Tipolista * &, int);


int main () {
    Tipolista *umalista = NULL;
    int valor;
    do {
    cout <<"Valor (qualquer negativo para sair) = ";
    cin >> valor;
    if(valor > -1)
    inserenofinal(umalista, valor); // OU inserenofinal(...);
    } while(valor > -1);

    return 0;
}

void inserenofinal(Tipolista* &ptr_lista, int valor) {
    Tipolista *p, *pant;
    p = new Tipolista; // aloca memoria p/ novo nodo
    if(p==NULL) {
    cout << "Sem memoria";
    cin.get();
    return; 
    }
    p->valor = valor;
    p->proximo = NULL;
    if(ptr_lista==NULL) { // se lista vazia, atualiza a lista e retorna
    ptr_lista = p;
    return;
    }
// lista nao vazia, segue adiante procurando o final dela
    pant = ptr_lista;
    while(pant->proximo != NULL) {
    pant = pant->proximo;
    }
    pant->proximo = p; // inclui novo nodo em ultimo
}


void excluiTodoElemento(Tipolista * &ptr_lista, int elemento) {
    Tipolista *p, *pant = NULL;
    p = ptr_lista;
    if(p->valor == elemento) {
    ptr_lista = p->proximo; // exclusao do 1o nodo
    delete p; // libera memoria do nodo excluido
    }
// se nao achou elemento no 1o nodo, varrer a lista
    pant = ptr_lista;
    p = p->proximo;
    while(p != NULL) {
    pant = p;
    p=p->proximo;
    if(p->valor == elemento) { // achou elemento pra excluir
    pant->proximo = p->proximo; //conecta nodos anterior e posterior
    delete p; // libera memoria do nodo excluido
            }
        }
} // fim do se lista nao vazia

//////////
/*
Tipolista* retornaEnderecoElemento(Tipolista* ptr_lista, string elemento){
    while(ptr_lista!=NULL){
        if(ptr_lista->corda==elemento){
            return ptr_lista; p=p->proximo;
        }
    }
    return NULL;
}
*/