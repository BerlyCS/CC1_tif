#ifndef VENDA_H
#define VENDA_H

#include <iostream>
#include <string>

using namespace std;

class venta {
    private:
        float valor;
        
    public:
        venta(const float = 0.0);
        // virtual ~venta();

        // Getters e Setters

        void setValor(float);
        float getValor() const;
};

#endif