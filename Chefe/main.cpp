#include "jefe.h"
#include "funcionario.h"
#include "supervisor.h"
#include "vendedor.h"
#include "venda.h"
#include "hora.h"
#include <iostream>
#include <vector>
#include <stdexcept>

//Gabriel Saldanha
//Mariana Macedo
//Gabriel Henrique
//Maria Bessa
//Gustavo Zacarias
//Joao Ramalho



using namespace std;

// /*
// void cadastrarFuncionario(jefe* jefe, vector<Funcionario*> *funcionarios) {
void cadastrarFuncionario(vector<Funcionario*> *funcionarios) {
    string nombre = "", usuario = "", contraseña = "", funcion = "";
    float salarioPorHora = 0;
    int tipoFuncionario = -1;

    Funcionario *funcionario = new Vendedor();
    
    cout << "Introduzca los datos del empleado" << endl;
    cout << "Nombre: ";
    cin.ignore();
    getline(cin, nombre);
    cout << endl << "Usuario: ";
    getline (cin, usuario);
    cout << endl << "Contraseña: ";
    getline (cin, contraseña);
    cout << endl << "Salario por hora: ";
    cin >> salarioPorHora;
    do {
        cout << endl << "Tipo: " << endl << "   0- Vendedor" << endl << "   1- Supervisor" << endl;
        cin >> tipoFuncionario;
        if(tipoFuncionario == 0)
            funcionario = new Vendedor(nombre, usuario, contraseña, funcion, TipoFuncionario::Vendedor, salarioPorHora);
        else if(tipoFuncionario == 1)
            funcionario = new Supervisor(nombre, usuario, contraseña, funcion, TipoFuncionario::Supervisor, salarioPorHora);
        else
            cout << "Informe un t&&o válido" << endl;
    } while(tipoFuncionario != 0 && tipoFuncionario != 1);

    // jefe->adicionarFuncionario(funcionario);
    
    funcionarios->push_back(funcionario);

    // delete funcionario;
}

void Menujefe(jefe *jefe, vector<Funcionario*> *funcionarios) {
    string opcaoStr;
    int opcao = -1;
    bool verifica;
    do {
        verifica = 1; 
        try {
            cout << "---------------------Menu jefe---------------------" << endl;
            cout << "    0- Cadastrar funcionário" << endl;
            cout << "    1- Listar funcionários cadastrados" << endl;
            cout << "    2- Checar ponto" << endl;
            cout << "    3- Calcular salário" << endl;
            cout << "    4- Voltar" << endl;

            cout << "Informe a opção que deseja execultar:" << endl;
            cin >> opcaoStr;
            opcao = stoi(opcaoStr);
        } catch (const invalid_argument& e) {
            cerr << "Erro: Entrada inválida. Digite um número válido." << endl;
            verifica = 0;
        }

        if(verifica){
            switch (opcao) {
                case 0:
                    // Funcionario funcionario = new Funcionario(...dados)
                    // cadastrarFuncionario(jefe, funcionarios);
                    cadastrarFuncionario(funcionarios);
                    // teste2(funcionarios);
                    // teste(funcionarios);
                    break;
                
                case 1:
                    // funcionarios.map((funcionario) => return funcionario.dados)
                    // jefe->listarFuncionarios();
                    // cout << "asdfasd" << endl;
                    // Funcionario *teste = new Funcionario((*jefe).getFuncionarios().begin());
                    // cout << teste->getnombre() << endl;
                    
                    // for(auto funcionario:(*jefe).getFuncionarios()) {
                    for(auto funcionario:(*funcionarios)) {
                        cout << "nombre: " << funcionario->getnombre() << endl;
                    }
                    // teste2(funcionarios);
                    break;
                
                case 2:
                    // Passa por todos os funcionarios e informa os seus dados(nombre, Tempo Trabalhado)
                    for(auto funcionario:(*funcionarios)) {
                        cout << "nombre: " << funcionario->getnombre() << endl;
                        cout << "Tempo Trabalhado: " << funcionario->calcularSalario()/funcionario->getSalarioPorHora() << " horas" << endl;
                    }
                    break;
                
                case 3:
                    // Passa por todos os funcionarios e informa os seus dados(nombre, Salário)
                    
                    
                    for(auto funcionario:(*funcionarios)) {
                        cout << "nombre: " << funcionario->getnombre() << endl;
                        cout << "Salário: " << funcionario->calcularSalario() << "R$" << endl;
                    }
                    break;
                
                case 4:
                    break;
                
                default:
                    cout << "Informe uma opção válida.\n" << endl;
                    break;
            }
        }
    } while(opcao != 4 && verifica != 0);
}

void cadastrarPonto(Funcionario *funcionario) {
    Hora *pontoInicio, *pontoFim;
    int horasPontoInicio, minutosPontoInicio, horasPontoFim, minutosPontoFim;
    
    cout << "Informe as Horas do inicio do ponto: ";
    cin >> horasPontoInicio;
    cout << endl << "Informe os Minutos do inicio do ponto: ";
    cin >> minutosPontoInicio;
    cout << endl << "Informe as Horas do fim do ponto: ";
    cin >> horasPontoFim;
    cout << endl << "Informe os Minutos do fim do ponto: ";
    cin >> minutosPontoFim;

    pontoInicio = new Hora(horasPontoInicio, minutosPontoInicio);
    pontoFim = new Hora(horasPontoFim, minutosPontoFim);

    funcionario->cadastrarPonto(*pontoInicio, *pontoFim);

    cout << funcionario->getTempoTrabalhado().getHoras() << ":" << funcionario->getTempoTrabalhado().getMinutos() << endl;
}

void listarVendas(Vendedor *vendedor) {
    cout << "nombre do vendedor: " << vendedor->getnombre() << endl;
    
    for(auto venda:vendedor->getVendas())
        cout << "Valor Venda: " << venda->getValor() << endl;
}

void MenuFuncionario(Funcionario *funcionario, vector<Funcionario*> *funcionarios) {
    int opcao;
    Vendedor* vendedor = dynamic_cast<Vendedor*>(funcionario);
    vector<Vendedor*> vendedores;
    for(auto func:(*funcionarios))
        vendedores.push_back(dynamic_cast<Vendedor*>(func));
    // Supervisor* supervisor = dynamic_cast<Supervisor*>(funcionario);

    do {
        cout << "------------------Menu Funcionário------------------" << endl;
        cout << "    0- Cadastrar ponto" << endl;
        cout << "    1- Exibir salário" << endl;
        cout << "    2- Cadastrar venda" << endl;
        cout << "    3- Listar vendas" << endl;
        cout << "    4- Voltar para o Menu Inicial" << endl;

        cout << "Informe a opção que deseja execultar:" << endl;
        cin >> opcao;

        switch (opcao) {
            case 0:
                // int horarioChegada, horarioSaida
                // int horasTrabalhada = horarioSaida - horarioChegada
                // funcionario.setPonto(horasTrabalhada)
                cadastrarPonto(funcionario);
                break;
            
            case 1:
                // int salario = calcSalario(funcionario.dados)
                // print salario
                cout << "Salário: " << funcionario->calcularSalario() << "R$" << endl;
                break;
            
            case 2: {
                if(funcionario->getTipo() == TipoFuncionario::Supervisor) {
                    cout << "Apenas Vendedores podem realizar vendas" << endl;  // Trocar por um alerta ou um warning
                    break;
                }

                float valorVenda; // <= adicionar o valor da venda
                Venda* venda = new Venda();

                cout << "Informe o Valor da Venda: ";
                cin >> valorVenda;

                venda->setValor(valorVenda);

                // funcionario.adicionarVenda(venda);
                vendedor->adicionarVenda(venda);

                // delete venda;

                break;
            }

            case 3:
                if(funcionario->getTipo() == TipoFuncionario::Supervisor) {
                    for(auto vendedor:vendedores) {
                        // cout << vendedor.get ->getnombre();
                        listarVendas(vendedor);
                    }            
                    break;
                }
                // if(funcionario.isSupervisor)
                    // supervisor.funcionarios.map((funcionario) => return funcionario.vendas)
                // else
                    // funcionario.vendas
                listarVendas(vendedor);

                break;
            
            case 4:
                break;
            
            default:
                cout << "Informe uma opção válida.\n" << endl;
                break;
        }
    } while(opcao != 4);
}

bool login(jefe *jefe, vector<Funcionario*> *funcionarios, int tipoLogin, string usuario, string contraseña) {
    bool achou = false;
    
    // Procura se o usuario e contraseña existem na lista de jefes
    if(tipoLogin == 0) {
        // Uma maneira de procurar todos os jefes
        // E examinar usuario e contraseña de cada jefe
        achou = jefe->logar(usuario, contraseña);
        if(achou)
            cout << "Logou." << endl;
        else
            cout << "Não logou." << endl;

        // Se achar um jefe q os dados batem c os q foram passados, vamos para a Menu do jefe
        if(achou)
            // Menu jefe
            Menujefe(jefe, funcionarios);
    }
    else {
        // Uma maneira de procurar todos os funcionarios
        // E examinar usuario e contraseña de cada funcionario
        for(auto funcionario:(*funcionarios))
            if(funcionario->logar(usuario, contraseña)) {
                achou = true;
                MenuFuncionario(funcionario, funcionarios);
            }
                
        // Se achar um funcionario q os dados batem c os q foram passados, vamos para a Menu do funcionario
    }

    // Se o jefe/Funcionario conseguiram acessar sua Menu, sera retornado True e voltaremos para o Menu Inicial
    // Se os dados de login n bateram c os q temos armazenados, sera retornado False e voltaremos para o Menu de Login para o usuaro tentar novamente ou voltar manualmente para a o Menu Inicial

    return achou;
}

bool realizarLogin(jefe *jefe, vector<Funcionario*> *funcionarios, int tipoLogin, string usuario, string contraseña) {
    // Se conseguir fazer login
    
    if(login(jefe, funcionarios,tipoLogin, usuario, contraseña)) return true;
    // if(true) return true;
    
    // Se n conseguir fazer login vai exibir mensagem de erro e retornara para a Menu de Login
    cout << "Login inválida.\n" << endl;

    return false;
}

void MenuLogin(jefe *jefe, vector<Funcionario*> *funcionarios) {
    int tipoLogin;
    string usuario, contraseña;
    
    do {
        cout << "-----------------------Login------------------------" << endl;
        cout << "    0- Login jefe" << endl;
        cout << "    1- Login Funcionário" << endl;
        cout << "    2- Voltar ao Menu Inicial" << endl;
        cin >> tipoLogin;

        switch (tipoLogin)
        {
            case 0:
            case 1:
                cout << "Informe o seu usuario:" << endl;
                cin >> usuario;

                cout << "Informe a sua contraseña:" << endl;
                cin >> contraseña;

                // Se n conseguir fazer login retorna para o menu de login
                if(!realizarLogin(jefe, funcionarios,tipoLogin, usuario, contraseña))
                    return;
                break;
            
            case 2:
                cout << "Voltando para a Menu de login:" << endl;
                break;
            
            default:
                break;
        }
    } while(tipoLogin != 2);
}

void MenuInicial(jefe *jefe, vector<Funcionario*> *funcionarios) {
    int opcao;

    do {
        cout << "--------------------Menu Inicial--------------------" << endl;
        cout << "    0- Login" << endl;
        cout << "    1- Sair do menu" << endl;

        cout << "Informe a opção que deseja execultar:" << endl;
        cin >> opcao;

        switch (opcao) {
            case 0:
                MenuLogin(jefe, funcionarios);
                break;
            
            case 1:
                cout << "Finalizando.\n" << endl;
                break;
            
            default:
                cout << "Informe uma opção válida.\n" << endl;
        }
    } while(opcao != 1);
}

jefe* iniciarjefe() {
    string nombre, usuario, contraseña;
    int opcao;

    jefe* jefe;

    cout << "Cadastre o jefe:" << endl;
    cout << "Informe seu nombre: ";
    getline(cin, nombre);
    
    cout << "Quer adicionar Usuario e contraseña?" << endl;
    cout << "   0- Não (se mantem como padrão Usuario = 'admin' e contraseña = 'admin')" << endl;
    cout << "   1- Sim" << endl;
    cin >> opcao;

    if(opcao == 0) jefe = new jefe(nombre);
    else {
        cout << endl << "Usuário: ";
        cin >> usuario;
        cout << endl << "contraseña: ";
        cin >> contraseña;

        jefe = new jefe(nombre, usuario, contraseña);
    }
    
    fflush(stdin);
    cout << "jefe criado com sucesso" << endl << endl;

    return jefe;
}
// */

int main() {
    jefe *jefe;
    vector<Funcionario*> funcionarios;

    jefe = iniciarjefe();
    
    MenuInicial(jefe, &funcionarios);
    
    cout << "Finalizando o programa.\n" << endl;
    // delete jefe, funcionarios;
    
    return 0;
}

