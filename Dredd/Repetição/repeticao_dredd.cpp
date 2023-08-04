#include <iostream>
#include <fstream>
using namespace std;

int main(){
    int tam, repetidos=0;
    ifstream arqA("entrada.txt");
    arqA>>tam;

    int vetor[tam];
    for(int i=0; i<tam; i++){
        arqA>>vetor[i];
    }
    for(int i=0; i<tam; i++){
        for(int j=0; j<tam; j++){
            if((vetor[j] == vetor[i]) and (j != i))
                repetidos++;
        }
    }

    int moda[repetidos];
    for(int i=0; i<tam; i++){
        for(int j=0; j<tam; j++){
            if((vetor[j] == vetor[i]) and (i != j)){
                int n=0;
                moda[n] = vetor[j];
                n++;
            }
        }
    }

    ofstream meuArq("saida.txt");
    meuArq<<repetidos<<endl;
    for(int i=0; i<repetidos; i++){
        meuArq<<moda[i]<<" ";
    }
    return 0;
}