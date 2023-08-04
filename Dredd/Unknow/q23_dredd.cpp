#include <iostream>
using namespace std;

int main(){
    int tam, cont=0;
    cin>>tam;
    char matriz[tam][tam];
    char subMatriz[2][2];
    bool vogal1 = falso;
    bool vogal2 = falso;

    for(int i=0; i<tam; i++){
        for(int j=0; j<tam; j++){
            cin>>matriz[i][j];
        }
    }
    do{
        for(int i=0; i<tam; i++){
            for(int j=0; j<tam; j++){
                if(matriz[i][j] == ("A"||"E"||"I"||"O"||"U")){
                    vogal1 = true;
                    cont++;
                }
            }
        }
        if(vogal1){
            for(int i=0; i<tam; i++){
                for(int j=0; j<tam; j++){
                    if(matriz[i][j] == ("A"||"E"||"I"||"O"||"U")){
                        vogal2 = true;
                        cont++;
                    }
                }
            }
        }
        if(vogal1 && vogal2){
            submatriz[]
        }
    } while(cont < (tam*tam));


    return 0;
}