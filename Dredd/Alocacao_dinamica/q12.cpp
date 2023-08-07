#include <iostream>

using namespace std;

int main(){
    char vetor1[100];
    char vetor2[100];
    char* concatena = NULL;

    string linha;
    unsigned tam1 = 0;
    getline(cin, linha);
    while(tam1 < linha.size()){
        vetor1[tam1] = linha[tam1];
        tam1++;
    }
    unsigned tam2 = 0;
    getline(cin, linha);
    while(tam2 < linha.size()){
        vetor2[tam2] = linha[tam2];
        tam2++;
    }

    concatena = new char[tam1+tam2];
    int tamC = tam1+tam2+1;
    for(unsigned i=0; i<tam1; i++){
        concatena[i] = vetor1[i];
    }
    concatena[tam1] = ' ';
    int aux = 0;
    for(int i=tam1+1; i < tamC; i++){
        concatena[i] = vetor2[aux];
        aux++;
    }

    for(int i=0; i<tamC; i++) cout << concatena[i];
    cout << endl;
    
    return 0;
}