#include <iostream>
using namespace std;

//Por enum tarablhar com valores inteiros nomeados, se eu entrar com a string quarta, o código não irá identificar a string quarta como dia útil
enum diasUteis {segunda=2,terca,quarta,quinta,sexta};
int main() {
    int dia;
    cin >> dia;
    if (dia == segunda)  
        cout << "Segunda é dia de praticar algoritmos" << endl;
    else if (dia == 3)
        cout << "Terça é dia de praticar algoritmos" << endl;
    else if (dia == quarta)
        cout << "Quarta é dia de praticar algoritmos" << endl;
    else if (dia == quinta)
        cout << "Quinta é dia de praticar algoritmos" << endl;
    else if (dia == sexta)
        cout << "Sexta é dia de praticar algoritmos" << endl;
    else 
        cout << "Não é dia útil? Ótimo para praticar algoritmos!" << endl;
    return 0;
}
//Apesar de, se eu quiser relacionar a variável dia com um número inteiro não nomeado, o código funcionar normalmente, a tipagem derivada enum torna meu código mais claro