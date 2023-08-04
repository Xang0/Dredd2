#include <iostream>

using namespace std;

int main()
{

    //crie um loop para a entrada de 10 itens em um vetor

    int vetor[10];

    for (int i = 0; i < 10; i++)
    {
        cout << "Digite o " << i + 1 << "º valor: ";
        cin >> vetor[i];
    }

    return
}