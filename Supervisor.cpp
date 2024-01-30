#include "supervisor.h"

// /*
Supervisor::Supervisor(
    const string nombre, const string usuario, const string contraseña,
    const string funcion, const TipoFuncionario tipo, const float salarioPorHora,
    const Hora& tiempoTrabajo, const Hora& horasPendientes,
    const vector<Hora*> semana, const vector<Vendedor*> vendedores
): Funcionario(
        nombre, usuario, contraseña, funcion, tipo, salarioPorHora, tiempoTrabajo, 
        horasPendientes, semana
    ), vendedores(vendedores) {}
// */

void Supervisor::setVendedor(vector<Vendedor*> Vendedor) {
    this->vendedores = Vendedor;
}
vector<Vendedor*> Supervisor::getVendedor() const {
    return this->vendedores;
}

void Supervisor::registrarPunto(Hora inicio, Hora fim) {
    int horasTrabajo, minutosTrabajo;
    Hora horasPendientes = this->gethorasPendientes();
    
    if(!this->punto(inicio, fim, &horasPendientes, &horasTrabajo, &minutosTrabajo)) {
        cout << "No es posible registrar un punto, se ha superado el horario diario" << endl;
        return;
    }

    // Se o funcionário trabalhou menos que 8 horas no dia
    // adicionamos o tempo que ficou faltando nas horas pendentes
    if(horasTrabajo < 8) {
        if(minutosTrabajo != 0) {
            horasPendientes.setHoras(horasPendientes.getHoras() - (7 - horasTrabajo));
            horasPendientes.setMinutos(horasPendientes.getMinutos() - (60 - minutosTrabajo));

            if(horasPendientes.getMinutos() <= -60) {
                horasPendientes.setMinutos(horasPendientes.getMinutos() + 60);
                horasPendientes.setHoras(horasPendientes.getHoras() - 1);
            }
        }
        else horasPendientes.setHoras(horasPendientes.getHoras() - (8 - horasTrabajo));
    }

    // Atribuimos as horas trabalhadas removendo as horas extras
    Hora tiempoTrabajo(horasTrabajo, minutosTrabajo);

    if(semana.size() == 7) {
        if(!this->tiempoSemana(semana)) {
            cout << "Não é possivel registrar punto, excedeu as horas semanais" << endl;
            return;
        } 
        semana.clear();
    }

    this->settiempoTrabajo(tiempoTrabajo);

    cout << "punto cadastrado com sucesso.\n" << endl;

    return;
}

float Supervisor::calcularSalario() {
    return calculoSalarioPorHoras(this->getTipo()) + bonificacion();
}

float Supervisor::bonificacion() {
    float valorTotal = 0.0;

    for(auto i = this->vendedores.begin(); i != this->vendedores.end(); ++i) {
        vector<Venda*> ventas = (*i)->getventas();
        for(auto j = ventas.begin(); j != ventas.end(); ++j)
            valorTotal += (*j)->getValor() * 0.01;
    }
    
    return valorTotal;
}

/*
void Supervisor::adicionarVendedor(Vendedor vendedor) {
    this->vendedores.push_back(vendedor);
}

void Supervisor::listarVendedores() {
    for (auto i = this->vendedores.begin(); i != this->vendedores.end(); ++i)
        cout << (*i).getnombre() << endl;
}
*/