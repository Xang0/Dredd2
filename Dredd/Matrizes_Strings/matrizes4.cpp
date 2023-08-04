#include <iostream>
using namespace std;

int main(){
    int tam, quantidade;
    cin>>tam;
    string palavras[tam];
    char letra;

    for(int i=0; i<tam; i++){
        cin>>palavras[i];
    }

    cin>>letra;

    for(int i=0; i<tam; i++){
        int tamP = palavras[i].size();
        int cont = 0;
        for(int j=0; j<tamP; j++){
            if(palavras[i][j] == letra)
                cont++;
        }
        if(cont == 0)
            quantidade++;
    }

    cout<<quantidade<<endl;

    return 0;
}