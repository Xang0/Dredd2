#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int hora, minuto, ms;
    float segundo;

    ifstream arquivo("tempo.txt");
    arquivo >> ms;

    //Tenho que pegar milisegundos e transformar em hora, minuto e segundo
    //1 segundo = 1000 milisegundos, 1 minuto = 60 segundos e 1hora é igual a 60 segundos
    /*A primeira parte do calculo é transformar ms em minuto, segundo ou hora dividindo por 1000*60 (para minuto)
    e 1000*60*60 (para hora).
    Já a segundo parte, eu pego resto da divisão por 60 da quantidade de minutos ou horas alcançadas para assim
    na conversão do valor para seu superior (minuto -> hora) mostre quanto do valor sobrou.*/
    segundo = (ms%60000)/1000.0;
    minuto = (ms/(1000*60))%60;
    hora = (ms/(1000*60*60))%24;

    ofstream meu_arq("horario.txt");
    meu_arq << hora << ":" << minuto << ":" << segundo;

    return 0;
}