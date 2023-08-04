#include <iostream>
using namespace std;

int main() {
    int var1;
    int* pont1;
    var1 = 5;
    pont1 = &var1;
    cout << *pont1 << endl;

    int var2;
    //Quero atribuir a ela o valor de var1.
    //var2 = var1;
    //Ou
    var2 = *pont1;
    cout << var2 << endl;

    //Quero mudar o valor de var1.
    //var1 = 30;
    //Ou
    *pont1 = 30;
    cout << var1 << endl;

    int* pont2;
    pont2 = NULL;
    cout << pont2 << endl;

//Nesse caso, o valor inteiro que foi atribuido ao ponteiro só poderá ser acessado por ele e se atribuido um novo valor, aquele original será perdido
    int* pont3 = new int;
    *pont3 = 35;
    cout << *pont3 << endl;

//Neste caso, por não ter * denotando o valor que o ponteiro foi atribuido, foi atribuido ao pont3 o endereço do pont1
//Dessa forma, o valor que antes estava armazenado no endereço de memória atribuido ao pont3 se perde, pois não há mais como acessá-lo
//Uma forma de lidar com esse vazamento de memória é apagar o endereço de memória tribuido ao pont3 antes de ser atribuido a ele o pont1
    //delete pont3;
    //pont3 = pont1;
    cout << *pont3 << " " << *pont1 << endl;

    return 0;
}