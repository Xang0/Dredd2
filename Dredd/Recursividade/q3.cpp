#include <iostream>
using namespace std;

void sequenciaRicci(int& num1, int& num2, int& qtd){
    if(qtd > 0){
        num1 += num2;
        num2 += num1;
        cout << num1 << " " << num2 << " ";
        qtd -= 2;
        sequenciaRicci(num1, num2, qtd);
    }
}

int main(){
    int num1, num2, qtd;
    cin >> num1 >> num2 >> qtd;

    qtd -= 2;
    cout << num1 << " " << num2 << " ";
    sequenciaRicci(num1, num2, qtd);

    return 0;
}