#include <iostream>
using namespace std;

int main()
{
	 int tam, cont=0;;
    cin>>tam;

    char vetor[tam];
    for(int i=0; i<tam; i++){
        cin>>vetor[tam];
    }

    char caracter1, caracter2;
    cin>>caracter1>>caracter2;
    for(int i=0; i<tam; i++){
        if(caracter1 < caracter2){
            if(vetor[i] >= caracter1 && vetor[i] != caracter2)
                cont++;
        } else{
            if(vetor[i] >= caracter2 && vetor[i] != caracter1)
                cont++;
        }
    }
    cout<<cont<<endl;

    char meio[cont];
    for(int i=0; i<tam; i++){
        if(caracter1 < caracter2){
            if(vetor[i] == caracter1){
                int n=0;
                while(vetor[i] != caracter2){
                    meio[n] = vetor[i];
                }
            }
        } else{
            if(vetor[i] == caracter2){
                int n=0;
                while(vetor[i] != caracter2){
                    meio[n] = vetor[i];
                }
            }
        }
    }

    for(int i=0; i<cont; i++){
        cout<<meio[i]<<" ";
    }
    cout<<endl;

    return 0;
}

