#include <iostream>
using namespace std;

int main (){
	int tamA, tamB, tamC, cont=0;
	cin>>tamA;
	int conjuntoA[tamA];
	for(int i=0; i<tamA; i++){
		cin>>conjuntoA[i];
	}
	cin>>tamB;
	int conjuntoB[tamB];
	for(int i=0; i<tamB; i++){
		cin>>conjuntoB[i];
	}

	for(int i=0; i<tamA; i++){
		for(int j=0; j<tamB; j++){
			if(conjuntoA[i] == conjuntoB[j])
				cont++;
		}
	}
	tamC = (tamA+tamB)-cont;

	int conjuntoC[tamC];
	for(int i=0; i<tamA; i++){
		conjuntoC[i] = conjuntoA[i];
	}
	for(int i=0; i<tamB; i++){
		bool aux = true;
		for(int j=0; j<tamA; j++){
			if(conjuntoB[i] == conjuntoC[j])
				aux = false;
		}
		if(aux){
			conjuntoC[tamA] = conjuntoB[i];
		}
	}
	for(int i=0; i<tamC; i++){
		cout<<conjuntoC[i]<<" ";
	}
	cout<<endl;

    return 0;
}