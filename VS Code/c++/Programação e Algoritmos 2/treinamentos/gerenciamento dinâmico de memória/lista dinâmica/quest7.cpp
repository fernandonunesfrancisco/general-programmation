#include<iostream>
#define TMAX 50
using namespace std;

typedef struct Nodo{
    char sexo;
    int idade;
    float salario;
    struct Nodo *proximo;
}ListaPessoa;
typedef struct Nodo{
    char sexo;
    int idade;
    float salario;
}TipoPessoa;

void inserenofinal(ListaPessoa* &, char, int, float);



int main(){
    TipoPessoa Pessoas[TMAX];
    ListaPessoa *pPessoas;
    int n, idade;
    char sexo;
    float salario;
    
    cout << "Quantas pessoas deseja inserir? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\n--- Pessoa " << i+1 << " ---\n";
        cout << "Sexo (M/F): ";
        cin >> sexo;
        cout << "Idade: ";
        cin >> idade;
        cout << "Salario: ";
        cin >> salario;

        inserenofinal(pPessoas, sexo, idade, salario);
    }


    mostraLista(pPessoas);

    return 0;
}

void inserenofinal(ListaPessoa* &ptr_lista, char sexo, int idade, float salario) {
    ListaPessoa *p, *pant;
    p = new ListaPessoa; // aloca memoria p/ novo nodo
    if(p==NULL) {
    cout << "Sem memoria";
    cin.get();
    return; 
    }
    p->sexo = sexo;
    p->idade = idade;
    p->salario = salario;
    p->proximo = NULL;
    if(ptr_lista==NULL) { // se lista vazia, atualiza a lista e retorna
    ptr_lista = p;
    return;
    }
}
void mostraLista(ListaPessoa *lista){
        cout << "\nConteudo da lista:\n";
    ListaPessoa* aux = lista;
    while (aux != NULL) {
        cout << aux->sexo << " - " << aux->idade << " anos - R$" << aux->salario << endl;
        aux = aux->proximo;
    }
}