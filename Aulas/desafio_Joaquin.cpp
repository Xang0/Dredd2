#include <iostream>
#include <fstream>
using namespace std;

int main(){
    int tam;
    string arquivo;
    cin>>arquivo;
    ifstream dados(arquivo);
    dados>>tam;

    int vetor[tam];
    for(int i=0; i<tam; i++){
        dados>>vetor[i];
    }

    int maior=0, cont=1, moda;
    for(int i=0; i<tam-1; i++){
        for(int j=i+1; j<tam; j++){
            if(vetor[i] == vetor[j]){
                cont++;
            }
            if(maior <= cont){
                moda = vetor[i];
                maior = cont;
            }


        }
    }
    cout<<moda<<endl;
    

	
    return 0;
}
