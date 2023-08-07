#include <iostream>
#include <fstream>
using namespace std;

struct lava_jato{
    int numero;
    string nome;
};

int main(){
    int tam = 0;
    ifstream in("fases.txt");
    string lixo;
    while(getline(in, lixo)){
        tam++;
    }
    in.close();

    ifstream arquivo("fases.txt");
    lava_jato *operacao = new lava_jato[tam];
    for(int i=0; i<tam; i++){
        arquivo >> operacao[i].numero >> operacao[i].nome;
    }
    arquivo.close();

    int k, j;
    cin >> k;
    lava_jato pivo[1];
    for(int i=1; i < k; i++){
        pivo[0] = operacao[i];
        j = i-1;
        while((j >= 0) and (pivo[0].numero > operacao[j].numero)){
            operacao[j+1] = operacao[j];
            j--;
        }
        operacao[j+1] = pivo[0];
    }

    for(int i = k+1; i < tam; i++){
        pivo[0] = operacao[i];
        j = i-1;
        while((j >= k) and (pivo[0].numero < operacao[j].numero)){
            operacao[j+1] = operacao[j];
            j--;
        }
        operacao[j+1] = pivo[0];
    }

    for(int i=0; i <= tam; i++) cout << operacao[i].nome << endl;

    return 0;
}