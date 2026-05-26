#include<iostream>
#include<iomanip>
using namespace std;
#define qmax 20

int main ()
{
    string nome[qmax], busca;
    int quantEstoque[qmax], quantAux, cont=0, resp, inteiro;
    float precoUnit[qmax], valorTotal, teste;
    bool achou, precoValido;

    do {
        do {
            cout<<"\nMenu de opcoes:"<<endl;
            cout<<"1 - Cadastrar produto"<<endl;
            cout<<"2 - Listar produtos"<<endl;
            cout<<"3 - Entrada no estoque"<<endl;
            cout<<"4 - Saida do estoque"<<endl;
            cout<<"5 - Buscar produto por nome"<<endl;
            cout<<"6 - Valor total em estoque"<<endl;
            cout<<"8 - Sair"<<endl;
            cin>>resp;
            cin.ignore();
        } while (resp<1 or (resp>6 and resp!=8));

        if (resp == 1) {
            if (cont>=qmax)
                cout<<"Limite de produtos atingido."<<endl;
            else {
                do {
                    cout<<"Nome do produto: ";
                    getline(cin, nome[cont]);
                    achou=false;
                    for (int i=0; i<cont; i++) {
                        if (nome[cont] == nome[i]) {
                            achou=true;
                            cout<<"Produto com esse nome ja cadastrado. Tente outro nome."<<endl;
                        }
                    }
                } while (achou);

                do {
                    cout<<"Quantidade em estoque: ";
                    cin>>quantEstoque[cont];
                    cin.ignore();
                } while(quantEstoque[cont] < 0);

                precoValido = false;
                do {
                    cout<<"Preco Unitario (utilize ponto em vez de virgula): ";
                    cin>>precoUnit[cont];
                    cin.ignore();

                    teste = precoUnit[cont] * 100;
                    inteiro = teste;
                    if (teste - inteiro == 0) {
                        precoValido = true;
                    } else {
                        cout<<"Preco invalido. Utilize no maximo 2 casas decimais."<<endl;
                    }
                } while (precoValido == false);

                cont++;
            }
        }

        if (resp == 2) {
            if (cont != 0) {
                cout<<"Lista de produtos:"<<endl;
                for(int i=0; i<cont; i++) {
                    cout<<"Nome: "<<nome[i]<<endl;
                    cout<<"Quantidade em estoque: "<<quantEstoque[i]<<endl;
                    cout<<"Preco unitario: R$"<<fixed<<setprecision(2)<<precoUnit[i]<<endl;
                }
            } else {
                cout<<"Nenhum produto listado."<<endl;
            }
        }

        if (resp == 3) {
            if (cont == 0) {
                cout<<"Nenhum produto registrado."<<endl;
            } else {
                cout<<"Qual produto? ";
                getline(cin, busca);
                achou=false;
                for(int i=0; i<cont; i++) {
                    if (busca == nome[i]) {
                        do {
                            cout<<"Quantos produtos serao adicionados ao estoque? ";
                            cin>>quantAux;
                            cin.ignore();
                        } while (quantAux <= 0);
                        quantEstoque[i] = quantEstoque[i] + quantAux;
                        achou = true;
                        cout<<"Entrada realizada com sucesso."<<endl;
                    }
                }
                if (achou == false) {
                    cout<<"Nenhum produto foi encontrado com esse nome."<<endl;
                }
            }
        }

        if (resp == 4) {
            if (cont == 0) {
                cout<<"Nenhum produto registrado."<<endl;
            } else {
                cout<<"Qual produto? ";
                getline(cin, busca);
                achou = false;
                for(int i=0; i<cont; i++) {
                    if (busca == nome[i]) {
                        do {
                            cout<<"Quantos produtos serao retirados do estoque? ";
                            cin>>quantAux;
                            cin.ignore();
                        } while(quantAux<=0);
                        if (quantAux > quantEstoque[i]) {
                            cout<<"Quantidade insuficiente."<<endl;
                        } else {
                            quantEstoque[i] = quantEstoque[i] - quantAux;
                            achou = true;
                            cout<<"Saida realizada com sucesso."<<endl;
                        }
                    }
                }
                if (achou == false) {
                    cout<<"Nenhum produto foi encontrado com esse nome."<<endl;
                }
            }
        }

        if (resp == 5) {
            if (cont == 0) {
                cout<<"Nenhum produto registrado."<<endl;
            } else {
                cout<<"Qual produto queres pesquisar? ";
                getline(cin, busca);
                achou = false;
                for(int i=0; i<cont; i++) {
                    if (busca == nome[i]) {
                        achou = true;
                        cout<<"Nome: "<<nome[i]<<endl;
                        cout<<"Preco: R$"<<fixed<<setprecision(2)<<precoUnit[i]<<endl;
                        cout<<"Quantidade em estoque: "<<quantEstoque[i]<<endl;
                    }
                }
                if (achou == false) {
                    cout<<"Produto nao cadastrado."<<endl;
                }
            }
        }

        if (resp == 6) {
            valorTotal=0;
            for(int i=0; i<cont; i++) {
                valorTotal = valorTotal+quantEstoque[i]*precoUnit[i];
            }
            cout<<"O valor total do estoque e de R$"<<fixed<<setprecision(2)<<valorTotal<<endl;
        }

    } while (resp != 8);

    return 0;
}
