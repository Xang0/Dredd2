#include <iostream>
using namespace std;

int main()
{
    int N, maior=0, indice;
    cin>>N;
    string palavras[N];
    for(int i=0; i<N; i++){
        cin>>palavras[i];
    }

    char letra;
    cin>>letra;
    for(int i=0; i<N; i++){
        int tam = palavras[i].size();
        int cont=0;
        for(int j=0; j<tam; j++){
            if(palavras[i][j] == letra)
                cont++;
        }
        if(maior <= cont){
            maior = cont;
            indice = i;
        }
    }

    cout<<palavras[indice]<<endl;


    return 0;
}