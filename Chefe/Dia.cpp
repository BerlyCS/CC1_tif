#include "dia.h"

Dia::Dia(
    const vector<Hora*> diaDelMes
): diaDelMes(diaDelMes) {}

void Dia::setdiaDelMes(vector<Hora*> diaDelMes) {
    this->diaDelMes = diaDelMes;
}
vector<Hora*> Dia::getdiaDelMes() const {
    return diaDelMes;
}