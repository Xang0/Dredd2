#include <iostream>
using namespace std;

struct mercado{
    int numero;
    string nome;
    float preco;
};

int particiona(mercado vetor[], int i, int f){
    mercado pivo[1];
    pivo[0] = vetor[f];
    int j = i;
    for(int k = i; k < f; k++){
        if(vetor[k].preco <= pivo[0].preco){
            swap(vetor[k], vetor[j]);
            j++;
        }
    }
    swap(vetor[j], vetor[f]);

    return j;
}

void quick_sort(mercado vetor[], int inicio, int fim){
    int meio;
    if(inicio < fim){
        meio = particiona(vetor, inicio, fim);
        quick_sort(vetor, inicio, meio-1);
        quick_sort(vetor, meio+1, fim);
    }
}

int main(){
    int qtd;
    cin >> qtd;
    cin.ignore(2, '\n');
    mercado* produto = new mercado[qtd];

    for(int i=0; i<qtd; i++){
        cin >> produto[i].numero;
        cin.ignore();
        getline(cin, produto[i].nome);
        cin >> produto[i].preco;
        cin.ignore(2, '\n');
    }

    quick_sort(produto, 0, qtd-1);

    int max, min;
    cin >> min >> max;

    for(int i=0; i<qtd; i++){
        if((produto[i].preco > min) and (produto[i].preco < max))
            cout << produto[i].numero << " " << produto[i].nome << " " << produto[i].preco << endl; 
    }

    return 0;
}