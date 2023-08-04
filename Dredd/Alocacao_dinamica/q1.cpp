#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

struct registro{
    string marca;
    int ano;
    float distancia, consumo;
};

float kmPorLitro(registro *carro){
    return carro->distancia/carro->consumo;
}

int main(){
    registro *carro = new registro;

    ifstream arquivo("entrada.txt");
    arquivo >> carro->marca >> carro->ano >> carro->distancia >> carro->consumo;
    arquivo.close();

    ofstream arqA("saida.txt");
    arqA << carro->marca << endl;
    arqA << carro->ano << endl;
    arqA << carro->consumo << endl;
    arqA << fixed << setprecision(2) << kmPorLitro(carro);
    arqA.close();

    return 0;
}