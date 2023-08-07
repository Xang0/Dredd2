#include <iostream>
using namespace std;

struct bolao{
    int numero, gols;
    string nome;
};

void leitura(bolao time[], int qtd){
    for(int i=0; i<qtd; i++){
        cin >> time[i].numero
            >> time[i].nome
            >> time[i].gols;
    }
}

void ordena_shell(bolao vetor[], int tam){
    int j;
    bolao pivo[1];
    for(int i=1; i<tam; i++){
        pivo[0] = vetor[i];
        j = i-1;
        while((j >= 0) and (vetor[j].numero > pivo[0].numero)){
            vetor[j+1] = vetor[j];
            j--;
        }
        vetor[j+1] = pivo[0]; 
    }
}

int buscar(bolao vetor[], int tam, int procurado){
    int indice = -1;
    for(int i = 0; i<tam; i++){
        if(vetor[i].numero == procurado){
            indice = i;
        }
    }

    return indice;
}

int main(){
    int qtd, procurado;
    cin >> qtd;
    bolao time[qtd];

    leitura(time, qtd);
    ordena_shell(time, qtd);
    
    cin >> procurado;

    int indice = buscar(time, qtd, procurado);
    if(indice != -1){
        cout << indice << endl
            << time[indice].nome << " " << time[indice].gols << endl;
    } else{
        cout << indice << endl;
    }

    return 0;
}