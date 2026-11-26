#include <iostream>
#include "adocao.hpp"
#include "animal.hpp"
#include "excecoes.hpp"
#include <stdexcept>

Adocao::Adocao(int codigo) : _codigo(codigo), _status("Nao registrado"), _solicitante(nullptr), 
                            _avaliador(nullptr), _animal(nullptr) {}

// guarda quem solicitou, qual animal, data da solicitacao e muda o status para pendente
void Adocao::registrarSolicitacao(Usuario* usuario, Animal* animal, std::string data){
    if(usuario==nullptr)
        throw std::invalid_argument("Usuario nao pode ser nulo.");
    if(animal==nullptr)
        throw std::invalid_argument("Animal nao pode ser nulo.");
    if(data.empty())
        throw std::invalid_argument("Data da solicitacao nao pode ser vazia.");
    if(_status!= "Nao registrado")
        throw AdocaoOperacaoInvalidaException("registrar a solicitacao de", _status);
    if(!animal->estaDisponivelParaAdocao())
        throw AnimalIndisponivelException(animal->getNome());
    
    _solicitante=usuario;
    _animal=animal;
    _dataSolicitacao=data;
    _status="Pendente";
    _animal->atualizarStatus(Animal::EM_PROCESSO_ADOCAO);

}

// funcionario aprova o pedido de adocao. Muda o status de adocao e marca o status do animal (adotado)
void Adocao::aprovar(Funcionario* funcionario, std::string data, std::string justificativa){
    if(funcionario==nullptr)
        throw std::invalid_argument("Funcionario nao pode ser nulo.");
    if(data.empty())
        throw std::invalid_argument("Data da avaliacao nao pode ser vazia.");
    if(_status!= "Pendente")
        throw AdocaoOperacaoInvalidaException("aprovar", _status);
    if(_animal->getStatus()!=Animal::EM_PROCESSO_ADOCAO)
        throw AnimalIndisponivelException(_animal->getNome());
    
    _avaliador=funcionario;
    _dataAvaliacao=data;
    _justificativa=justificativa;
    _status="Aprovada";

    _animal->atualizarStatus(Animal::ADOTADO);

}


// funcionario recusa o pedido de adocao. Muda status DA ADOCAO para "Recusada" e altera o status DO ANIMAL para disponivel
void Adocao::recusar(Funcionario* funcionario, std::string data, std::string justificativa){
    if(funcionario==nullptr)
        throw std::invalid_argument("Funcionario nao pode ser nulo.");
    if(data.empty())
        throw std::invalid_argument("Data da avaliacao nao pode ser vazia.");
    if(_status!= "Pendente")
        throw AdocaoOperacaoInvalidaException("recusar", _status);
    if(_animal->getStatus()!=Animal::EM_PROCESSO_ADOCAO)
        throw AnimalIndisponivelException(_animal->getNome());

    _avaliador=funcionario;
    _dataAvaliacao=data;
    _justificativa=justificativa;
    _status="Recusada";

    _animal->atualizarStatus(Animal::DISPONIVEL);

}

void Adocao::cancelarSolicitacao(){
    if(_status != "Pendente"){
        throw AdocaoOperacaoInvalidaException("cancelar", _status);
    }
    if(_animal->getStatus()!=Animal::EM_PROCESSO_ADOCAO)
        throw AnimalIndisponivelException(_animal->getNome());

    _status="Cancelada";
    _animal->atualizarStatus(Animal::DISPONIVEL);
}

// GETTERS

int Adocao::getCodigo() const{
    return _codigo;
}

std::string Adocao::getDataSolicitacao() const{
    return _dataSolicitacao;
}
std::string Adocao::getDataAvaliacao() const{
    return _dataAvaliacao;
}
std::string Adocao::getStatus() const {
    return _status;
}
std::string Adocao::getJustificativa() const{
    return _justificativa;
}
Usuario* Adocao::getSolicitante() const{
    return _solicitante;
}
Funcionario* Adocao::getAvaliador() const{
    return _avaliador;
}
Animal* Adocao::getAnimal() const{
    return _animal;
}