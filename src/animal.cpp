#include "animal.hpp"
#include "excecoes.hpp"
#include <iostream>

const std::string Animal::DISPONIVEL = "Disponivel.";
const std::string Animal::EM_TRATAMENTO = "Em tratamento.";
const std::string Animal::EM_PROCESSO_ADOCAO = "Em processo de adocao.";
const std::string Animal::ADOTADO = "Adotado.";

Animal::Animal(int codigo, std::string nome, std::string especie, std::string raca,
               int idade, std::string porte, std::string caracteristicaPrincipal,
               std::string status) {
    setCodigo(codigo);
    setNome(nome);
    setEspecie(especie);
    setRaca(raca);
    setIdade(idade);
    setPorte(porte);
    setCaracteristicaPrincipal(caracteristicaPrincipal);
    setStatus(status);
}

Animal::~Animal() {}

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

void Animal::setCodigo(int codigo) {
    if (codigo < 0) {
        throw DadoInvalidoException("Codigo do animal nao pode ser negativo");
    }
    this->codigo = codigo;
}

void Animal::setNome(std::string nome) {
    if (nome.empty()) {
        throw DadoInvalidoException("Nome nao pode ser vazio");
    }
    this->nome = nome;
}

void Animal::setEspecie(std::string especie) {
    if (especie.empty()) {
        throw DadoInvalidoException("Especie nao pode ser vazia");
    }
    this->especie = especie;
}

void Animal::setRaca(std::string raca) {
    if (raca.empty()) {
        throw DadoInvalidoException("Raca nao pode ser vazia");
    }
    this->raca = raca;
}

void Animal::setIdade(int idade) {
    if (idade < 0) {
        throw DadoInvalidoException("Idade nao pode ser negativa");
    }
    this->idade = idade;
}

void Animal::setPorte(std::string porte) {
    if (porte.empty()) {
        throw DadoInvalidoException("Porte nao pode ser vazio");
    }
    this->porte = porte;
}

void Animal::setCaracteristicaPrincipal(std::string caracteristica) {
    if (caracteristica.empty()) {
        throw DadoInvalidoException("Caracteristica principal nao pode ser vazia");
    }
    this->caracteristicaPrincipal = caracteristica;
}

void Animal::setStatus(std::string status) {
    if (!statusValido(status)) {
        throw StatusInvalidoException(status);
    }
    this->status = status;
}

bool Animal::statusValido(const std::string &status) {
    return status == DISPONIVEL || status == EM_TRATAMENTO ||
           status == EM_PROCESSO_ADOCAO || status == ADOTADO;
}

void Animal::fornecerDados() const {
    std::cout << "--- Dados do Animal ---\n"
              << "Codigo: " << codigo << "\n"
              << "Nome: " << nome << "\n"
              << "Especie: " << especie << "\n"
              << "Raca: " << raca << "\n"
              << "Idade: " << idade << " ano(s)\n"
              << "Porte: " << porte << "\n"
              << "Caracteristica Principal: " << caracteristicaPrincipal << "\n"
              << "Status: " << status << "\n"
              << "-----------------------" << std::endl;
}

void Animal::atualizarStatus(std::string novoStatus) {
    setStatus(novoStatus);
}

bool Animal::estaDisponivelParaAdocao() const {
    return status == DISPONIVEL;
}
