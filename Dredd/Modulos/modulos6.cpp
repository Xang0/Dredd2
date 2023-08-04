#include <iostream>
#include <iomanip>
using namespace std;

int calculo(int tam, int vet[]){
    double mediana;
    if(tam%2 == 0){
        mediana = (double) (vet[(tam/2)-1] + vet[(tam/2)])/2;
    } else{
        mediana = vet[tam/2];
    }
    return mediana;
}

int main(){
    int tam;
    cin>>tam;
    int vetor[tam];

    for(int i=0; i<tam; i++){
        cin>>vetor[i];
    }

    cout<<calculo(tam, vetor)<<endl;

    return 0;
}