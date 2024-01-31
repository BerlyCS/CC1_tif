#ifndef persona_H
#define persona_H

#include <iostream>
#include <string>

using namespace std;

class persona {
    private:
        string nombre;
        string usuario;
        string contraseña;
    public:
        persona(const string = "", const string = "", const string = "");
        // virtual ~persona();

        void setnombre(string);
        string getnombre() const;

        void setUsuario(string);
        const string &getUsuario() const;

        void setcontraseña(string);
        const string &getcontraseña() const;

        bool logar(string, string);
};

#endif