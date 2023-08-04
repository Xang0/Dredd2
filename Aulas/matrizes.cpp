#include <iostream>
#include <cstring>
using namespace std;

int main(){
    /*double matriz[3][3];
    double K;

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin >> matriz[i][j];
        }
    }
    cin >> K;
    for(int i=0; i<3; i++){
        cout << matriz[i][i]*K << endl;
    }*/
//Na saída de dados, como a diagonal vai ter como coluna e linha índicis iguais, é possivel 

    /*string frase1 = "Bom dia.";
    char frase2[20] = "Boa noite.";
    cout << frase1[1] << endl;
    cout << frase2[6] << endl;*/
//Strings são vetores de char e podem ser tratadas da mesmo forma que um vetor

    /*string primeiroTexto = "Oa ud!";
    char segundoTexto[10] = "l,Mno!";
    int i = 0;
    while (i < 6) {
   	 cout << primeiroTexto[i] << segundoTexto[i];
   	 i++;
    }
    cout << endl;*/

    /*int tam1, tam2;
    string frase3 = "Bom dia.";
    char frase4[30] = "Boa noite.";
    tam1 = frase3.length(); // ou frase1.size()
    tam2 = strlen(frase4);
    cout << tam1 << " " << tam2 << endl;*/

    char palavra[12];
    cin >> palavra;

    int indicePalavra=0;
    while(indicePalavra<12){
        if(palavra[indicePalavra] == 'z')
            palavra[indicePalavra] = 'a';
        else
            palavra[indicePalavra] = palavra[indicePalavra] + 1;
        indicePalavra++;
    }
    cout << palavra <<  endl;



    return 0;
}