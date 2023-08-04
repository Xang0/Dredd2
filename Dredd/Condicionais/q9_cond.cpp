#include <iostream>
using namespace std;

int main(){
    int tamanho, menor=0, maior=0, indiceMaior, indiceMenor;
    cin>>tamanho;
    int vet[tamanho];

    for(int i=0; i<tamanho; i++){
        cin>>vet[i];
        if(vet[i] > maior){
            maior = vet[i];
            indiceMaior = i;
        }
    }
    menor = maior;
    for(int i=0; i<tamanho; i++){
        if(vet[i] < menor){
            menor = vet[i];
            indiceMenor = i;
        }
    }

    cout<<maior<<" "<<menor<<" "<<indiceMaior<<" "<<indiceMenor<<endl;

    return 0;
}