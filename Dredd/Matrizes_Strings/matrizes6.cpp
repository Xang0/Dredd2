#include <iostream>
using namespace std;

int main(){
    string principal, procurada;
    cin>>principal;
    cin>>procurada;

    int quantidade=0, cont=0;
    bool validade;
    for(unsigned i=0; i<principal.size(); i++){
        if(principal[i] == procurada[0]){
            validade = true;
            for(unsigned j=1; j<procurada.size(); j++){
                if(principal[i+j] != procurada[j]){
                    validade = false;
                }
            }
            if(validade)
                quantidade++;
        }
    }

    cout<<quantidade<<endl;

    return 0;
}