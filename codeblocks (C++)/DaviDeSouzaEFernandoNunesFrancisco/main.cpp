#include <iostream>


using namespace std;

int main()
{

    float total_comissao1 = 0, total_comissao2 = 0, total_comissao3 = 0, total_comissao4 = 0;
    float total_vendas1 = 0, total_vendas2 = 0, total_vendas3 = 0, total_vendas4 = 0;
    int total_itens1 = 0, total_itens2 = 0, total_itens3 = 0, total_itens4 = 0;

    float maior_venda = 0;
    int codigo_maior_venda = 0;
    int menor_itens = 999;
    int codigo_menor_itens = 0;

    int total_vendas_processadas = 0;
    float total_comissoes_empresa = 0;

    int opcao;

    do
    {
        cout << "\n==== MENU - SISTEMA DE COMISSOES ====\n";
        cout << "1 - Registrar nova venda\n";
        cout << "2 - Exibir total de vendas processadas\n";
        cout << "3 - Exibir total de comissoes por representante\n";
        cout << "4 - Exibir total de comissoes pagas pela empresa\n";
        cout << "5 - Vendedor com o maior valor de vendas\n";
        cout << "6 - Vendedor com a menor quantidade de itens vendidos\n";
        cout << "7 - Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        while(opcao < 1 || opcao > 7)
        {
            cout << "Opcao invalida! Digite novamente: ";
            cin >> opcao;
        }

        switch(opcao)
        {
        case 1:
        {
            int codigo, itens;
            float valor_venda, comissao;

            cout << "\nDigite o codigo do representante (1 a 4): ";
            cin >> codigo;
            while(codigo < 1 || codigo > 4)
            {
                cout << "Codigo invalido! Digite novamente (1 a 4): ";
                cin >> codigo;
            }

            cout << "Digite o numero de itens vendidos: ";
            cin >> itens;
            while(itens <= 0)
            {
                cout << "Numero invalido! Digite novamente: ";
                cin >> itens;
            }

            cout << "Digite o valor total da venda: R$ ";
            cin >> valor_venda;
            while(valor_venda <= 0)
            {
                cout << "Valor invalido! Digite novamente: R$ ";
                cin >> valor_venda;
            }

            if(itens < 20)
            {
                comissao = valor_venda * 0.10;
            }
            else if(itens < 50)
            {
                comissao = valor_venda * 0.15;
            }
            else if(itens < 75)
            {
                comissao = valor_venda * 0.20;
            }
            else
            {
                comissao = valor_venda * 0.25;
            }


            if(codigo == 1)
            {
                total_comissao1 += comissao;
                total_vendas1 += valor_venda;
                total_itens1 += itens;
            }
            else if(codigo == 2)
            {
                total_comissao2 += comissao;
                total_vendas2 += valor_venda;
                total_itens2 += itens;
            }
            else if(codigo == 3)
            {
                total_comissao3 += comissao;
                total_vendas3 += valor_venda;
                total_itens3 += itens;
            }
            else if(codigo == 4)
            {
                total_comissao4 += comissao;
                total_vendas4 += valor_venda;
                total_itens4 += itens;
            }


            if(valor_venda > maior_venda)
            {
                maior_venda = valor_venda;
                codigo_maior_venda = codigo;
            }

            if(itens < menor_itens)
            {
                menor_itens = itens;
                codigo_menor_itens = codigo;
            }


            total_vendas_processadas++;
            total_comissoes_empresa += comissao;


            cout << "\nComissao desta venda: R$ " << comissao << endl;
            break;
        }

        case 2:
            cout << "\nTotal de vendas processadas: " << total_vendas_processadas << endl;
            break;

        case 3:

            cout << "\nTotal de comissoes por representante:\n";
            cout << "Representante 1: R$ " << total_comissao1 << endl;
            cout << "Representante 2: R$ " << total_comissao2 << endl;
            cout << "Representante 3: R$ " << total_comissao3 << endl;
            cout << "Representante 4: R$ " << total_comissao4 << endl;
            break;

        case 4:

            cout << "\nTotal de comissoes pagas pela empresa: R$ " << total_comissoes_empresa << endl;
            break;

        case 5:
            if(total_vendas_processadas == 0)
            {
                cout << "\nNenhuma venda registrada ainda.\n";
            }
            else
            {

                cout << "\nVendedor com maior valor de vendas:\n";
                cout << "Representante " << codigo_maior_venda << " com R$ " << maior_venda << endl;
            }
            break;

        case 6:
            if(total_vendas_processadas == 0)
            {
                cout << "\nNenhuma venda registrada ainda.\n";
            }
            else
            {
                cout << "\nVendedor com menor quantidade de itens vendidos:\n";
                cout << "Representante " << codigo_menor_itens << " com " << menor_itens << " itens\n";
            }
            break;

        case 7:
            cout << "\nPrograma encerrado.\n";
            break;
        }

    }
    while(opcao != 7);

    return 0;
}
