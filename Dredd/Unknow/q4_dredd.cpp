#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int T, N, num, soma=0, aux;
    cin >> T;
    int vet[T];

    if(T<3){
        cin >> T;
    }
    for(int i=0; i<T; i++){
        cin >> num;
        vet[i] = num;
    }
    cin >> N;
    for(int i=0; i<(T-2); i++){
        soma = vet[i]+vet[i+1]+vet[i+2];
        aux = i;
    }
    if(soma == N)
        cout << vet[aux] << " " << vet[aux+1] << " " << vet[aux+2] << endl;
    else
        cout << "-1" << endl;
    
    return 0;
}