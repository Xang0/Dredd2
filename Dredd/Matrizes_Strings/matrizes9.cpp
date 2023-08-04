#include <iostream>
using namespace std;

int main(){
    string texto, palavra;
    cin>>texto>>palavra;

    bool achou;
    bool completo = false;
    int indice;
    for(unsigned i=0; i<texto.size(); i++){
        if(texto[i] == palavra[0] and !completo){
            achou = true;
            for(unsigned j=1; j<palavra.size(); j++){
                if(texto[i+j] != palavra[j]){
                    achou = false;
                }
            }
            if(achou){
                indice = i;
                completo = true;
            }
        }
    }

    cout<<indice<<endl;

    return 0;
}