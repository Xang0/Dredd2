#include <iostream>
using namespace std;

int calculo(int &numero, int &aux){
    if(aux > 0){
        numero *= aux;
        aux -= 2;
        calculo(numero, aux);
    }

    return numero;
}

int main(){
    int numero;
    cin >> numero;

    int aux = numero-2;
    cout << calculo(numero, aux) << endl;

    return 0;
}