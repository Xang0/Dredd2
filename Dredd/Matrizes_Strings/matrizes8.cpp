#include <iostream>
using namespace std;

int main(){
    string palavra, inserido, caracter1, caracter2;
    int posicao;
    cin>>palavra>>posicao>>inserido;
    
    int j=0, i=0;
    while(i<2){
        caracter1[j] = palavra[i];
        j++;
        i++;
    }
    j=0;
    int tam = palavra.size();
    while(i<tam){
        caracter2[j] = palavra[i];
        j++;
        i++;
    }

    for(int y=0; y<2; y++){
        cout<<caracter1[y];
    }
    cout<<inserido;
    for(int n=0; n<(tam-2); n++){
        cout<<caracter2[n];
    }cout<<endl;

    return 0;
}