#include "jefe.h"

jefe::jefe(
    const string nombre, const string usuario, const string contraseña,
    const vector<Funcionario*> funcionarios
):  Pessoa(nombre, usuario, contraseña), funcionarios(funcionarios) {}

void jefe::setFuncionarios(vector<Funcionario*> funcionarios) {
    this->funcionarios = funcionarios;
}
vector<Funcionario*> jefe::getFuncionarios() const {
    // return this->funcionarios;
    return this->funcionarios;
}

/*
void jefe::adicionarFuncionario(Funcionario* funcionario) {
    if (funcionario == nullptr) return;
    
    vector<Funcionario*> lista = this->getFuncionarios();
    lista.push_back(funcionario);
    // this->setFuncionarios(lista);
    this->funcionarios = lista;
}

void jefe::listarFuncionarios() {
    // for (auto i = this->funcionarios.begin(); i != this->funcionarios.end(); ++i)
    for (auto funcionario:funcionarios)
        // cout << (*i).getnombre() << endl;
        cout << funcionario->getnombre() << endl;
}
*/





// bool jefe::logar(string usuario, string contraseña) {
//     return (this->getUsuario() == usuario && this->getcontraseña() == contraseña);
// }

/*
bool jefe :: logar(string user, string s){
    return (usuario == user && contraseña == s);
}

void jefe :: cadastrarFuncionario(string nombre, string cargo, double salario, string user, string s){
    if(cargo == "Vendedor"){
        // a class jefe deveria ser friend da Vendedor?
        Vendedor* vendedor = new Vendedor(nombre, salario);
        //adicionar este novo vendedor a lista de funcionarios do jefe
    }else if(cargo == "supervisor"){
        Supervisor* supervisor = new Supervisor(nombre, salario);
        // mesmos questionamentos do primeiro if
    }else {
        cout << "O cargo informado é inválido." << endl;
    }
}
*/