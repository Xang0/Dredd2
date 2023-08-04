#include <iostream>
using namespace std;

int main(){
    string P;
    int maior=0, indice, N;
    cin>>P;
    cin>>N;
    string palavras[N];

    for(int i=0; i<N; i++){
        cin>>palavras[i];
    }

    for(int i=0; i<N; i++){
        int cont=0;
        for(int j=0; j<5; j++){
            if(palavras[i][j] == P[j]){
                cont++;
            }
        }
        if(cont >= maior){
            maior = cont;
            indice = i;
        }
    }
    cout<<palavras[indice]<<endl;

    return 0;
}