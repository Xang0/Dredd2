#include <iostream>
using namespace std;

int busca(int vetor[],int& menor, int& tam){
    if(tam >= 0){
        if(vetor[tam] < menor){
            menor = vetor[tam];
        }
        tam--;
        busca(vetor, menor, tam);
    }

    return menor;
}

int main(){
    int tam;
    cin >> tam;
    int vetor[tam];
    for(int i=0; i<tam; i++) cin >> vetor[i];

    tam--;
    int menor = vetor[tam];
    cout << busca(vetor, menor, tam) << endl;

    return 0;
}