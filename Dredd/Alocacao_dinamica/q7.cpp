#include <iostream>
using namespace std;

int main(){
    int quantidade;
    cin >> quantidade;
    int *vetor = new int[quantidade];

    for(int i=0; i<quantidade; i++) cin >> vetor[i];

    int *multi_23 = NULL;
    int *multi_2 = NULL;
    int *multi_3 = NULL;
    int tam23 = 0, tam2 = 0, tam3 = 0;
    for(int i=0; i<quantidade; i++){
        if(vetor[i]%2 == 0 and vetor[i]%3 == 0){
            if(tam23 == 0){
                multi_23 = new int[tam23+1];
                multi_23[tam23] = vetor[i];
                tam23++;
            } else{
                int *aux1 = new int[tam23+1];
                copy(multi_23, multi_23+tam23, aux1);
                delete [] multi_23;
                multi_23 = aux1;
                multi_23[tam23] = vetor[i];
                tam23++;
            }
        }
        if(vetor[i]%2 == 0){
            if(tam2 == 0){
                multi_2 = new int[tam2+1];
                multi_2[tam2] = vetor[i];
                tam2++;
            } else{
                int *aux1 = new int[tam2+1];
                copy(multi_2, multi_2+tam2, aux1);
                delete [] multi_2;
                multi_2 = aux1;
                multi_2[tam2] = vetor[i];
                tam2++;
            }
        }
        if(vetor[i]%3 == 0){
            if(tam3 == 0){
                multi_3 = new int[tam3+1];
                multi_3[tam3] = vetor[i];
                tam3++;
            } else{
                int *aux1 = new int[tam3+1];
                copy(multi_3, multi_3+tam3, aux1);
                delete [] multi_3;
                multi_3 = aux1;
                multi_3[tam3] = vetor[i];
                tam3++;
            }
        }
    }

    if(tam2 == 0){
        cout << tam2;
    } else{
        for(int i=0; i<tam2; i++)
            cout << multi_2[i] << " ";
    }cout << endl;

    if(tam3 == 0){
        cout << tam3;
    } else{
        for(int i=0; i<tam3; i++)
            cout << multi_3[i] << " ";
    }cout << endl;

    if(tam23 == 0){
        cout << tam23;
    } else{
        for(int i=0; i<tam23; i++)
            cout << multi_23[i] << " ";
    }cout << endl;

    return 0;
}