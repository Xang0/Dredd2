#include <iostream>
using namespace std;

int main(){
    char vetor1[100];
    char vetor2[100];

    int i = 0;
    char entrada;
    cin >> entrada;
    while(entrada != '\n'){
        cin >> vetor1[i];
        cin >> entrada;
        i++;
    }
    i = 0;
    cin >> entrada;
    while(entrada != '\n'){
        cin >> vetor2[i];
        cin >> entrada;
        i++;
    }
    
    return 0;
}