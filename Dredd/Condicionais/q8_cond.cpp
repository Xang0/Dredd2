#include <iostream>
using namespace std;

int main(){
    int vetor[15];
    int num;

    int i=0;
    while(num != -1){
        cin>>num;
        vetor[i] = num;
        i++;
    }
    while(i>=0){
        if(vetor[i] != vetor[0]){
            if((vetor[i]%vetor[0]) == 0){
                cout<<vetor[i]<<" ";
            }
        }
        i--;
    }
    cout<<endl;


    return 0;
}