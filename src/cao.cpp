#include "cao.hpp"
#include <iostream>

Cao::Cao(int codigo, std::string nome, std::string raca, int idade,
         std::string porte, std::string caracteristicaPrincipal,
         std::string status, bool castrado, bool adestrado)
    : Animal(codigo, nome, "Cao", raca, idade, porte, caracteristicaPrincipal, status, castrado) {
    setAdestrado(adestrado);
}

Cao::~Cao() {}

bool Cao::getAdestrado() const {
    return adestrado;
}

void Cao::setAdestrado(bool adestrado) {
    this->adestrado = adestrado;
}

void Cao::fornecerDados() const {
    Animal::fornecerDados(); // imprime os dados comuns a todo animal
    std::cout << "Adestrado: " << (adestrado ? "Sim" : "Nao") << "\n"
              << "-----------------------" << std::endl;
}
