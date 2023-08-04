//Usar esse código para testar coisas
#include<iostream>

using namespace std;

//A estrutura de uma função é a mesma do código principal
//Nesse caso, a função tipo "void" não tem saíde, sem resposta
void inscrever() {
    cout<< "F*ck Yeah!!\n";
}
//O & é usado para atrelar a variavel de uma função a outra
int somar(int &x, int &y){
    /*Essa variavel "soma" é local
    Ou seja, só existe na função onde ela está inserida*/
    int soma= x+y;
    x=29;

    int t;
    t=1;

    return soma;
}

int main() {
    int a=5, b=4;
    int s= somar(a,b);
    cout<< "Valor de a: " << a << endl;
    cout<< "Soma: "<< s <<endl;

    inscrever();

    int t;
    t=0;
    cout << "Valor de t: " << t << endl;

    return 0;
}