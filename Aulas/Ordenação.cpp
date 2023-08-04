#include <iostream>
using namespace std;

void selection_sort(int vetor[], int tam)
{
    for (int i = 0; i < tam - 1; i++) // Laço vai até tamanaho-1 para que não faça uma última comparação desnecessária
    {
        int menor = i;
        for (int j = i; j < 5; j++)
        {
            if (vetor[menor] > vetor[j]) // Para atualizar qual é o indice com menor valor, eu usso a mesma variavel indice de comparação no if também
                menor = j;               // como aquela que vai receber o novo indice
        }
        int aux = vetor[i];
        vetor[i] = vetor[menor];
        vetor[menor] = aux;
    }
}

void insertion_sort(int vetor[], int tam)
{
    int valor_pivo, j;
    for (int i = 1; i < tam; i++)
    {
        valor_pivo = vetor[i];                       // Amazeno o valor que no final do loop interno será atribuido ao primero indice
        j = i - 1;                                   // Pegar os valores a esquerda do pivô
        while ((j >= 0) and (valor_pivo < vetor[j])) // Enquanto o j for maior ou igual a 0 e o valor do pivô ser menor qeu seu valor a esquerda
        {                                            // eu passo para a direita o valor comparado até chegar ao último valor a esquerda no vetor
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = valor_pivo; // Atribuo o valor do pivo ao último valor comparado
    }
}

void shell_sort(int vet[], int size)
{
    // sequência de Ciura, a que tem os melhores resultados experimentais
    // para vetores maiores usar recursão -> h[k] =  floor( 2.25 * h[k-1] ).
    int gaps[9] = {1, 4, 10, 23, 57, 132, 301, 701, 1750};
    int pos_gap = 8;
    while (gaps[pos_gap] > size)
    {
        pos_gap--;
    }
    int value;
    int j;
    while (pos_gap >= 0)
    {
        int gap = gaps[pos_gap];
        cout << "gap: " << gap << endl;

        for (int i = gap; i < size; i++)
        {
            value = vet[i];
            j = i;
            while ((j >= gap) and (value < vet[j - gap]))
            {
                vet[j] = vet[j - gap];
                j = j - gap;
            }
            vet[j] = value;
        }

        pos_gap--;
    }
}

int main()
{
    int tam;
    cin >> tam;
    int vetor[tam];

    for (int i = 0; i < tam; i++)
        cin >> vetor[i];

    // selection_sort(vetor, tam);
    // insertion_sort(vetor, tam);
    shell_sort(vetor, tam);

    for (int i = 0; i < tam; i++)
        cout << vetor[i] << " ";
    cout << endl;

    return 0;
}