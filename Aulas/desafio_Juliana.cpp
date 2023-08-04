#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream arqA("arquivoA.txt");
    ifstream arqB("arquivoB.txt");
    ofstream arqC("arquivoC.txt");

    string caracterA, caracterB, caracterC;
    int tamA=0, tamB=0;
    if(arqA){
        while(arqA>>caracterA[tamA]){
            tamA++;
        }
    }
    if(arqB){
        while(arqB>>caracterB[tamB]){
            tamB++;
        }
    }

    arqA.close();
    arqB.close();

    for(int i=0; i<tamA; i++){
        for(int j=0; j<tamB; j++){
            if(caracterA[i] == caracterB[j]){
                arqC<<caracterA[i]<<" ";
            }
        }
    }

    arqC.close();

    return 0;
}