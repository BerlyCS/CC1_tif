#ifndef MES_H
#define MES_H

#include <iostream>
#include <vector>

#include "dia.h"

using namespace std;

class Mes{
    private:
        vector<Dia*> mesDelaño;

    protected:
        Mes(vector<Dia*> = vector<Dia*>());

        void setmesDelaño(vector<Dia*>);
        vector<Dia*> getmesDelaño() const;
};

#endif