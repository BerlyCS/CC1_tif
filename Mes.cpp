#include "mes.h"

Mes::Mes(
    const vector<Dia*> mesDelaño
): mesDelaño(mesDelaño) {}

void Mes::setmesDelaño(vector<Dia*> mesDelaño) {
    this->mesDelaño = mesDelaño;
}
vector<Dia*> Mes::getmesDelaño() const {
    return mesDelaño;
}