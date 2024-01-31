#include "Funcionario.h"

Funcionario::Funcionario(
    const string nombre, const string usuario, const string contraseña,
    const string funcion, const TipoFuncionario tipo, const float salarioPorHora,
    const Hora& tiempoTrabajo, const Hora& horasPendientes, const vector<Hora*> semana
):  Pessoa(nombre, usuario, contraseña), salarioPorHora(salarioPorHora),
    funcion(funcion), tipo(tipo), tiempoTrabajo(tiempoTrabajo),
    horasPendientes(horasPendientes), semana(semana) {}

void Funcionario::setSalarioPorHora(float salarioPorHora) {
    this->salarioPorHora = salarioPorHora;
}
float Funcionario::getSalarioPorHora() const {
    return salarioPorHora;
}

void Funcionario::settiempoTrabajo(Hora tiempoTrabajo) {
    this->tiempoTrabajo = tiempoTrabajo;
}
Hora Funcionario::gettiempoTrabajo() const {
    return tiempoTrabajo;
}

void Funcionario::sethorasPendientes(Hora horasPendientes) {
    this->horasPendientes = horasPendientes;
}
Hora Funcionario::gethorasPendientes() const {
    return horasPendientes;
}

void Funcionario::setfuncion(string funcion) {
    this->funcion = funcion;
}
const string &Funcionario::getfuncion() const {
    return funcion;
}

void Funcionario::setTipo(TipoFuncionario tipo) {
    this->tipo = tipo;
}
TipoFuncionario Funcionario::getTipo() const {
    return tipo;
}

void Funcionario::setSemana(vector<Hora*> semana) {
    this->semana = semana;
}
vector<Hora*> Funcionario::getSemana() const {
    return semana;
}

bool Funcionario::tempoSemana(vector<Hora*> semana) {
    Hora* tempoTotal = new Hora();
    int horas;

    for(auto dia:semana) {
        cout << "asdfasd" << endl;
        tempoTotal->setHoras(dia->getHoras() + tempoTotal->getHoras());
        tempoTotal->setMinutos(dia->getMinutos() + tempoTotal->getMinutos());
    }


    horas = tempoTotal->getMinutos()/60;
    tempoTotal->setMinutos(tempoTotal->getMinutos()%60);
    tempoTotal->setHoras(tempoTotal->getHoras() + horas);

    cout << tempoTotal->getHoras() << ":" << tempoTotal->getMinutos() << endl;

    return (tempoTotal->getHoras() < 60) || (tempoTotal->getHoras() == 60 && tempoTotal->getMinutos() == 0);
}

bool Funcionario::ponto(Hora inicio, Hora fim, Hora* horasPendientes, int* horasTrabalhado, int* minutosTrabalhado) {
    *horasTrabalhado = fim.getHoras() - inicio.getHoras();
    *minutosTrabalhado = fim.getMinutos() - inicio.getMinutos();

    if (*minutosTrabalhado < 0) {
        *horasTrabalhado--;
        *minutosTrabalhado += 60;
    }

    // Impede que o funcionário trabalhe mais que 10 horas por dia
    if (*horasTrabalhado > 10 || (*horasTrabalhado == 10 && *minutosTrabalhado > 0)) {
        cout << "O funcionário trabalhou mais que 10 horas no dia.\n" << endl;
        cout << "Não será possível cadastrar o ponto.\n" << endl;
        cout << "Tente novamente.\n" << endl;
        return false;
    }

    // Hora horasPendientes = this->gethorasPendientes();

    // Se o funcionário trabalhar mais que 8 horas no dia
    // atribuímos essas horas extras para outra variável
    if (*horasTrabalhado <= 10 && (*horasTrabalhado == 8 && *minutosTrabalhado > 0)) {
        int horasExtras = *horasTrabalhado - 8;
        int minutosExtras = *minutosTrabalhado;

        (*horasPendientes).setHoras((*horasPendientes).getHoras() + horasExtras);
        (*horasPendientes).setMinutos((*horasPendientes).getMinutos() + minutosExtras);

        if ((*horasPendientes).getMinutos() >= 60) {
            (*horasPendientes).setHoras((*horasPendientes).getHoras() + 1);
            (*horasPendientes).setMinutos((*horasPendientes).getMinutos() - 60);
        }
    }

    return true;
}

float Funcionario::calculoSalarioPorHoras(TipoFuncionario tipoFuncionario) {
    int salarioPorHora = this->getSalarioPorHora();
    float multiplicadorHorasExtras;
    Hora tiempoTrabajo = this->gettiempoTrabajo();
    Hora tempoPendentes = this->gethorasPendientes();

    float horasTrabalhado = tiempoTrabajo.getHoras();
    float minutosTrabalhado = tiempoTrabajo.getMinutos();

    int horasPendientes = (tempoPendentes).getHoras();
    int minutosPendentes = (tempoPendentes).getMinutos();
    
    if(tipoFuncionario == TipoFuncionario::Vendedor) multiplicadorHorasExtras = 2.0;
    else multiplicadorHorasExtras = 2.5;

    if(horasPendientes < 0) {
        horasTrabalhado += horasPendientes;
        minutosTrabalhado -= minutosPendentes;
    }
    if(minutosTrabalhado < 0) minutosTrabalhado += minutosPendentes;

    if(horasPendientes > 0) horasTrabalhado += (horasPendientes * multiplicadorHorasExtras);
    if(minutosTrabalhado > 0) minutosTrabalhado += (minutosPendentes * multiplicadorHorasExtras);

    if(minutosTrabalhado >= 60) {
        horasTrabalhado += 1;
        minutosTrabalhado -= 60;
    }

    return horasTrabalhado * salarioPorHora + (minutosTrabalhado * salarioPorHora)/60;
}