#include "persona.h"

persona::persona(
    const string nombre, const string usuario, const string contraseña
): nombre(nombre), usuario(usuario), contraseña(contraseña) {}

void persona::setnombre(string nombre) {
    this->nombre = nombre;
}
string persona::getnombre() const {
    return nombre;
}

void persona::setUsuario(string usuario) {
    this->usuario = usuario;
}
const string &persona::getUsuario() const {
    return usuario;
}

void persona::setcontraseña(string contraseña) {
    this->contraseña = contraseña;
}
const string &persona::getcontraseña() const {
    return contraseña;
}

bool persona::logar(string usuario, string contraseña) {
    return (this->getUsuario() == usuario && this->getcontraseña() == contraseña);
}