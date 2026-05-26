#ifndef EXERCICIOLISTAESTATICAGENERICA_H_INCLUDED
#define EXERCICIOLISTAESTATICAGENERICA_H_INCLUDED

using namespace std;

template<typename T, int MAX>
struct ListaEstaticaGenerica
{
    int cardinalidade;
    T elementos [MAX];
};
template<typename T, int MAX>
void cria(ListaEstaticaGenerica<T, MAX> &lista)
{
lista.cardinalidade = 0;
}

template<typename T, int MAX>
bool ehVazia (ListaEstaticaGenerica<T, MAX> lista)
{
    return lista.cardinalidade == 0;
}

template<typename T, int MAX>
bool temEspaco (ListaEstaticaGenerica<T, MAX> lista)
{
    return lista.cardinalidade < MAX;
}

template<typename T, int MAX>
 int numeroDeElementos (ListaEstaticaGenerica<T, MAX> lista)
{
    return lista.cardinalidade;
}

template<typename T, int MAX>
bool existeElemento (ListaEstaticaGenerica<T, MAX> lista, T elemento)
{
    for (int i = 0; i < lista.cardinalidade; i++)
        if (lista.elementos[i] == elemento)
            return true;
        return false;
}

 template<typename T, int MAX>
bool existePosicao (ListaEstaticaGenerica<T, MAX> lista, int posicao)
{
    return (posicao >= 1) && (posicao <= lista.cardinalidade);
}

template<typename T, int MAX>
 T umElemento (ListaEstaticaGenerica<T, MAX> lista, int posicao)
 {
    if(posicao < 1 || posicao > lista.cardinalidade)
    {
        throw "POSICAO INVALIDA";
    }
    return lista.elementos[posicao - 1];
 }

 template<typename T, int MAX>
 63 int posicao (ListaEstaticaGenerica<T, MAX> lista, T elemento)
 64 {
 65 if (!existeElemento(lista, elemento))
 66 {
 67 throw "ELEMENTO NAO ESTA NA LISTA";
 68 }
 69 for (int i = 0; i < lista.cardinalidade; i++)
 70 if (lista.elementos[i] == elemento)
 71 return i + 1;
 72 }
 73
 74 template<typename T, int MAX>
 75 void insere (ListaEstaticaGenerica<T, MAX> &lista, T elemento, int posicao)
 76 {
 77 if(lista.cardinalidade == MAX)
 78 {
 79 throw "OVERFLOW";
 80 }
 81 if(posicao < 1 || posicao > lista.cardinalidade + 1)
 82 {
 83 throw "POSICAO INVALIDA";
 84 }
 85 for (int i = lista.cardinalidade; i >= posicao; i--)
 86 lista.elementos[i] = lista.elementos[i - 1];
 87 lista.elementos[posicao - 1] = elemento;
 88 lista.cardinalidade++;
 89 }
 90
 91 template<typename T, int MAX>
 92 void retira (ListaEstaticaGenerica<T, MAX> &lista, int posicao)
 93 {
 94 if(lista.cardinalidade == 0)
 95 {
 96 throw "UNDERFLOW";
 97 }
 98 if(posicao < 1 || posicao > lista.cardinalidade)
 99 {
100 throw "POSICAO INVALIDA";
101 }
102 for (int i = posicao; i < lista.cardinalidade; i++)
103 lista.elementos[i - 1] = lista.elementos[i];
104 lista.cardinalidade--;
105 }
106
107 template<typename T, int MAX>
108 void mostra (ListaEstaticaGenerica<T, MAX> lista)
109 {
110 for (int i = 0; i < lista.cardinalidade; i++)
111 cout << lista.elementos[i] << " ";
112 cout << endl;
113 }



#endif // EXERCICIOLISTAESTATICAGENERICA_H_INCLUDED
