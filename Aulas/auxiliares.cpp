#include <iostream>
using namespace std;

int main(){
//Tanto "i" quanto "quantidade" são variáveis auxiliares contadoras
    /*int num, i = 0, quantidade = 0;
    cin >> num;

    while(num > 0){
        if(num%2 == 0){
            i++;
        }
        cin >> num;
    }*/
//O segundo cin que dá armazena o valor de num precisa estar dentro do laço, pois se não, o código ficará esperando um próximo numéro que não virá

    /*do {
   	 cin >> num;
   	 
   	 if (((num % 2) == 0) and (num != 0))
   		 quantidade++;
    } while (num != 0);*/
//Usando o "do...while" eu preciso colocar a função de leitura da entrada apenas uma vez já que a ação ocorre primeiro que a avaliação

    //cout << i << endl;

    /*int i = -1, num, soma = 0, media;

    do{
        cin >> num;
        i++;
        soma += num;
    }while(i < num);
    media = soma/i;

    cout << media << endl;*/
//Neste caso é melhor utilizar o while já que é necessário a avaliação primeiro para que não contas a mais

    /*int num;
    int cont = 0;
    float valor; 
    float soma = 0;
    cin >> num;
    while (cont < num) {
   	 cin >> valor;
   	 cont++;
   	 soma += valor;
    }*/

    return 0;
}