#include <iostream>
using namespace std;

int main() {
    int ano;
    cin >> ano;
    if((ano%400==0) || (ano%4==0 && ano%100!=0)){
        cout << "Esse é um ano bisexto.\n";
    } else {
        cout << "Esse não é um ano bisexto.\n";
    }

    return 0;
}