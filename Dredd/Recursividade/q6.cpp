#include <iostream>
using namespace std;

int calculo(int& numero){
    if(numero == 0){
        numero = 1;
    } else if(numero%2 == 0){

        calculo(numero);
    }else {
        
        calculo(numero);
    }
    return numero;
}

int main(){
    int numero;
    cin >> numero;

    cout << numero;

    return 0;
}