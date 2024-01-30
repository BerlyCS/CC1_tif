#include "venta.h"

venta::venta(const float valor): valor(valor) {}

void venta::setValor(float valor) {
    this->valor = valor;
}
float venta:: getValor() const {
    return this->valor;
}