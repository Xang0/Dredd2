#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int num, produto, tabuada=1;
    cin>>num;

    while(tabuada <= 10){
        produto = num*tabuada;
        cout<< num << " x " << tabuada << " = " << produto << endl;
        tabuada++;
    }

    return 0;
}