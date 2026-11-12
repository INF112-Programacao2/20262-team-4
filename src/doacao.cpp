#include "doacao.hpp"

#include <stdexcept>

int Doacao::codigo = 0;

void ValidarValor(double &valor){
    while(true){
        try{
            if(valor <= 0)
                throw std::invalid_argument("Valor nao pode ser igual a 0 ou negativo");

            break;
        }catch(std::invalid_argument &e){
            std::cout << e.what() << std::endl;
            std::cout << "Digite outro valor: ";
            std::cin >> valor;
        }
    }
}

void ValidarData(std::string &data){
    while(true){
        try{
            if(data.empty())
                throw std::invalid_argument("Data nao pode ser vazia");

            break;
        }catch(std::invalid_argument &e){
            std::cout << e.what() << std::endl;
            std::cout << "Digite outra data: ";
            std::cin >> data;
        }
    }
}

Doacao::Doacao(double valor, std::string data) {
        ValidarValor(valor);
        ValidarData(data);

        this->valor = valor;
        this->data = data;
        this->codigoDoacao = codigo;
        codigo++;
    }

Doacao::~Doacao() {};

int Doacao::getCodigoDoacao() const {
    return codigoDoacao;
}

double Doacao::getValor() const {
    return valor;
}

std::string Doacao::getData() const {
    return data;
}

void Doacao::EmitirRecibo() const{
    std::cout << "------- RECIBO DA DOACAO -------\n";
    std::cout << "CODIGO: " <<  codigoDoacao << std::endl;
    std::cout << "VALOR: " <<  valor << std::endl;
    std::cout << "DATA: " <<  data << std::endl;
    std::cout << "--------------------------------\n";
}