#include <iostream>
using namespace std;

int main()
{
    int tam;
    cin >> tam;
    int *vetor = new int[tam];
    for (int i = 0; i < tam; i++)
        cin >> vetor[i];

    int i = 0;
    int n = 1;
    while (i < (tam / 2))
    {
        if (vetor[i] == vetor[tam - n])
        {
            cout << i << " " << vetor[i] << " " << tam - n << " " << vetor[tam - n] << " ";
        }
        else
        {
            cout << endl << "nao" << endl;
            return 0;
        }
        i++;
        n++;
    }
    cout << endl;
    if (i == tam)
    {
        cout << "sim" << endl;
    }
    return 0;
}