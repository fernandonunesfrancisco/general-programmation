#include <iostream>
using namespace std;
#include<vector>

void lerVectorInt(unsigned, vector<int> &);
void mostrarVectorInt(vector<int>);
bool equals(vector<int>, vector<int>);

int main()
{
    vector<int> a, b;
    lerVectorInt(3, a);
    lerVectorInt(3, b);
    cout<<equals(a, b);
    return 0;
}

void lerVectorInt(unsigned n, vector<int> &v){
    double valor;
    for(unsigned i=0;i<n;i++){
        cout<<"Valor:"; cin>>valor; v.push_back(valor);
    }
}

void mostrarVectorInt(vector<int> v){
    for(unsigned i=0; i<v.size(); i++){
        cout<<"["<<v[i]<<"]";
    }
    cout<<endl;
}

bool equals(vector<int> a, vector<int> b){
    if(a.size()!=b.size()) return false;
    for(unsigned i=0; i<a.size(); i++){
        if(a[i]!=b[i]) return false;
    }
    return true;
}

