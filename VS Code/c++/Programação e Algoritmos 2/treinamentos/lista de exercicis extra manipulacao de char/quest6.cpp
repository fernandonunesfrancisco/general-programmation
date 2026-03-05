#include<iostream>
#include<cstring>
using namespace std;
int main (){
string fraseNormal, fraseCodificada, alfabeto="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

cout<<"Frase pra ser codificada em codigo de Cezar:"<<endl;
getline(cin, fraseNormal);



for(unsigned i=0; i<fraseNormal.size; i++){
    for(unsigned j=0; i<27; j++){
        if(fraseNormal[i]==alfabeto[j]){
            fraseCodificada[i]=alfabeto[j+3];
        }
    }
}
cout<<"Frase codificada:"<<endl;
cout<<fraseCodificada;
    return 0;
}