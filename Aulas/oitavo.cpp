#include<iostream>

using namespace std;

int main() {
    int n;
    cout<< "Diga um número inteiro não negativo." << endl;
    cin >> n;

    if(n < 0) {
        cout << "Favor infomrar um número positivo e inteiro.\n";
        return 0;
    }

    int soma = 0 , cont = 1;
//Quando o programa se repete infinitamente, exite o comando "break"
    while (cont <= n){
        soma+=cont;
        cont+=1;
        cout << "teste\n";
    }

    /*do{
        soma+=cont;
        cont+=1;
    } while(cont <= n);*/

//Se o "j" valesse 0, o computador teria de fazer um calculo a mais
//do que se j fosse igual a 1
    /*for(int j=1 ; j<=n ; j+=1) {
        soma+=j;
        cout << "teste\n";
    }*/

    cout << "Soma dos némeros de 0 até " << n << " = " << soma << endl;

    return 0;
}