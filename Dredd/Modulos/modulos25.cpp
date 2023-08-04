#include <iostream>
using namespace std;

void contador(string emoticons[], string linhas[], int N, int M, int& qtd){
    bool mudancas;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            for(unsigned y=0; y<linhas[i].size(); y++){
                if(linhas[i][y] == emoticons[j][0]){
                    mudancas = true;
                    for(unsigned z=1; z<emoticons[j].size(); z++){
                        if(linhas[i][y+z] != emoticons[j][z])
                            mudancas = false;
                    }
                    if(mudancas)
                        qtd += emoticons[j].size();
                }
            }
        }
    }
}

int main(){
    int N, M;
    int qtd=0;

    cin>>N>>M;
    while(N != 0 and M != 0){
        string emoticons[N];
        string linhas[M];

        for(int i=0; i<N; i++){
            cin.ignore();
            getline(cin, emoticons[i]);
        }
        for(int i=0; i<M; i++){
            cin.ignore();
            getline(cin, linhas[i]);
        }
            
        contador(emoticons, linhas, N, M, qtd);
        
        cout<<qtd<<endl;
        
        cin>>N>>M;
    }

    return 0;
}