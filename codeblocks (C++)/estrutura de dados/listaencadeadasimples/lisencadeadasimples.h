#ifndef LISENCADEADASIMPLES_H_INCLUDED
#define LISENCADEADASIMPLES_H_INCLUDED

#include <iostream>

using namespace std;

template <typename T>
struct Nodo {
    T elemento;
    Nodo<T>* proximo;
};

template <typename T>
struct ListaSimplesEncadeada
{
    int cardinalidade;
    Nodo<T>* inicio;
};

template <typename T>
void cria(ListaSimplesmenteEncadeada<T> &lista)
{
    lista.cardinalidade = 0;
    lista.inicio = NULL;
}

template <typename T>
void destroiLista(ListaSimplesEncadeada<T> &lista)
{
    Nodo<T> *p;
    while(lista.inicio!=NULL){
        p=lista.inicio;
        lista.inicio=lista.inicio->proximo;
        delete p;
    }
    lista.cardinalidade = 0;
}

template <typename T>
bool ehVazia(ListaSimplesEncadeada<T> lista){
    return(lista.inicio==NULL);
}

template <typename T>
void insereNoFinal(ListaSimplesEncadeada<T> &lista, T valor)
{
    Nodo<T>* novo = new Nodo<T>;
    novo->elemento = valor;
    novo->proximo=NULL;

    if(lista.inicio==NULL)
        lista.inicio=novo;
    else{
        Nodo<T>*aux = lista.inicio;
        while(aux->proximo!=NULL)
            aux=aux->proximo;
        aux->proximo=novo;
        }
    lista.cardinalidade++;
}

template <typename T>
void insereNaPosicao(ListaSimplesEncadeada<T> &lista, T valor, int posicao)
{
    if(posicao>=lista.cardinalidade)
}



#endif // LISENCADEADASIMPLES_H_INCLUDED
