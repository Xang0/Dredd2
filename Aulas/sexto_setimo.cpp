#include <iostream>

using namespace std;

int main() {
    float nota1, nota2;
    cout<< "Qual a nota da sua P1:\n";
    cin>> nota1;
    cout<< "Qual a nota da sua P2:\n";
    cin >> nota2;
    float media= (nota1+nota2)/2;
    cout<< "Media: " << media << endl; 

    //Comparações: Igual: == , Diferença: != , Outros: > , < , >= , <=
    /*if(media >= 5){
        cout<< "Parábens!! Você passou.\n";
        cout<< "Você tirou no trimestre " << media << endl;
    }*/

    /*if(media >=5.99) {
        cout<< "Aluno aprovado\n";
    }else {
        cout<< "Aluno reprovado\n";
    }*/

    //O else if é utilizado quando a mais de uma opção quando certa condição é satisfeita
    if(media < 2.5){
        cout << "Nota Final: D\n";
    }else if(media < 5){
        cout << "Nota Final: C\n";
    }else if(media < 7.5){
        cout << "Nota Final: B\n";
    }else {
        cout << "Nota Final: A\n";
    }

    //Operadores Lógicos: E: && , OU: || , NÃO: !
    float freq;
    cout << "Qual é a frequência do aluno?\n";
    cin >> freq;

    //Somente é possível comparar variaveis de mesmo tipo
    /*if (media >= 6 && freq >= 75){
        cout << "Aluno Aprovado!\n";
    }else{
        cout << "Aluno Reprovado!\n";
    }*/

    /*if(media < 6 || freq < 75) {
        cout << "Aluno Reprovado\n";
    }else {
        cout << "Aluno Aprovado!\n";
    }*/

    //Operador Ternário: função condicional feito em uma linha
    (media >= 6 && freq >= 75) ? cout << "Aluno Aprovado\n" : cout << "Aluno Reprovado\n"; 

    return 0;
}