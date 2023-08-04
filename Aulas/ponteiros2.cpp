#include <iostream>
using namespace std;

/*int main(){
    int vetor[10];
    for (int i=0; i<10; i++){
	    cin >> vetor[i];
    }
    int* ptr1 = (int*) &vetor;
    int* ptr2 = vetor; 
    cout << vetor << endl;
    cout << &vetor << endl;
    cout << &vetor[1] << endl;
    cout << ptr1 << endl;
    cout << ptr2 << endl;

    return 0;
}*/

struct Ponto{
	int X, Y;
};
int main(){
Ponto P1, *P2, *P3;
cin >> P1.X >> P1.Y;
P2 = &P1;
P3 = &P1;
cout << "P1: X = " << P1.X << " Y = " << P1.Y << endl;
cout << "P2: X = " << (*P2).X << " Y = " << (*P2).Y << endl;
cout << "P3: X = " << P3->X << " Y = " << P3->Y << endl;
}