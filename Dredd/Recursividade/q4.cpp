#include <iostream>
using namespace std;

int mult(int numero, int& vezes, int& soma){
    if(vezes > 0){
        if(soma == 0){
            soma = numero + numero;
            vezes -=2;
            mult(numero, vezes, soma);
        } else{
            soma += numero;
            vezes--;
            mult(numero, vezes, soma);
        }
    }

    return numero;
}

int main(){
    int numero, vezes;
    cin >> numero >> vezes;

    int soma = 0;
    mult(numero, vezes, soma);

    cout << soma << endl;

    return 0;
}