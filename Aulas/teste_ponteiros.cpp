#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct pessoa{
	char nome[20];
	char cpf[14];
	char tipoSanguineo[3];
	int porcentVermelho;
	int porcentBranco;
    float densidade;
};

void leitura(ifstream& arquivo, pessoa cadastros[], int tam){
    char lixo;
    string lixao;

    getline(arquivo, lixao);

    for(int i=0; i<tam-1; i++){
        int capacidade = 0;
        arquivo >> lixo;
        while(lixo != ';'){
            cadastros[i].nome[capacidade] = lixo;
            capacidade++;
            arquivo >> lixo;
        }
        capacidade = 0;
        arquivo >> lixo;
        while(lixo != ';'){
            cadastros[i].cpf[capacidade] = lixo;
            capacidade++;
            arquivo >> lixo;
        }
        capacidade = 0;
        arquivo >> lixo;
        while(lixo != ';'){
            cadastros[i].tipoSanguineo[capacidade] = lixo;
            capacidade++;
            arquivo >> lixo;
        }
        if(not(arquivo >> cadastros[i].porcentVermelho)){
            cout << "Erro na entrada da porcentagem de glóbulos vermelhos. Linha " << i << endl;
        }
        arquivo >> lixo;
        if(not(arquivo >> cadastros[i].porcentBranco)){
            cout << "Erro na entrada da porcentagem de glóbulos brancos. Linha " << i << endl;
        }
        arquivo >> lixo;
        if(not(arquivo >> cadastros[i].densidade)){
            cout << "Erro na entrada da densidade do sangue. Linha " << i << endl;
        }
        arquivo.ignore();
    }


    arquivo.close();
}

void mostrartodosdados(pessoa cadastros[]){

    //Calcula a quantidade de linhas no arquivo csv
    int tam = 0;
    ifstream in("dados_hemograma.csv");
    string unused;
    while ( getline(in, unused) ){
        tam++;
    }
    in.close();

    cout << endl << "** Hemogramas Cadastrados **" << endl;

    for(int i=0; i<tam-1; i++) {
    // Exibe os dados na tela
        cout << cadastros[i].nome << endl; 
        cout << cadastros[i].cpf << endl;
        cout << cadastros[i].tipoSanguineo << endl;
        cout << cadastros[i].porcentVermelho << "%" << endl;
        cout << cadastros[i].porcentBranco << "%" << endl;
        cout << cadastros[i].densidade << endl;
        cout << endl;
    }
}

int main(){
    int capacidade = 150;
	pessoa *cadastros;
    int linhas = 101;
    cadastros = new pessoa[capacidade];
    
    
    ifstream arquivo("dados_hemograma.csv");

    //Testa se o arquivo foi aberto corretamente para sua leitura e continuidade do código
    if (!arquivo) {
        cout << "Erro ao abrir o arquivo!" << endl;
        return 1;
    }else {
        leitura(arquivo, cadastros, linhas);
    }

    mostrartodosdados(cadastros);

    return 0;
}