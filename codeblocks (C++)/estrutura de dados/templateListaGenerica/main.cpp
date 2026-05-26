1 #ifndef LISTAESTATICAGENERICA_H_INCLUDED
2 #define LISTAESTATICAGENERICA_H_INCLUDED
3
4 using namespace std;
5
6 template<typename T, int MAX>
7 struct ListaEstaticaGenerica
8 {
9 int cardinalidade;
10 T elementos [MAX];
11 };
12
13 template<typename T, int MAX>
14 void cria(ListaEstaticaGenerica<T, MAX> &lista)
15 {
16 lista.cardinalidade = 0;
17 }
18
19 template<typename T, int MAX>
20 bool ehVazia (ListaEstaticaGenerica<T, MAX> lista)
21 {
22 return lista.cardinalidade == 0;
23 }
24
25 template<typename T, int MAX>
26 bool temEspaco (ListaEstaticaGenerica<T, MAX> lista)
27 {
28 return lista.cardinalidade < MAX;
29 }
30
31 template<typename T, int MAX>
32 int numeroDeElementos (ListaEstaticaGenerica<T, MAX> lista)
33 {
34 return lista.cardinalidade;
35 }
36
37 // continuar...
38
39 #endif // LISTAES
