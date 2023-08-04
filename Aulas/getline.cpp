#include <iostream>
using namespace std;

int main(){
    string nome, email;
    int idade;
    getline(cin,nome);
    cin>>email;
    cin >> idade;
    cout << "Nome: " << nome << endl;
    cout << "Email: " << email << endl;
    cout << "Idade: " << idade << endl;

    return 0;
}