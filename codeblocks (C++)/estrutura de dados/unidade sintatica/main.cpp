#include <iostream>
#include<numbers>
/*
enum comparacao


*/
using namespace std;

struct Circuferencia{
    float raio;
    int X, Y;
};

/*Circuferencia cria(int raio, int X, int Y) errado

{
    Circuferencia c;
    c.raio=raio;
    c.X=X;
    c.Y=Y;
    return c;
}
*/
void cria(float raio, int x, int y, Circunferencia &c){
    Circuferencia c;
    c.raio=raio;
    c.X=X;
    c.Y=Y;
}

void alteraRaio(Circuferencia& c, float novoRaio){
    c.raio=novoRaio;
}

void alteraX(Circuferencia& c, float novoX){
    c.X=novoX;
}

void alteraY(Circuferencia& c, float novoY){
    c.Y=novoY;
}


float recuperaRaio(Circuferencia c){
    return c.raio;
}
int recuperaX(Circuferencia c){
    return c.X;
}
int recuperaY(Circuferencia c){
    return c.Y;
}

float calculaDiametro(Circuferencia c){
return 2*raio;
}
float calculaPerimetro(Circuferencia c){
    return 2*numbers::pi*raio;
}



int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
