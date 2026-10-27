#include"animal.hpp"

#include <iostream>
#include <stdexcept>

Animal::Animal(int codigo, std::string nome, std::string especie, std::string raca,
int idade, std::string porte, std::string caracteristicaPrincipal, std::string status) : 
    codigo(codigo),
    nome(nome),
    especie(especie),
    raca(raca),
    idade(idade),
    porte(porte),
    caracteristicaPrincipal(caracteristicaPrincipal),
    status(status) {}

Animal::~Animal() {};

int Animal::getCodigo() const {
    return codigo;
}

std::string Animal::getNome() const {
    return nome;
}

std::string Animal::getEspecie() const {
    return especie;
}

std::string Animal::getRaca() const {
    return raca;
}

int Animal::getIdade() const {
    return idade;
}

std::string Animal::getPorte() const {
    return porte;
}

std::string Animal::getCaracteristicaPrincipal() const {
    return caracteristicaPrincipal;
}

std::string Animal::getStatus() const {
    return status;
}

void Animal::setNome(std::string nome) {
    if (nome.empty()) {
        throw std::invalid_argument("Nome nao pode ser vazio");
    }
    this->nome = nome;
}

void Animal::setEspecie(std::string especie) {
    if (especie.empty()) {
        throw std::invalid_argument("Especie nao pode ser vazia");
    }
    this->especie = especie;
}

void Animal::setRaca(std::string raca) {
    if (raca.empty()) {
        throw std::invalid_argument("Raca nao pode ser vazia");
    }
    this->raca = raca;
}

void Animal::setIdade(int idade) {
    if (idade < 0) {
        throw std::invalid_argument("Idade nao pode ser negativa");
    }
    this->idade = idade;
}

void Animal::setPorte(std::string porte) {
    if (porte.empty()) {
        throw std::invalid_argument("Porte nao pode ser vazio");
    }
    this->porte = porte;
}

void Animal::setCaracteristicaPrincipal(std::string caracteristica) {
    if (caracteristica.empty()) {
        throw std::invalid_argument("Caracteristica principal nao pode ser vazia");
    }
    this->caracteristicaPrincipal = caracteristica;
}

void Animal::setStatus(std::string status) {
    if (status.empty()) {
        throw std::invalid_argument("Status nao pode ser vazio");
    }
    this->status = status;
}

void Animal::fornecerDados() const {
    std::cout << "--- Dados do Animal ---\n"
              << "Código: " << codigo << "\n"
              << "Nome: " << nome << "\n"
              << "Espécie: " << especie << "\n"
              << "Raça: " << raca << "\n"
              << "Idade: " << idade << " ano(s)\n"
              << "Porte: " << porte << "\n"
              << "Característica Principal: " << caracteristicaPrincipal << "\n"
              << "Status: " << status << "\n"
              << "-----------------------" << std::endl;
}