#include <iostream>
using namespace std;

int main(){
    string fita;
    cin>>fita;

    double massaT=0;
    for(unsigned i=0; i<fita.size(); i++){
        if(fita[i] == 'A')
            massaT += (71.03711 + 18.01056);
        else if(fita[i] == 'G')
            massaT += (57.02146 + 18.01056);
        else if(fita[i] == 'C')
            massaT += (103.00919 + 18.01056);
        else
            massaT += (101.04768 + 18.01056);
    }

    cout<<massaT<<endl;

    return 0;
}