#include <iostream>
using namespace std;

int main(){
    //A contagem dos vetores começa no zero: vet 0, vet 1, vet 2 e vet 3.
    //int vet[4];
    //vet[0] = 5;
    //vet[1] = 10;

    //Outra forma de declarar vetores:
    //O 5 está no vet 0, o 10 está no vet 1, e o vet 2 e 3 tem valor 0.
    //Se eu não declaro o número de elementos do meu vetor, ele considera os elementos que eu declarar na ordem, vet 0, vet 1....
    //int vet[4] = {5, 10};

    //Obs: Ambas as formas são formas mostrar o vetor por Alocação Estática.

    //cout << vet[2] << endl;

    //Outra forma de imprimir o vetor é usando for
    /*for(int i=0; i<4; i++){
        cout << vet[i] << " ";
    }
    cout << endl;*/

    //Função que demonstra quantos bytes tem um elemento no código:
    /*int x = sizeof(vet);
    int y = sizeof(int);
    int z = sizeof(vet)/sizeof(int);
    cout << y << endl;
    cout << x << endl;
    cout << "Quantidade de elementos no vetor: " << z << endl;*/

    //Alocação Dinâmica:
    //Essa forma de alocação permite que enquanto o programa estiver rodando, ser possível ver o tamanho da variavel e muda-la usando delete
    int tamanho;
    cout << "Digite o tamanho do vetor!" << endl;
    cin >> tamanho;
    int* vetor = new int[tamanho];

    for(int i=0; i<tamanho; i++){
        cout << "Digite elemento " << i+1 << " do vetor:" << endl;
        cin >> vetor[i];
    }

//Esse for está sendo utilizado para imprimir os elementos do vetor
    for(int i=0; i<tamanho; i++){
        cout << vetor[i] << " ";
    }
    cout << endl;

//Para deletar o conteudo do vetor e aquele espaço de memória ser reutilizado, usa-se delete
    delete [] vetor;

    return 0;
}