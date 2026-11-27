#include "gato.hpp"

Gato::Gato(int codigo, std::string nome, std::string raca, int idade,
           std::string porte, std::string caracteristicaPrincipal,
           std::string status, bool castrado)
    : Animal(codigo, nome, "Gato", raca, idade, porte, caracteristicaPrincipal, status, castrado) {}

Gato::~Gato() {}

void Gato::fornecerDados() const {
    Animal::fornecerDados(); // imprime os dados comuns a todo animal
}