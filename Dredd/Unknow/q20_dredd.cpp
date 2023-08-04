#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string arquivo, texto;
    cin>>arquivo;
    ofstream arqA("cifrado.txt");
    ifstream meuArq(arquivo);


    while(getline(meuArq, texto)){
        int tamanho = texto.size();
        for(int i=0; i<tamanho; i++){
            if(texto[i] >= 65 && texto[i] <= 90)
                texto[i] = 90 - (texto[i] - 65);
        }
        arqA<<texto<<'\n';
    }
    
    return 0;
}
