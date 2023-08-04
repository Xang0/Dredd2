#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
using namespace std;

// Declaração dos campos do registro
struct pessoa
{
    char nome[21];
    char cpf[15];
    char tipoSanguineo[4];
    int porcentVermelho;
    int porcentBranco;
    float densidade;
};

// Realoca os dados do vetor de registros para um outro maior
void realocar(pessoa cadastros[], int &capacidade)
{
    pessoa *novo = new pessoa[capacidade + 10];
    copy(cadastros, cadastros + capacidade, novo);
    delete[] cadastros;
    capacidade += 10;
    cadastros = novo;
}


// Função para fazer o merge
void merge(pessoa cadastro[], int esquerda, int meio, int direita)
{
    int i, j, k;
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;
    // Vetores alocados dinamicamente para guardar as metades
    pessoa *L = new pessoa[n1];
    pessoa *R = new pessoa[n2];

    for (i = 0; i < n1; i++)
        L[i] = cadastro[esquerda + i];
    for (j = 0; j < n2; j++)
        R[j] = cadastro[meio + 1 + j];

    i = 0;
    j = 0;
    k = esquerda;
    //Compara os vetores e vai realizando as trocas
    while (i < n1 && j < n2)
    {
        bool comparou = false;
        int comparando = 0;
        for (int d = 0; d < 15; d++)
        {
            if (L[i].cpf[d] != R[j].cpf[d] and !comparou)
            {
                comparando = L[i].cpf[d] - R[j].cpf[d];
                comparou = true;
            }
        }
        if (comparando <= 0)
        {
            cadastro[k] = L[i];
            i++;
        }
        else
        {
            cadastro[k] = R[j];
            j++;
        }
        k++;
    }
    // Copia os que restarem, caso houver
    while (i < n1)
    {
        cadastro[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        cadastro[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(pessoa cadastro[], int esquerda, int direita)
{
    // Condição de parada
    if (esquerda >= direita)
    {
        return;
    }

    int meio = esquerda + (direita - esquerda) / 2;
    // Chama a função para primeira metade
    mergeSort(cadastro, esquerda, meio);
    // Agora para a segunda
    mergeSort(cadastro, meio + 1, direita);
    // Faz o merge mudando as posições caso necessário.
    merge(cadastro, esquerda, meio, direita);
}

int leitura(ifstream &arquivo, pessoa cadastros[])
{
    int registros = 0;
    // Lê os dados do arquivo como char e conta mais um na variavel registros a cada passagem da quantidade de bits igual a quantidade de bits da struct pessoa
    while (arquivo.read(reinterpret_cast<char *>(&cadastros[registros]), sizeof(pessoa)))
    {
        registros++;
    }

    // Volta o estado de leitura do arquivo para o começo e o fecha
    arquivo.clear();
    arquivo.seekg(0, std::ios::beg);
    arquivo.close();

    return registros;
}

// Mostra todos os Dados cadastrados
void mostrartodosdados(pessoa cadastros[], bool &continuar, int linhas)
{

    cout << endl
         << "** Hemogramas Cadastrados **" << endl;
    for (int i = 1; i < linhas - 1; i++)
    {
        // Exibe os dados na tela
        cout << "Nome: " << cadastros[i].nome << endl;
        cout << "CPF: " << cadastros[i].cpf << endl;
        cout << "Tipo sanguineo: " << cadastros[i].tipoSanguineo << endl;
        cout << "Porcentagem de globulos vermelhos: " << cadastros[i].porcentVermelho << "%" << endl;
        cout << "Porcentagem de globulos brancos: " << cadastros[i].porcentBranco << "%" << endl;
        cout << "Densidade do sangue: " << cadastros[i].densidade << endl;
        cout << endl;
    }

    char continua;
    bool aux = true;
    cout << "deseja continuar?(responda com S ou N)" << endl;
    while (aux)
    {
        cin >> continua;
        switch (continua)
        {
        case 'S':
            continuar = true;
            aux = false;
            break;
        case 'N':
            continuar = false;
            aux = false;
            break;
        default:
            cout << "Digite uma resposta válida." << endl;
            aux = true;
            break;
        }
    }
}

void cadastrarNovaPessoa(bool &continuar, int &linhas, pessoa cadastros[]) {
    pessoa novaPessoa;

    cout << " CADASTRO DE PESSOA " << endl;
    cout << "Nome: " << endl;
    cin.ignore();
    cin.getline(novaPessoa.nome, sizeof(novaPessoa.nome));
    cout << novaPessoa.nome << endl;

    cout << "CPF com '.' e '-': " << endl;
    cin.getline(novaPessoa.cpf, sizeof(novaPessoa.cpf));
    if (strlen(novaPessoa.cpf) != 14) {
        cout << "O CPF deve conter 11 números." << endl;
        return;
    }
    for (int i = 0; i < linhas; i++) {
        if (strcmp(novaPessoa.cpf, cadastros[i].cpf) == 0) {
            cout << "Esse CPF já existe" << endl;
            return;
        }
    }

    cout << "Tipo Sanguineo: " << endl;
    cin.getline(novaPessoa.tipoSanguineo, sizeof(novaPessoa.tipoSanguineo));
    for (unsigned i = 0; i < strlen(novaPessoa.tipoSanguineo); ++i) {
        novaPessoa.tipoSanguineo[i] = toupper(novaPessoa.tipoSanguineo[i]);
    }
    if (strcmp(novaPessoa.tipoSanguineo, "A+") != 0 && strcmp(novaPessoa.tipoSanguineo, "B+") != 0 &&
        strcmp(novaPessoa.tipoSanguineo, "AB+") != 0 && strcmp(novaPessoa.tipoSanguineo, "O+") != 0 &&
        strcmp(novaPessoa.tipoSanguineo, "A-") != 0 && strcmp(novaPessoa.tipoSanguineo, "B-") != 0 &&
        strcmp(novaPessoa.tipoSanguineo, "AB-") != 0 && strcmp(novaPessoa.tipoSanguineo, "O-") != 0) {
        cout << "Esse tipo de sangue não existe!" << endl;
        return;
    }

    cout << "Porcentagem de Globulos Vermelhos: " << endl;
    cin >> novaPessoa.porcentVermelho;
    cout << "Porcentagem de Globulos Brancos: " << endl;
    cin >> novaPessoa.porcentBranco;
    if (novaPessoa.porcentVermelho + novaPessoa.porcentBranco > 100) {
        cout << "A soma das porcentagens de glóbulos vermelhos e brancos deve ser igual ou menor a 100%." << endl;
        return;
    }

    cout << "Densidade do sangue: " << endl;
    cin >> novaPessoa.densidade;

    //Passa os novos dados para depois do último cadastrado e faz o ordenação do vetor de registros 
    cadastros[linhas-2] = novaPessoa;
    mergeSort(cadastros, 0, linhas - 1);
    fstream binario("dados_hemograma.bin", ios::binary | ios::in | ios::out);
    if (!binario) {
        cout << "Erro ao abrir o arquivo binário" << endl;
        return;
    }


    binario.seekg(0, ios::end);
    
    binario.write((char*)&novaPessoa, sizeof(pessoa));
    
    binario.close();
    cout << "Cadastro realizado!" << endl;

    char continua;
    bool aux = true;
    cout << "Deseja continuar? (responda com S ou N)" << endl;
    while (aux) {
        cin >> continua;
        switch (continua) {
            case 'S':
                continuar = true;
                aux = false;
                break;
            case 'N':
                continuar = false;
                aux = false;
                break;
            default:
                cout << "Digite uma resposta válida." << endl;
                aux = true;
                break;
        }
    }
}

// Busca os dados de uma pessoa pelo CPF
int binaria(pessoa nomeProcurado[], int inicio, int fim, string procurado, bool &continuar, bool &encontrar){
    if (inicio <= fim){
        int meio = (inicio+fim)/2;
        if (procurado > nomeProcurado[meio].cpf)
            return binaria(nomeProcurado, meio+1, fim, procurado, continuar, encontrar);
        else if (procurado < nomeProcurado[meio].cpf)
            return binaria(nomeProcurado, inicio, meio-1, procurado, continuar, encontrar);
        else if(procurado == nomeProcurado[meio].cpf){
            encontrar=true;
            return meio;
        }
        else
            cout<< "CPF não encontrado" << endl;
    }
    return -1;
}
// Busca os dados de uma pessoa pelo CPF
void buscarpessoa(pessoa nomeProcurado[], int inicio, int fim, bool& continuar){
	bool encontrar = false;
    int indice;
	string procurado;
	cout<< "Digite o CPF, com . e -, da pessoa a ser buscada: ";
	cin>>procurado;

    //Faz a busca no vetor de registros pelo CPF digitado
    cout << "Buscando CPF... " << endl;

    indice = binaria(nomeProcurado, inicio, fim, procurado, continuar, encontrar); //Chama a função binaria para fazer a busca
    

    if (encontrar) { //Se encontrar o CPF, dá saída, se não, mostra que não foi encontrado
		cout << "** PESSOA ENCONTRADA **" << endl;
        cout << "Nome: " << nomeProcurado[indice].nome << endl;
        cout << "CPF: " << nomeProcurado[indice].cpf << endl;
        cout << "Tipo Sanguineo: " << nomeProcurado[indice].tipoSanguineo << endl;
        cout << "Porcentagem Globulos Vermelhos: " << nomeProcurado[indice].porcentVermelho <<"%"<< endl;
        cout << "Porcentagem Globulos Brancos: " << nomeProcurado[indice].porcentBranco <<"%"<< endl;
        cout << "Densidade do Sangue: " << nomeProcurado[indice].densidade << endl;
    }

    char continua;
    bool aux = true;
    cout << "deseja continuar?(responda com S ou N)" << endl;
    while (aux)
    {
        cin >> continua;
        switch (continua)
        {
        case 'S':
            continuar = true;
            aux = false;
            break;
        case 'N':
            continuar = false;
            aux = false;
            break;
        default:
            cout << "Digite uma resposta válida." << endl;
            aux = true;
            break;
        }
    }

}

// Altera os dados de alguma pessoa escolhida pelo usuário
void alterarpessoa(pessoa nomeProcurado[], int linhas, bool &continuar) {
    bool encontrar = false;
    int indice;
    string cpf;

    cout << "Digite o CPF da pessoa que você deseja alterar (com pontos e traço): ";
    cin.ignore();
    getline(cin, cpf);

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

        //atualizando os dados
        cout << endl << "** INSIRA OS NOVOS DADOS **" << endl;
        cout << "Nome: ";
        cin.getline(nomeProcurado[indice].nome, sizeof(nomeProcurado[indice].nome));

        cout << "CPF: ";
        cin.getline(nomeProcurado[indice].cpf, sizeof(nomeProcurado[indice].cpf));
        
        for(int i=0; i<linhas; i++){
            if(nomeProcurado[indice].cpf == nomeProcurado[i].cpf){
                if(i!=(indice))
                {
                    cout<< "Ja existe esse cpf." << endl;
                    return;
                }
            }
        }
        cout << "Tipo Sanguíneo: ";
        cin.getline(nomeProcurado[indice].tipoSanguineo, sizeof(nomeProcurado[indice].tipoSanguineo));

        cout << "Porcentagem de Células Vermelhas: ";
        cin >> nomeProcurado[indice].porcentVermelho;

        cout << "Porcentagem de Células Brancas: ";
        cin >> nomeProcurado[indice].porcentBranco;

        cout << "Densidade: ";
        cin >> nomeProcurado[indice].densidade;

        //Após alterado os dados desejados, o vetor de registros é ordenado novamente
        mergeSort(nomeProcurado, 0, linhas - 1);

        // Abrindo o arquivo
        ofstream binario("dados_hemograma.bin", ios::binary | ios::out);
        if (!binario) {
            cout << "Erro ao abrir o arquivo binário" << endl;
            return;
        }

        binario.clear();
        binario.write((char*)nomeProcurado, sizeof(pessoa) * linhas);

        binario.close();
        cout << endl << "Dados alterados com sucesso!" << endl;
    } else {
        cout << "Pessoa não encontrada." << endl;
    }

    char continua;
    bool aux = true;
    cout << "Deseja continuar? (responda com S ou N)" << endl;
    while (aux) {
        cin >> continua;
        switch (continua) {
            case 'S':
                continuar = true;
                aux = false;
                break;
            case 'N':
                continuar = false;
                aux = false;
                break;
            default:
                cout << "Digite uma resposta válida." << endl;
                aux = true;
                break;
        }
    }
}
// Exclui os dados de uma pessoa escolhida pelo usuário
void excluirpessoa(pessoa nomeProcurado[], bool &continuar, int &linhas)
{
    int indice = 0;
    string cpf;
    cout << "Digite o CPF da pessoa que você deseja excluir (com pontos e traço): ";
    cin >> cpf;
    cout << endl;

    // Busca pelo CPF digitado no terminal
    cout << "Procurando pessoa..." << endl
         << endl;
    for (int i = 0; i < linhas and indice == 0; i++)
    {
        if (cpf == nomeProcurado[i].cpf)
        {
            indice = i;
        }
    }

    if (indice == 0)
    {
        cout << "Pessoa não encontrada" << endl;

        char continua;
        bool aux = true;
        cout << "deseja continuar?(responda com S ou N)" << endl;
        while (aux)
        {
            cin >> continua;
            switch (continua)
            {
            case 'S':
                continuar = true;
                aux = false;
                break;
            case 'N':
                continuar = false;
                aux = false;
                break;
            default:
                cout << "Digite uma resposta válida." << endl;
                aux = true;
                break;
            }
        }
    }
    else
    {
        cout << "** APAGANDO DADOS DO CADASTRO DE " << nomeProcurado[indice].nome << " **" << endl
             << endl;
        nomeProcurado[indice] = nomeProcurado[linhas - 3]; // moveu o último elemento para a posição do elemento a ser excluído
        linhas--;                                          // Atualiza o número de linhas

        //Após excluído o cadastro desejado, o vetor de registros é ordenado novamente
        mergeSort(nomeProcurado, 0, linhas - 1);

        ofstream binario("dados_hemograma.bin");
        if (not(binario.is_open()))
        {
            cout << "Erro ao abrir o arquivo." << endl
                 << endl;

            char continua;
            bool aux = true;
            cout << "deseja continuar?(responda com S ou N)" << endl;
            while (aux)
            {
                cin >> continua;
                switch (continua)
                {
                case 'S':
                    continuar = true;
                    aux = false;
                    break;
                case 'N':
                    continuar = false;
                    aux = false;
                    break;
                default:
                    cout << "Digite uma resposta válida." << endl;
                    aux = true;
                    break;
                }
            }

            return;
        }
        else
        {
            // regrava os dados atualizados no arquivo
            binario.clear();
            binario.write((char *)nomeProcurado, sizeof(pessoa) * linhas);
            binario.close();

            cout << "Dados excluídos com sucesso!" << endl
                 << endl;

            char continua;
            bool aux = true;
            cout << "deseja continuar?(responda com S ou N)" << endl;
            while (aux)
            {
                cin >> continua;
                switch (continua)
                {
                case 'S':
                    continuar = true;
                    aux = false;
                    break;
                case 'N':
                    continuar = false;
                    aux = false;
                    break;
                default:
                    cout << "Digite uma resposta válida." << endl;
                    aux = true;
                    break;
                }
            }
        }
    }
}

int main()
{
    // Coloca acentos no terminal(Apenas em Windows)
    setlocale(LC_ALL, "pt_BR.UTF-8");

    int capacidade = 110;
    pessoa *cadastros;
    int opcao, linhas;
    bool continuar = true;
    bool leitura_correta = true;
    cadastros = new pessoa[capacidade];
   
    // Abre o arquivo dados_hemograma.bin e verifica se foi aberto corretamente

    ifstream arquivo("dados_hemograma.bin", ios::binary);
    if (!arquivo.is_open())
    {
        cout << "Erro ao abrir ao arquivo" << endl;
        return 0;
    }
    
    // Faz a leitura dos dados do arquivo binário e faz a contagem de cadastros para ser usado ao longo do código
    linhas = leitura(arquivo, cadastros);
    mergeSort(cadastros, 0, linhas - 1);

    while (leitura_correta and continuar)
    { // A variavel continuar pode ser alterada em cada um dos subprogramas acessados pelo usuário, de forma que ele possa escolher se deseja continuar utilizando o programa
        for (int i = 0; i <= 1; i++)
        { // Esse "for" garante que as opções só serão repetidas uma vez
            cout << "** CADASTRO DE HEMOGRAMA **" << endl;
            cout << "1. Cadastrar nova pessoa" << endl;
            cout << "2. Buscar pessoa" << endl;
            cout << "3. Alterar dados de uma pessoa" << endl;
            cout << "4. Excluir uma pessoa" << endl;
            cout << "5. Mostrar todos os dados" << endl;
            cout << "6. Sair" << endl;
            cout << "Digite o número da opção desejada: ";
            cin >> opcao;

            // Switch para as opções de respostas
            switch (opcao)
            {
            case 1: // Adiciona à quantidade de linhas e verifica se está dentro do limite do vetor, se não, faz o cadastro, se seim, faz a realocação primeiro
                linhas++;
                if (linhas == capacidade)
                    realocar(cadastros, capacidade);
                cadastrarNovaPessoa(continuar, linhas, cadastros);
                break;
            case 2:
                buscarpessoa(cadastros, 0, linhas-1, continuar);
                break;
            case 3:
                alterarpessoa(cadastros, linhas, continuar);
                break;
            case 4:
                excluirpessoa(cadastros, continuar, linhas);
                break;
            case 5:
                mostrartodosdados(cadastros, continuar, linhas);
                break;
            case 6:
                cout << "Programa encerrado" << endl;
                return 0;
            default:
                cout << "Opção inválida" << endl;
                break;
            }
            if (!continuar)
            {
                cout << endl
                     << "Saindo do programa..." << endl;
                return 0;
            }
            cout << endl;
        }
    }
}