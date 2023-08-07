#include <iostream>
using namespace std;

struct memes{
    int numero;
    string arquivo, assunto, site;
};

void leitura(memes vetor[], int tam){
    for(int i=0; i<tam; i++){
        cin >> vetor[i].numero
            >> vetor[i].arquivo
            >> vetor[i].assunto
            >> vetor[i].site;
    }
}

void ordem_selection(memes vetor[], int tam){
    int menor;
    for(int i=0; i<tam-1; i++){
        menor = i;
        for(int j = i; j<tam; j++){
            if(vetor[menor].numero > vetor[j].numero)
                menor = j;
        }
        memes aux[1];
        aux[0] = vetor[i];
        vetor[i] = vetor[menor];
        vetor[menor] = aux[0];
    }
}

void busca(memes imagem[], int qtd, string procurado){
    for(int i=0; i<qtd; i++){
        if(imagem[i].site == procurado){
            cout << imagem[i].numero << " "
                << imagem[i].arquivo << " "
                << imagem[i].assunto << " "
                << imagem[i].site << endl;
        }
        if((imagem[i].site != procurado) and (i == qtd-1)){
            cout << "Inexistente" << endl;
        }
    }
}

int main(){
    int qtd;
    cin >> qtd;
    memes imagem[qtd];

    leitura(imagem, qtd);
    ordem_selection(imagem, qtd);

    string procurado;
    cin >> procurado;
    busca(imagem, qtd, procurado);

    return 0;
}