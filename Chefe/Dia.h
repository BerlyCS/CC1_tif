#ifndef DIA_H
#define DIA_H

#include <iostream>
#include <vector>

#include "hora.h"

using namespace std;

class Dia{
    private:
        vector<Hora*> diaDelMes;

    protected:
        Dia(vector<Hora*> = vector<Hora*>());

        void setdiaDelMes(vector<Hora*>);
        vector<Hora*> getdiaDelMes() const;
};

#endif