#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include <fstream>

using namespace std;

int main() {
    //ofstream arquivo("meus_dados.txt");
    //arquivo << "Testando como funciona a abertura, leitura e escrita de arquivos a partir do c++." << endl;

    /*ifstream arquivo("meus_dados.txt");
    string dados;
    if (arquivo){
        while (arquivo >> dados){
            cout << dados;
        }
        arquivo.close();
    }*/




    /*ifstream arquivo("numeros.dat");
    float soma = 0.0;
    int num = 0;
    float valor;
    if (arquivo){
        while (arquivo >> valor){
            soma += valor;
            num++;
        }
        cout << soma/num << endl;
    } else
        cout << "Arquivo não pode ser encontrado." << endl;
    break;*/




    /*int num1, num2;
    char valor;
    cout << "Informe dois números e depois uma operação matemática." << endl;
    cin >> num1 >> num2 >> valor;

    switch (valor){
        case '+':
            cout << (num1 + num2) << endl;
            break;
        case '-':
            cout << (num1-num2) << endl;
            break;
        case 'x':
        case '*':
            cout << (num1 * num2) << endl;
            break;
        case '/':
            if (num2 != 0){
                cout << (num1 / num2) << endl;
                break;
            } else {
                cout << "Não é possível dividir um número por 0." << endl;
                break;
            }
        default:
            cout << "Por favor informar uma operação matemática válida." << endl;
    }*/




//Em C/C++, 0 é sempre considerado um valor falso como mostrado nesse caso em que a condicional de valor 0 é ignorada
    /*int m = 1;
    int n = 0;
    if (m = 0){
        cout << "m vale 1" << endl;
    }

    if (n = 1){
        cout << "n vale 0" << endl;
    }
    cout << m << "\t" << n << endl;*/



//Para fazer comparações entre números flutuantes, deve tolerar certo erro subitraindo os dois valores que quer comprarar como iguais.
    /*float x = 1.1;
   
    if (abs(2*x - 2.2) <= 0.00001) {
        cout << "passou no 2o. teste" << endl;
    }*/


    /*int cont, soma;
    cin >> cont;
    if ((cont == 20) || (soma >= 200)){
        cout << "Deu certo.";
    } else {
        cout << "foda-se";
    }*/

    /*int a, b, valor;
    cin >> a >> b;
    while(b != 0){
        valor = a%b;
        a = b;
        b = valor;
    }
    cout << a << endl;*/

    /*int tempo = 0, hora, minuto, segundo;
    float massa;
    cin >> massa;

    while(massa > 0.10){
        massa -= massa*0.25;
        tempo += 30;
    }

    segundo = (tempo%3600)%60;
    minuto = (tempo/60)%60;
    hora = tempo/3600;

    cout << hora << ":" << minuto << ":" << segundo << endl;

    int x=0, y=5;*/

    double nota, maior = -1;
    int i = -1;

//A variável i tem valor -1, pois uma das notas apresentadas pelo usuário não será tratada como nota e por isso deve ser desconsiderada
//Enquanto maior é iniciado com valor -1 pois um candidato pode muito bem tirar nota maior ou igual a zero
//O cin é colocado em primeiro nese caso pois quando o programa repetir na expressão de controle, deve-se ler a nota primeiro enquanto a função
// if armazena o valor primeiro e de acordo com que vai aparecendo maiores, também acumula eles e exclui os que não forem maiores
    do{
        cin >> nota;
        i++;
        if(nota > maior)
        maior = nota;
    } while(nota >= 0);
    
    cout << i << endl;
    cout << maior << endl;

    

    

    return 0;
}