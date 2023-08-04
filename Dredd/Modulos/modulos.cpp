#include <iostream>
using namespace std;

void conjunto(int tamA, int tamB, int& j, int vetorA[], int vetorB[], int uniao[]){
    int igual;
    for(int i=0; i<tamA; i++){
        uniao[j] = vetorA[i];
        j++;
    }
    for(int i=0; i<tamA; i++){
        for(int y=0; y<tamB; y++){
            if(vetorA[i] == vetorB[y])
                igual = vetorB[y];
        }
    }
    for(int i=0; i<tamB; i++){
        if(vetorB[i] != igual){
            uniao[j] = vetorB[i];
            j++;
        }
    }
    
}

int main(){
    int tamA, tamB, tamC=0;
    cin>>tamA>>tamB;
    int vetorA[tamA];
    int vetorB[tamB];
    int uniao[tamA+tamB];

    for(int i=0; i<tamA; i++){
        cin>>vetorA[i];
    }
    for(int i=0; i<tamB; i++){
        cin>>vetorB[i];
    }

    conjunto(tamA, tamB, tamC, vetorA, vetorB, uniao);

    for(int i=0; i<tamC; i++){
        cout<<uniao[i]<<" ";
    }cout<<endl;

    return 0;
}