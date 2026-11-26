#ifndef GATO_HPP
#define GATO_HPP

#include "animal.hpp"

class Gato : public Animal {
    public:
        Gato(int codigo, std::string nome, std::string raca, int idade,
             std::string porte, std::string caracteristicaPrincipal,
             std::string status, bool castrado);
        ~Gato();

        void fornecerDados() const override;
};

#endif