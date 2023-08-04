#include <iostream>
using namespace std;

struct Atleta{
    float tempo;
};

int main(){
    Atleta *atleta = new Atleta[8];

    float menor;
    for(int i=0; i<8; i++){
        cin >> atleta[i].tempo;
        menor = atleta[i].tempo;
    }
    for(int i=0; i<8; i++){
        if(atleta[i].tempo < menor)
            menor = atleta[i].tempo;
    }

    for(int i=0; i<8; i++){
        if(atleta[i].tempo == menor)
            cout << menor << endl;
        else {
            cout << atleta[i].tempo - menor << endl;
        }
    }

    return 0;
}