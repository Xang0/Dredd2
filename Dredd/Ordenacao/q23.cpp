#include <iostream>
using namespace std;

int particiona(int vetor[], int inicio, int fim){
    int pivo = vetor[fim];
    int j = inicio;
    for(int k = inicio; k < fim; k++){
        if(vetor[k] <= pivo){
            swap(vetor[k], vetor[j]);
            j++;
        }
    }
    swap(vetor[j], vetor[fim]);

    return j;
}

void quick_sort(int vetor[], int pos_pivo, int fim){
    int pos_novo_pivo;
    if(pos_pivo < fim){
        pos_novo_pivo = particiona(vetor, pos_pivo, fim);
        quick_sort(vetor, pos_pivo, pos_novo_pivo - 1);
        quick_sort(vetor, pos_novo_pivo + 1, fim);
    }
}

int main(){
    int tam, K;
    cin >> tam;

    int vetor[tam];
    for(int i=0; i<tam; i++) cin >> vetor[i];
    cin >> K;

    quick_sort(vetor, 0, K-1);

    for(int i=0; i<tam; i++) cout << vetor[i] << " ";
    cout << endl;

    return 0;
}