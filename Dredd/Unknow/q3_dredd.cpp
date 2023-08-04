#include <iostream>
using namespace std;

int main (){
    int inimigos, vida, derrotados=0, n=1;
    cin >> inimigos;
    int vet[inimigos];

    for(int i=0; i<inimigos; i++){
        cin >> vida;
        vet[i] = vida;
    }
    for(int& dados : vet){
        dados-=n;
        if(dados<=0){
            derrotados++;
            for(int& dados: vet)
                dados-=n;
            n++;
        }
    }

    cout << derrotados << endl;

    return 0;
}