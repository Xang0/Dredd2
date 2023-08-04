#include <iostream>
#include <fstream>
using namespace std;

void minha_func(string x) {

}

int main() {
    /*int vet [5];
    for(int num : vet){
        sequencia de comandos;
    }*/

//O "&" indica que será utilizada a variável e não seu valor
//Sem ela não é possível alterar o elemento
    /*for(int& num : vet){
        sequencia de comandos;
    }*/

    string vetor[5] = {"joão",
	"maria", "pedro", "thiago",
	"carlos"};
    minha_func(vetor[0])
    for (int i = 0; i < 5; i++) {
	    cout << vetor[i] ;
    }
    cout << endl;

    for (string t : vetor) {
	    t = "X" + t + "X";
    }

//Pelo "&" demonstrar que será utilizada 
    for (string& t : vetor) {
	    t = " " + t + " ";
    }
    for (string t : vetor) {
	    cout << t;
    }
    cout << endl;

    /*string teste = "Ola, mundo!";
    for (char& c: teste) {
	    cout << c << " ";
    }
    cout << endl;*/

    return 0;
}