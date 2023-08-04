#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int quantidade;
    cin >> quantidade;
    int *vetor;
    vetor = new int[quantidade];

    for(int i=0; i<quantidade; i++) cin >> vetor[i];

    int maior = 0, segundo_maior;
    int menor = vetor[0], segundo_menor = vetor[0];
    for(int i=0; i<quantidade; i++){
        if(vetor[i] > maior){
            segundo_maior = maior;
            maior = vetor[i];
        }
        if(vetor[i] < menor){
            segundo_menor = menor;
            menor = vetor[i];
        }
    }

    int n=0;
    for(int i=0; i<quantidade; i++){
        if(vetor[i] != segundo_maior and vetor[i] != segundo_menor){
            vetor[n] = vetor[i];
            n++;
        }
    }

    int *novo = new int[quantidade-2];
    memcpy(novo, vetor, sizeof(int)*quantidade-2);
    delete [] vetor;
    vetor = novo;

    for(int i=0; i<quantidade-2; i++){
        cout << vetor[i] << endl;
    }

    return 0;
}