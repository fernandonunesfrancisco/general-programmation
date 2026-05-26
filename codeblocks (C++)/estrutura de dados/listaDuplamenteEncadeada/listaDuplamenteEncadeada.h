#ifndef LISTADUPLAMENTEENCADEADA_H_INCLUDED
#define LISTADUPLAMENTEENCADEADA_H_INCLUDED

template<typename T>
struct Nodo
{
    T elemento;
    Nodo *proximo;
    Nodo *anterior;
};

template<typename T>
struct ListaDuplamenteEncadeada
{
    int cardinalidade;
    Nodo<T> *inicio;
    Nodo<T> *fim;
};

template<typename T>
void criarLista(ListaDuplamenteEncadeada<T> &lista)
{
    lista.cardinalidade=0;
    lista.inicio=NULL;
    lista.fim=NULL;
}

template<typename T>
void destruirLista(ListaDuplamenteEncadeada<T> &lista)
{
    Nodo<T> *p;
    while(lista.inicio!=NULL)
    {
        p=lista.inicio;
        lista.inicio=lista.inicio->proximo;
        delete p;
    }
    lista.cardinalidade=0;
    lista.inicio=NULL;
    lista.fim=NULL;
}

template<typename T>
bool ehVazia(ListaDuplamenteEncadeada<T> lista)
{
    return lista.cardinalidade==0;
}

template<typename T>
int numeroElementos(ListaDuplamenteEncadeada<T> lista)
{
    return lista.cardinalidade;
}

template<typename T>
bool existeElemento(ListaDuplamenteEncadeada<T> lista, int elemento)
{
    Nodo<T> *p = lista.inicio;
    while(p!=NULL)
    {
        if(p->elemento==elemento)
            return true;
        p=p->proximo;
    }
    return false;
}

template<typename T>
bool existePosicao(ListaDuplamenteEncadeada<T> lista, int posicao)
{
    if(posicao>0 || posicao<=lista.cardinalidade) return true;
    return false;
    // mais "otimizado": return ((posicao>=1) && (posicao<=lista.cardinalidade));
}

template<typename T>
T getElemento(ListaDuplamenteEncadeada<lista> lista, int posicao)
{
    if(posicao<1 || posicao>lista.cardinalidade)
        throw "Posicao invalida!";
    Nodo<T> *p=lista.inicio;
    int contador=1;
    while(contador<posicao)
    {
        contador++;
        p=p->proximo;
    }
    return p->elemento;
}
template<typename T>
int posicao(ListaSimplesmenteEncadeada<T> lista, T elemento)
{
    if(!existeElemento(lista, elemento)) throw "Elemento nao esta na lista!";
    int contador=1;
    Nodo<T> *p=lista.inicio;
    while(p->elemento!=elemento)
    {
        contador++;
        p=p->proximo;
    }
    return contador;
}

template<typename T>
void insere(ListaDuplamenteEncadeada<T> &lista, T elemento, int posicao)
{
    if(posicao<1 || posicao>lista.cardinalidade+1) throw "Posicao invalida!";
    Nodo<T> *novoNodo = new Nodo<T>();
    novoNodo->elemento=elemento;

    if(lista.inicio==NULL){
        novoNodo->anterior=NULL;
        novoNodo->proximo=NULL;

        lista.inicio=novoNodo;
        lista.fim=novoNodo;
    }else if(posicao==1){
        Nodo<T> *pAUX=lista.inicio;

        pAUX->anterior=novoNodo;
        novoNodo->proximo=pAUX;
        nodoNodo->anterior=NULL;
        lista.inicio=novoNodo;
    }else if(posicao==lista.cardinalidade+1){
        Nodo<T> *pAUX=lista.fim;

        pAUX->proximo=novoNodo;
        novoNodo->anterior=pAUX;
        novoNodo->proximo=NULL;
        lista.fim=novoNodo;
    }else{
        Nodo<T> *pAUX=lista.inicio;
        int cont=1;
        while(cont<posicao){
            pAUX=pAUX->proximo;
            cont++;
        }
        novoNodo->proximo=pAUX;
        novoNodo->anterior=pAUX->anterior;

        pAUX->anterior->proximo= novoNodo;
        pAUX anterior = novoNodo;
    }
    lista.cardinalidade++;
}



#endif // LISTADUPLAMENTEENCADEADA_H_INCLUDED
