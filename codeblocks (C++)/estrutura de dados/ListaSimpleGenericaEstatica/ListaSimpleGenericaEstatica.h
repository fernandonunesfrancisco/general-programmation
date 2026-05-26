#ifndef LISTASIMPLEGENERICAESTATICA_H_INCLUDED
#define LISTASIMPLEGENERICAESTATICA_H_INCLUDED

template<typename T, int MAX>
struct ListaEstaticaGenerica
{
    int cardinalidade;
    T elementos[MAX];
};

template<typename T, int MAX>
void cria(ListaEstaticaGenerica<T,MAX> &lista) lista.cardinalidade=0;

template<typename T, int MAX>
bool ehVazia(ListaEstaticaGenerica<T,MAX> lista)
{
    return lista.cardinalidade==0;
}
template<typename T, int MAX>
bool temEspaco(ListaEstaticaGenerica<T,MAX> lista)
{
    return lista.cardinalidade<MAX;
}

template<typename T, int MAX>
int numeroDeElementos(ListaEstaticaGenerica<T,MAX> lista)
{
    return lista.cardinalidade;
}

template<typename T, int MAX>
bool elementoXexistente(T elementoX,ListaEstaticaGenerica<T,MAX> lista)
{
    for(int i=0; i<lista.cardinalidade; i++){
        return lista.elementos[i]==elementoX;
    }
    return false;
}

template<typename T, int MAX>



#endif // LISTASIMPLEGENERICAESTATICA_H_INCLUDED
