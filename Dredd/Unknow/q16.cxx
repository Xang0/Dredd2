#include <iostream>
#include <fstream>
using namespace std;

int main()
{
   string arquivo, texto;
   cin>>arquivo;

   ifstream meuArq{arquivo};
   while(meuArq){
    getline(meuArq, texto);
    cout<<texto;
   }

   int tamanho = texto.size();
   for(int i=0; i<tamanho; i++){
    texto[i] = 90 - (texto[i] - 65);
    cout<<texto;
   }

	return 0;
}

