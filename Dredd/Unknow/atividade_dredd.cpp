#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

int main() {
    /*int angulo, angulo1;
    float x, y;
    cout << "Escreva o angulo de uma reta no plano cartesiano e os pontos X e Y onde termina essa reta.\n";
    cin << angulo << x << y;

    if(angulo > 360) {
        angulo1 = angulo%360;
    } else {
        if(angulo <= 90){
            cout << x+y << endl;
        } else if(90 < angulo <= 180){
            cout << x*y << endl;
        } else if
    }*/

    /*float n1, n2, n3, n4;
    cin >> n1; 
    cin >> n2; 
    cin >> n3;
    cin >> n4;

    if(n1 > n2 && n1 > n3 && n1 > n4){
        cout << n2+n3+n4 << endl;
    } else if(n2 > n1 && n2 > n3 && n2 > n4){
        cout << n1+n3+n4 << endl;
    } else if(n3 > n1 && n3 > n2 && n3 > n4){
        cout << n1+n2+n4 << endl;
    } else {
        cout << n1+n2+n3 << endl;
    }*/

    char x, y;
    cin >> x;
    cin >> y;

    if(x > y){
        cout << x << endl;
    }else
        cout << y << endl;

    return 0;
}