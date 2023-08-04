#include <iostream>
using namespace std;

void busca(int qtd, int vetor[], int procurado, int &inicio, int &fim, int &resultado)
{
    int meio;

    if (inicio <= fim)
    {
        if (qtd % 2 == 0)
        {
            meio = (fim + inicio) / 2;
        }
        else
        {
            meio = (((fim + inicio) / 2) + 1);
        }
        
        if (procurado == vetor[meio])
        {
            resultado = meio;
        }
        else
        {
            if (procurado > vetor[meio])
            {
                fim = meio - 1;
                busca(qtd, vetor, procurado, inicio, fim, resultado);
            }
            else if (procurado < vetor[meio])
            {
                inicio = meio + 1;
                busca(qtd, vetor, procurado, inicio, fim, resultado);
            }
        }
    }
    else
        resultado = -1;
}

int main()
{
    int quantidade, procurado;
    cin >> quantidade;
    int vetor[quantidade];

    for (int i = 0; i < quantidade; i++)
        cin >> vetor[i];

    cin >> procurado;
    int inicio = 0;
    int fim = quantidade - 1;
    int resultado;
    busca(quantidade, vetor, procurado, inicio, fim, resultado);
    cout << resultado << endl;

    return 0;
}