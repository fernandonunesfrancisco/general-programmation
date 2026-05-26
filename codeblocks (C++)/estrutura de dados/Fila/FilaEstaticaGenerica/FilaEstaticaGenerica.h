#ifndef FILAESTATICAGENERICA_H_INCLUDED
#define FILAESTATICAGENERICA_H_INCLUDED

using namespace std;

template<typename T, int MAX>
struct FilaEstaticaGenerica{
    int cardinalidade;
    int inicio;
    int fim;
    T elementos[MAX];
};

template<typename T, int MAX>
void cria(FilaEstaticaGenerica<T, MAX> &q){
    q.cardinalidade=0;
    q.inicio=MAX-1;
    q.fim=MAX-1;
}

template<typename T, int MAX>
bool ehVazia(FilaEstaticaGenerica<T, MAX> q){
    return q.cardinalidade==0;
}

template<typename T, int MAX>
bool temEspaco(FilaEstaticaGenerica<T, MAX> q){
    return q.cardinalidade<MAX;
}

template<typename T, int MAX>
int numeroDeElementos(FilaEstaticaGenerica<T, MAX> q)
{
    return q.cardinalidade;
}

template<typename T, int MAX>
bool existeElemento(FilaEstaticaGenerica<T, MAX> q, T elemento)
{
    int i=1;
    int posicao=q.inicio;
    while(i<=q.cardinalidade)
    {
        posicao++;
        if(posicao>MAX-1) posicao=0;
        if(q.elementos[posicao]==elemento) return true;
        i++;
    }
    return false;
}

template<typename T, int MAX>
bool existePosicao(FilaEstaticaGenerica<T, MAX> q, int posicao)
{
    return (posicao>=1) && (posicao<q.cardinalidade);
}

template<typename T, int MAX>
T umElemento(FilaEstaticaGenerica<T, MAX> q, int posicao)
{
    if(posicao<1||posicao>q.cardinalidade)
    {
        throw "POSICAO INVALIDA";
    }
    if((q.inicio+posicao)<=MAX-1) return q.elementos[q.inicio+posicao];
    return q.elementos[posicao-MAX+q.inicio];
}

template<typename T, int MAX>
int posicao(FilaEstaticaGenerica<T, MAX> q, T elemento)
{
    if(!existeElemento(q, elemento)) throw "Elemento nao existe na fila";
    int i=1;
    int posicao = q.inicio;
    while(i<=q.cardinalidade)
    {
        posicao++;
        if(posicao>MAX-1) posicao=0;
        if(q.elementos[posicao]==elemento) return i;
        i++;
    }
}

template<typename T, int MAX>
T primeiro (FilaEstaticaGenerica<T, MAX> q)
{
    if(q.inicio<MAX-1) return q.elementos[q.inicio+1];
    return q.elementos[0];
}

template<typename T, int MAX>
T ultimo(FilaEstaticaGenerica<T, MAX> q)
{
    return q.elementos[q.fim];
}

template<typename T, int MAX>
void insere(FilaEstaticaGenerica<T,MAX> &q, T elemento)
{
    if(q.cardinalidade==MAX) throw "UNDERFLOW";
    q.fim++;
    if(q.fim>MAX-1) q.fim=0;
    q.elementos[q.fim]=elemento;
    q.cardinalidade++;
}

template<typename T, int MAX>
void retira (FilaEstaticaGenerica<T, MAX> &q)
{
    if(q.cardinalidade==0) throw "UNDERFLOW";
    q.inicio++;
    if(q.inicio>MAX-1) q.inicio=0;
    q.cardinalidade--;
}

template<typename T, int MAX>
void mostra(FilaEstaticaGenerica<T, MAX> q)
{
    int i=1;
    int posicao=q.inicio;
    while(i<=q.cardinalidade)
    {
        posicao++;
        if(posicao>MAX-1) posicao=0;
        cout<<q.elementos[posicao]<<"   ";
        i++;
    }
    cout<<endl;
}


#endif // FILAESTATICAGENERICA_H_INCLUDED
