#include <iostream>
#include <fstream>
using namespace std;

//Declaração dos campos do registro
struct pessoa{
	string nome;
	string cpf;
	string tipoSanguineo;
	int porcentVermelho;
	int porcentBranco;
    float densidade;
};

//Realoca os dados do vetor de registros para um outro maior
void realocar(pessoa cadastros[], int& capacidade){
	pessoa *novo = new pessoa[capacidade + 50];
	copy(cadastros, cadastros+capacidade, novo);
	delete[] cadastros;
	capacidade = capacidade + 50;
	cadastros = novo;//Faço o ponteiro cadastros ter o mesmo endereço de memória que novo
}


//Lê os dados do arquivo no registro
int leitura(fstream& arquivo, pessoa cadastros[], int tam, bool& leitura_correta){
    char lixo;
    string lixao;

    getline(arquivo, lixao);
    for(int i=0; i<tam-1 and leitura_correta; i++){
        if(not(getline(arquivo, cadastros[i].nome, ';'))){
            cout << "Erro na entrada do nome. Linha " << i+1 << endl;
            leitura_correta = false;
        }
        if(not(getline(arquivo, cadastros[i].cpf, ';'))){
            cout << "Erro na entrada do CPF. Linha " << i+1 << endl;
            leitura_correta = false;
        }
        if(not(getline(arquivo,cadastros[i].tipoSanguineo, ';'))){
            cout << "Erro na entrada do tipo sanguíneo. Linha " << i+1 << endl;
            leitura_correta = false;
        }
        if(not(arquivo >> cadastros[i].porcentVermelho)){
            cout << "Erro na entrada da porcentagem de glóbulos vermelhos. Linha " << i+1 << endl;
            leitura_correta = false;
        }
        arquivo >> lixo;
        if(not(arquivo >> cadastros[i].porcentBranco)){
            cout << "Erro na entrada da porcentagem de glóbulos brancos. Linha " << i+1 << endl;
            leitura_correta = false;
        }
        arquivo >> lixo;
        if(not(arquivo >> cadastros[i].densidade)){
            cout << "Erro na entrada da densidade do sangue. Linha " << i+1 << endl;
            leitura_correta = false;
        }
        arquivo.ignore();
    }

    return 0;
}


//Mostra todos os Dados cadastrados
int mostrartodosdados(pessoa cadastros[], bool& continuar, bool& mostrar){

    //Calcula a quantidade de linhas no arquivo csv
    int tam = 0;
    ifstream in("dados_hemograma.csv");
    string unused;
    while ( getline(in, unused) ){
        tam++;
    }
    in.close();

    if(mostrar){
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

        string continua;
        cout << "deseja continuar?(responda com sim ou não)"<<endl;
        cin >> continua;
        if (continua == "sim"){
            continuar = true;
        } else {
            continuar = false;
        }
        mostrar = false;
    }
    return tam;
}


//Cadastra dados de uma nova pessoa
void cadastrarNovaPessoa(bool& continuar, int& linhas, pessoa cadastros[]) {
    pessoa novaPessoa;

    cout << " CADASTRO DE PESSOA " << endl;
    cout << "Nome: " << endl;
    cin.ignore();
    getline(cin, novaPessoa.nome);
    cout << "CPF com '.' e '-': " << endl;
    getline(cin, novaPessoa.cpf);
    if (novaPessoa.cpf.length() != 14) {//Verifica se CPF digitado com 11 números mais os pontos e o hífens
        cout << "O CPF deve conter 11 números." << endl;
        return;
    }
    for(int i=0; i<linhas ; i++){
        if(novaPessoa.cpf == cadastros[i].cpf){//verifica se o CPF já está cadastrado
            cout<< "Esse CPF já existe" << endl;
            return;
        }
    }
    cout << "Tipo Sanguineo: "<< endl;
    getline(cin, novaPessoa.tipoSanguineo);
    for (size_t i = 0; i < novaPessoa.tipoSanguineo.length(); ++i) {//Transforma a letra digitada em maiúsculo
    novaPessoa.tipoSanguineo[i] = toupper(novaPessoa.tipoSanguineo[i]);
}
    //Verifica se é um tipo sanguineo válido
    if (novaPessoa.tipoSanguineo != "A+" and novaPessoa.tipoSanguineo != "B+" and novaPessoa.tipoSanguineo != "AB+" and novaPessoa.tipoSanguineo != "O+"
    and novaPessoa.tipoSanguineo != "A-" and novaPessoa.tipoSanguineo != "B-" and novaPessoa.tipoSanguineo != "AB-" and novaPessoa.tipoSanguineo != "O-")
    {
        cout<< "Esse tipo de sangue não existe!" << endl;
        return;
    }

    cout << "Porcentagem de Globulos Vermelhos: " << endl;
    cin>> novaPessoa.porcentVermelho;
    cout << "Porcentagem de Globulos Brancos: " << endl;
    cin >> novaPessoa.porcentBranco;
    if (novaPessoa.porcentVermelho + novaPessoa.porcentBranco != 100) {//Verifica se a soma das porcentagens de globulos brancos e vermelhos é menor ou igual a 100
        cout << "A soma das porcentagens de glóbulos vermelhos e brancos deve ser igual ou menor a 100%." << endl;
        return;
    }
    cout << "Densidade do sangue: " << endl;
    cin >> novaPessoa.densidade;

    //Passa o hemograma cadastrado para o arquivo
    ofstream arquivo("dados_hemograma.csv", ios::app); 
    arquivo << "#Nome;CPF;Tipo sanguineo;Porcentagem globulos vermelhos;Porcentagem globulos brancos;Densidade";
    if (arquivo.is_open()) {
        arquivo << novaPessoa.nome << ";"
         << novaPessoa.cpf << ";"
         << novaPessoa.tipoSanguineo << ";"
         << novaPessoa.porcentVermelho << ";"
         << novaPessoa.porcentBranco << ";"
         << novaPessoa.densidade;
    }
    arquivo.close();

    //Passa o hemograma para o último espaço do vetor de registros;
    cadastros[linhas-1].nome = novaPessoa.nome;
    cadastros[linhas-1].cpf = novaPessoa.cpf;
    cadastros[linhas-1].tipoSanguineo = novaPessoa.tipoSanguineo;
    cadastros[linhas-1].porcentVermelho = novaPessoa.porcentVermelho;
    cadastros[linhas-1].porcentBranco = novaPessoa.porcentBranco;
    cadastros[linhas-1].densidade = novaPessoa.densidade;

    cout << endl << "Cadastro realizado!" << endl;

    string continua;
    cout << "deseja continuar?(responda com sim ou não)"<<endl;
        cin >> continua;
        if (continua == "sim"){
            continuar = true;
        } else {
            continuar = false;
        }
}


//Busca os dados de uma pessoa pelo CPF
void buscarpessoa(pessoa nomeProcurado[], bool& continuar, int linhas){
	bool encontrar = false;
    int indice;
	string cpf;
	cout<< "Digite o CPF, com . e -, da pessoa a ser buscada: ";
	cin>> cpf;

    //Faz a busca no vetor de registros pelo CPF digitado
    cout << "Buscando CPF... " << endl;
    for(int i=0; i<linhas and !encontrar; i++){
        if(cpf == nomeProcurado[i].cpf){
            encontrar = true;
            indice = i;
        }
    }
    if (encontrar) { //Se encontrar o CPF, dá saída, se não, mostra que não foi encontrado
		cout << "** PESSOA ENCONTRADA **" << endl;
        cout << "Nome: " << nomeProcurado[indice].nome << endl;
        cout << "CPF: " << nomeProcurado[indice].cpf << endl;
        cout << "Tipo Sanguineo: " << nomeProcurado[indice].tipoSanguineo << endl;
        cout << "Porcentagem Globulos Vermelhos: " << nomeProcurado[indice].porcentVermelho <<"%"<< endl;
        cout << "Porcentagem Globulos Brancos: " << nomeProcurado[indice].porcentBranco <<"%"<< endl;
        cout << "Densidade do Sangue: " << nomeProcurado[indice].densidade << endl;    
    } else {
        cout << endl << "Pessoa não encontrada" << endl;
    }

    string continua;
    cout << "deseja continuar?(responda com sim ou não)"<<endl;
	cin >> continua;
	if (continua == "sim"){
		continuar = true;
	} else {
		continuar = false;
	}

}


//Altera os dados de alguma pessoa escolhida pelo usuário
void alterarpessoa(pessoa nomeProcurado[], int linhas, bool& continuar) {
    bool encontrar = false;
    int indice;
    string cpf;
    cout << "Digite o CPF da pessoa que você deseja alterar (com pontos e traço): ";
    cin >> cpf;

    // Busca pelo CPF digitado no terminal
    for (int i = 0; i < linhas and !encontrar; i++) {
        if (cpf == nomeProcurado[i].cpf) {
            encontrar = true;
            indice = i;
            
        }
    }

    if (encontrar) {
        cout << endl << "** DADOS ATUAIS **" << endl;
        cout << "Nome: " << nomeProcurado[indice].nome << endl;
        cout << "CPF: " << nomeProcurado[indice].cpf << endl;
        cout << "Tipo Sanguíneo: " << nomeProcurado[indice].tipoSanguineo << endl;
        cout << "Porcentagem de Células Vermelhas: " << nomeProcurado[indice].porcentVermelho << endl;
        cout << "Porcentagem de Células Brancas: " << nomeProcurado[indice].porcentBranco << endl;
        cout << "Densidade: " << nomeProcurado[indice].densidade << endl;

        cout << endl << "** INSIRA OS NOVOS DADOS **" << endl;
        cout << "Nome: ";
        cin.ignore();
        getline(cin, nomeProcurado[indice].nome);
        cout << "CPF: ";
        getline(cin, nomeProcurado[indice].cpf); //Verifica se contém a 11 caracteres de números mais os pontos e o hífens
        if (nomeProcurado[indice].cpf.length() != 14) {
            cout << "O CPF deve conter 11 números." << endl; 
        return;
        }
        for(int i=0; i<linhas ; i++){ //Faz a procura em todo o vetor para saber se o CPf já é cadastrado
        if(nomeProcurado[indice].cpf == nomeProcurado[i].cpf){
            cout<< "Esse CPF já existe" << endl;
            return;
        }
    }
        cout << "Tipo Sanguíneo: ";
        getline(cin, nomeProcurado[indice].tipoSanguineo);

        for (size_t i = 0; i < nomeProcurado[indice].tipoSanguineo.length(); ++i) {
            nomeProcurado[indice].tipoSanguineo[i] = toupper(nomeProcurado[indice].tipoSanguineo[i]); //converte os caracteres para maiúsculo
        }
        //Verifica se é um tipo sanguíneo válido
        if (nomeProcurado[indice].tipoSanguineo != "A+" and nomeProcurado[indice].tipoSanguineo != "B+" and nomeProcurado[indice].tipoSanguineo != "AB+" and nomeProcurado[indice].tipoSanguineo != "O+"
        and nomeProcurado[indice].tipoSanguineo != "A-" and nomeProcurado[indice].tipoSanguineo != "B-" and nomeProcurado[indice].tipoSanguineo != "AB-" and nomeProcurado[indice].tipoSanguineo != "O-")
        {
            cout<< "Esse tipo de sangue não existe!" << endl;
            return ;
        }
        
        cout << "Porcentagem de Células Vermelhas: ";
        cin >> nomeProcurado[indice].porcentVermelho;
        cout << "Porcentagem de Células Brancas: ";
        cin >> nomeProcurado[indice].porcentBranco;
        if (nomeProcurado[indice].porcentVermelho + nomeProcurado[indice].porcentBranco <= 100) { //Verifica se a soma das porcentagens de glóbulos brancos e veremlhos não passa de 100
            cout << "A soma das porcentagens de glóbulos vermelhos e brancos deve ser igual ou menor a 100%." << endl;
        return;
        }
        cout << "Densidade: ";
        cin >> nomeProcurado[indice].densidade;

        // Abre o arquivo em modo de escrita
        ofstream arquivo("dados_hemograma.csv");
        if (!arquivo) {
            cout << "Erro ao abrir o arquivo." << endl;
            return;
        }else {

            // Grava os todos os dados junto com o alterado em que se faz um for que transfere todo o vetor de registros para o arquivo dados_hemograma.csv
            //De linhas é subtraido 1 pela variavel i estar sendo usada para percorrer o vetor
            arquivo << "#Nome;CPF;Tipo Sanguineo;Porcentagem branco;Porcentagem veremlho;Densidade\n";
            for (int i = 0; i < linhas-1; i++) {
                arquivo << nomeProcurado[i].nome << ";"
                        << nomeProcurado[i].cpf << ";"
                        << nomeProcurado[i].tipoSanguineo << ";"
                        << nomeProcurado[i].porcentVermelho << ";"
                        << nomeProcurado[i].porcentBranco << ";"
                        << nomeProcurado[i].densidade << endl;
            }
        }
        arquivo.close();

        cout << endl << "Dados alterados com sucesso!" << endl;
    } else {
        cout << "Pessoa não encontrada." << endl;
    }

    string continua;
    cout << "deseja continuar?(responda com sim ou não)"<<endl;
	cin >> continua;
	if (continua == "sim"){
		continuar = true;
	} else {
		continuar = false;
	}
}


//Exclui os dados de uma pessoa escolhida pelo usuário
void excluirpessoa(pessoa nomeProcurado[], bool& continuar, int linhas) {
    bool encontrar = false;
    int indice;
    string cpf;
    cout << "Digite o CPF da pessoa que você deseja excluir (com pontos e traço): ";
    cin >> cpf;

    // Busca pelo CPF digitado no terminal
    cout << "Apagando pessoa..." << endl;
    for (int i = 0; i < linhas and !encontrar; i++) {
        if (cpf == nomeProcurado[i].cpf) {
            encontrar = true;
            indice = i;
        }
    }

    if (encontrar) {
        cout << "** APAGANDO DADOS DO CADASTRO DE " << nomeProcurado[indice].nome << " **" << endl;
        nomeProcurado[indice] = nomeProcurado[linhas - 2]; // moveu o último elemento para a posição do elemento a ser excluído
        linhas--; // Atualiza o número de linhas

        ofstream arquivo("dados_hemograma.csv");
        if (!arquivo) {
            cout << "Erro ao abrir o arquivo." << endl;
            return;
        }

        // regrava os dados atualizados no arquivo
        arquivo << "#Nome;CPF;Tipo sanguineo;Porcentagem branco;Porcentagem vermelho;Densidade\n";
        for (int i = 0; i < linhas-1; i++) {
            arquivo << nomeProcurado[i].nome << ";"
                    << nomeProcurado[i].cpf << ";"
                    << nomeProcurado[i].tipoSanguineo << ";"
                    << nomeProcurado[i].porcentVermelho << ";"
                    << nomeProcurado[i].porcentBranco << ";"
                    << nomeProcurado[i].densidade << endl;
        }
        arquivo.close();

        cout << "Dados excluídos com sucesso!" << endl;
    } else {
        cout << "Pessoa não encontrada." << endl;
    }

    string continua;
    cout << "Deseja continuar? (responda com 'sim' ou 'não'): ";
    cin >> continua;
    if (continua == "sim") {
        continuar = true;
    } else {
        continuar = false;
    }
}



int main() {
    //Coloca acentos no terminal(Apenas em Windows)
    setlocale(LC_ALL, "pt_BR.UTF-8");
    
	int capacidade = 150;
	pessoa *cadastros;
    bool mostrar = false;
    int opcao, linhas;
    bool continuar = true;
    bool leitura_correta = true;
    cadastros = new pessoa[capacidade];
    linhas = mostrartodosdados(cadastros, continuar, mostrar);
       
    
    
    fstream arquivo("dados_hemograma.csv");

    //Testa se o arquivo foi aberto corretamente para sua leitura e continuidade do código
    if (!arquivo) {
        cout << "Erro ao abrir o arquivo!" << endl;
        return 1;
    }else {
        leitura(arquivo, cadastros, linhas, leitura_correta);
    }


    while (leitura_correta and continuar) { //A variavel continuar pode ser alterada em cada um dos subprogramas acessados pelo usuário, de forma que ele possa escolher se deseja continuar utilizando o programa
		for(int i=0; i <=1; i++){ //Esse "for" garante que as opções só serão repetidas uma vez
            cout << "** CADASTRO DE HEMOGRAMA **" << endl;
            cout << "1. Cadastrar nova pessoa" << endl;
            cout << "2. Buscar pessoa" << endl;
            cout << "3. Alterar dados de uma pessoa" << endl;
            cout << "4. Excluir uma pessoa" << endl;
            cout << "5. Mostrar todos os dados" << endl;
            cout << "6. Sair" << endl;
            cout << "Digite a opção desejada: ";
            cin >> opcao;

            //Switch para as opções de respostas
            switch(opcao) {
                case 1: //Adiciona à quantidade de linhas e verifica se está dentro do limite do vetor, se não, faz o cadastro, se seim, faz a realocação primeiro
                    linhas++;
					if(linhas == capacidade)
						realocar(cadastros, capacidade);
                    cadastrarNovaPessoa(continuar, linhas, cadastros);
                    break;
                case 2:
                    buscarpessoa(cadastros, continuar, linhas);
                    break;
                case 3:
                    alterarpessoa(cadastros, linhas, continuar);
                    break;
                case 4:
                    excluirpessoa(cadastros, continuar, linhas);
                    break;
                case 5:
                    mostrar = true;
                    mostrartodosdados(cadastros, continuar, mostrar);
                    break;
                case 6:
                    cout << "Programa encerrado" << endl;
                    return 0;
                default:
                    cout << "Opção inválida" << endl;
                    break;
            }
            if (!continuar){
                    cout<<"Saindo do programa..."<<endl;
                    return 0;
                }
            cout << endl;
        }
    }
    

    arquivo.close();

    return 0;
}