#include <iostream>
using namespace std;

struct medalhas{
    int ouro, prata, bronze;
};

int main(){
    medalhas *paises = new medalhas;
    int *valorO = new int;
    int *valorP = new int;
    int *valorB = new int;

    int ouro, prata, bronze;
    cin >> ouro >> prata >> bronze
    >> paises->ouro >> paises->prata >> paises->bronze;

    valorO = &ouro;
    valorP = &prata;
    valorB = &bronze;

    cout << (*valorO*paises->ouro)+(*valorP*paises->prata)+(*valorB*paises->bronze) << endl;;

    return 0;
}