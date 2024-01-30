#include "Vendedor.h"

Vendedor::Vendedor(
    const string nombre, const string usuario, const string contraseña,
    const string funcion, const TipoFuncionario tipo, const float salarioPorHora,
    const Hora& tiempoTrabajo, const Hora& horasPendientes,
    const vector<Hora*> semana, const vector<Venda*> vendas
): Funcionario(
        nombre, usuario, contraseña, funcion, tipo, salarioPorHora, tiempoTrabajo, 
        horasPendientes, semana
    ), vendas(vendas) {}

void Vendedor::setVendas(vector<Venda*> vendas) {
    this->vendas = vendas;
}
vector<Venda*> Vendedor::getVendas() const {
    return this->vendas;
}

void Vendedor::cadastrarPonto(Hora inicio, Hora fim) {
    int horasTrabalhado, minutosTrabalhado;
    Hora horasPendientes = this->gethorasPendientes();
    
    if(!this->ponto(inicio, fim, &horasPendientes, &horasTrabalhado, &minutosTrabalhado)) {
        cout << "Não é possivel registrar ponto, excedeu as horas diarias" << endl;
        return;
    }

    // Se o funcionário trabalhou menos que 8 horas no dia
    // adicionamos o tempo que ficou faltando nas horas pendentes
    if(horasTrabalhado < 8) {
        if(minutosTrabalhado != 0) {
            horasPendientes.setHoras(horasPendientes.getHoras() - (7 - horasTrabalhado));
            horasPendientes.setMinutos(horasPendientes.getMinutos() - (60 - minutosTrabalhado));

            if(horasPendientes.getMinutos() <= -60) {
                horasPendientes.setMinutos(horasPendientes.getMinutos() + 60);
                horasPendientes.setHoras(horasPendientes.getHoras() - 1);
            }
        }
        else horasPendientes.setHoras(horasPendientes.getHoras() - (8 - horasTrabalhado));
    }

    // Atribuimos as horas trabalhadas removendo as horas extras
    horasTrabalhado += this->gettiempoTrabajo().getHoras();
    minutosTrabalhado += this->gettiempoTrabajo().getMinutos();

    if(minutosTrabalhado >= 60) {
        minutosTrabalhado -= 60;
        horasTrabalhado += 1;
    }

    Hora tiempoTrabajo(horasTrabalhado, minutosTrabalhado);
    vector<Hora*> semana = this->getSemana();
    semana.push_back(&tiempoTrabajo);

    cout << semana.size() << endl;

    if(semana.size() == 5 || semana.size() == 6) {
        if(!this->tempoSemana(semana)) {
            cout << "Não é possivel registrar ponto, excedeu as horas semanais" << endl;
            return;
        } 
        semana.clear();
    }

    this->setSemana(semana);
    this->settiempoTrabajo(tiempoTrabajo);

    cout << "Ponto cadastrado com sucesso.\n" << endl;

    return;
}

float Vendedor::calcularSalario() {
    return this->calculoSalarioPorHoras(this->getTipo()) + bonificacao();
}

float Vendedor::bonificacao() {
    float valorTotal = 0.0;

    // for (auto i = this->vendas.begin(); i != this->vendas.end(); ++i)
    for (auto venda:this->getVendas())
        // valorTotal += (*i)->getValor() * 0.1;
        valorTotal += venda->getValor() * 0.1;
    
    return valorTotal;
}

void Vendedor::adicionarVenda(Venda* venda) {
    this->vendas.push_back(venda);
}

/*
void Vendedor::listarVendas() {
    for (auto i = this->vendas.begin(); i != this->vendas.end(); ++i)
        cout << (*i)->getValor() << endl;
}
*/