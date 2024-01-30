#ifndef SUPERVISOR_H
#define SUPERVISOR_H

#include <iostream>
#include <string>
#include <vector>

#include "funcionario.h"
#include "vendedor.h"
#include "venta.h"

class Supervisor : public Funcionario {
    // friend class Chefe;
    private:
        vector<Vendedor*> vendedores;
        
        float bonificacao() override;
    public:
        Supervisor(
            const string = "", const string = "", const string = "",
            const string = "", const TipoFuncionario = TipoFuncionario::Vendedor,
            const float = 0.0, const Hora& = Hora(), const Hora& = Hora(),
            const vector<Hora*> = vector<Hora*>(),
            const vector<Vendedor*> = vector<Vendedor*>()
        );
        // virtual ~Supervisor();
        
        void setVendedor(vector<Vendedor*>);
        vector<Vendedor*> getVendedor() const;

        void cadastrarPonto(Hora, Hora) override;
        float calcularSalario() override;

        // void adicionarVendedor(Vendedor);
        // void listarVendedores();

// • Exibir salário, em função das horas trabalhadas + bonificações, de forma detalhada.
// • Cadastrar venta.
// • Listar ventas (se for supervisor devem listadas as ventas de todos os vendedores).
// • Retonar a tela inicial.
};
#endif