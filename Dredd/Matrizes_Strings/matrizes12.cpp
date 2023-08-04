#include <iostream>
using namespace std;

int main(){
    int qtd;
    cin>>qtd;
    string palavras[qtd];

    unsigned maior=0;
    for(int i=0; i<qtd; i++){
        cin>>palavras[i];
        if(palavras[i].size() > maior)
            maior = palavras[i].size();
    }

    for(int i=0; i<qtd; i++){
        unsigned j=0;
        if(palavras[i].size() < maior){
            while(j < (maior - palavras[i].size())){
                cout<<"*";
                j++;
            }cout<<palavras[i]<<endl;
        }else
			cout<<palavras[i]<<endl;
    }
    return 0;
}