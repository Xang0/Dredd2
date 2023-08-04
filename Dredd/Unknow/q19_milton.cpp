#include <iostream>
using namespace std;

int main(){
    int tamA, tamB;

    cin >> tamA;
    int vetorA[tamA];
    for(int i=0; i< tamA; i++){
        cin >> vetorA[i];
    }

    cin >> tamB;
    int vetorB[tamB];
    for(int i=0; i< tamB; i++){
        cin >> vetorB[i];
    }

    int count = 0;
    for(int i=0; i<tamB; i++){
        for(int j=0; j<tamA; j++){
            if(vetorA[i]==vetorB[j]) count++;
        }
    }

    int tamC = tamA+tamB-count;

    cout << tamC;
    int vetorC[tamC];
    int i = 0, j = 0, c = 0;
    
    while(i<tamA and j<tamB){
        if(vetorA[i]==vetorB[j]){
            vetorC[c] = vetorA[i];
            j++;
            i++;
            c++;
        }else if(vetorB[j]<vetorA[i]){
            vetorC[c] = vetorB[j];
            j++;
            c++;
        }else if(vetorB[j]>vetorA[i]){
            vetorC[c] = vetorA[i];
            i++;
            c++;
        }

        // if(i==tamA-1){
        //     for(int x=c; x<tamC; x++){
        //         vetorC[c] = vetorB[j];
        //         j++;
        //     }
        // }
        // if(j==tamB-1){
        //     for(int x=c; x<tamC; x++){
        //         vetorC[c] = vetorA[i];
        //         i++;
        //     }
        // }
    }

    for(int x=0; x<tamC; x++){
        cout << vetorC[x] << " ";
    }

}