#include <iostream>
using namespace std;

int main(){
    string expressao;
    cin>>expressao;

    bool validade;
    int tam = expressao.size();
    for(int i=0; i<tam; i++){
        if(expressao[i] == '('){
            validade = false;
            int tam2 = expressao.size() - i;
            for(int j=i; j<tam2; j++){
                if(expressao[j+i] == ')')
                    validade = true;
            }
        }
    }
    if(validade){
        cout<<"parenteses corretos"<<endl;
    } else{
        cout<<"parenteses incorretos"<<endl;
    }
    return 0;
}