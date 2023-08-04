#include <iostream>
using namespace std;

int main()
{
    int tam;
    cin >> tam;
    int *vetor1 = new int[tam];
    int *vetor2 = new int[tam];
    for(int i=0; i<tam; i++)
        cin >> vetor1[i];
    for(int i=0; i<tam; i++)
        cin >> vetor2[i];

    int cont = 0;
    for(int i=0; i<tam; i++){
        for(int j=0; j<tam; j++){
            if(vetor1[i] == vetor2[j])
                cont++;
        }
    }

    if(cont == tam)
        cout << "IGUAIS" << endl;
    else
        cout << "DIFERENTES" << endl;
    
    return 0;
}