#ifndef CAO_HPP
#define CAO_HPP

#include "animal.hpp"

class Cao : public Animal {
    private:
        bool adestrado;

    public:
        Cao(int codigo, std::string nome, std::string raca, int idade,
            std::string porte, std::string caracteristicaPrincipal,
            std::string status, bool adestrado);
        ~Cao();

        bool getAdestrado() const;
        void setAdestrado(bool adestrado);

        void fornecerDados() const override;
};

#endif