#ifndef FUNCIONARIO
#define FUNCIONARIO

#include <iostream>
#include <string>
#include <vector>

#include "persona.h"
#include "hora.h"

using namespace std;

enum class TipoFuncionario { Vendedor, Supervisor };

class Funcionario : public persona {
    private:
        string funcion;
        TipoFuncionario tipo;
    protected:    
        float salarioPorHora;
        Hora tiempoTrabajo;
        Hora horasPendientes;
        vector<Hora*> semana;
    public:
        Funcionario(
            const string = "", const string = "", const string = "",
            const string = "", const TipoFuncionario = TipoFuncionario::Vendedor,
            const float = 0.0, const Hora& = Hora(), const Hora& = Hora(),
            const vector<Hora*> = vector<Hora*>()
        );

        void setSalarioPorHora(float);
        float getSalarioPorHora() const;

        void settiempoTrabajo(Hora);
        Hora gettiempoTrabajo() const;

        void sethorasPendientes(Hora);
        Hora gethorasPendientes() const;

        void setfuncion(string);
        const string &getfuncion() const;
        
        void setTipo(TipoFuncionario);
        TipoFuncionario getTipo() const;

        void setSemana(vector<Hora*>);
        vector<Hora*> getSemana() const;

        virtual void registrarPunto(Hora, Hora) = 0;
        virtual float calcularSalario() = 0;
        virtual float bonificacion() = 0;  

    // private:
        bool ponto(Hora, Hora, Hora*, int*, int*);
        bool tempoSemana(vector<Hora*>);
    // protected:
        float calculoSalarioPorHoras(TipoFuncionario);
};

#endif