#include <iostream>
using namespace std;

int main(){
    int vetor[5] = {1,2,3,4,5};

//O valor de um vetor é seu endereço de memória enquanto do seu índice é o valor atribuido aquela posição
    cout << vetor << endl;
    cout << &vetor << endl; 
    cout << &vetor[0] << endl; 

//Forma comum de se atribuir como índice uma váriavel
    const int TAMVETOR = 100;
    int vetor2[TAMVETOR];


    return 0;
}
