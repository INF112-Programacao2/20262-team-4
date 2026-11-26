#include "visita.hpp"
#include <stdexcept>

Visita::Visita(int Codigo, const std::string& nomeVisitante, const std::string& DataVisita, const std::string& HorarioVisita, Animal* animal): 
_codigo(Codigo), 
_nomeVisitante(nomeVisitante), 
_dataVisita(DataVisita), 
_horarioVisita(HorarioVisita), 
_status(StatusVisita::AGENDADA), 
_animal(animal) 
{
    if(_codigo <= 0){
        throw std::invalid_argument("Codigo de visita invalido.");
    }
    if(_nomeVisitante.size() == 0){
        throw std::invalid_argument("Nome do visitante e obrigatorio.");
    }
    //formato padrao de data (dd/mm/aaaa)
    if(_dataVisita.size() != 10 || _dataVisita[2] != '/' || _dataVisita[5] != '/'){
    throw std::invalid_argument("Data invalida.");
    }
    //forma padrao do horario (XX:XX)
    if(_horarioVisita.size() != 5 || _horarioVisita[2] != ':'){
    throw std::invalid_argument("Horario invalido.");
    }
}

Visita::Visita(int Codigo, const std::string& nomeVisitante, const std::string& DataVisita, const std::string& HorarioVisita, StatusVisita statusInicial, Animal* animal): 
_codigo(Codigo), 
_nomeVisitante(nomeVisitante), 
_dataVisita(DataVisita), 
_horarioVisita(HorarioVisita), 
_status(statusInicial), 
_animal(animal) 
{
    if(_codigo <= 0){
        throw std::invalid_argument("Codigo de visita invalido.");
    }
    if(_nomeVisitante.size() == 0){
        throw std::invalid_argument("Nome do visitante e obrigatorio.");
    }
    //formato padrao de data (dd/mm/aaaa)
    if(_dataVisita.size() != 10 || _dataVisita[2] != '/' || _dataVisita[5] != '/'){
    throw std::invalid_argument("Data invalida.");
    }
    //forma padrao do horario (XX:XX)
    if(_horarioVisita.size() != 5 || _horarioVisita[2] != ':'){
    throw std::invalid_argument("Horario invalido.");
    }
}

void Visita::confirmarAgendamento(){
    if(_status == StatusVisita::REALIZADA){
        throw std::invalid_argument("Nao e possivel confirmar uma visita ja realizada.");
    }
    if(_status == StatusVisita::CANCELADA){
        throw std::invalid_argument("Nao e possivel confirmar uma visita cancelada.");
    }
    _status = StatusVisita::CONFIRMADA;
}

void Visita::cancelarVisita(){
    if(_status == StatusVisita::REALIZADA){
        throw std::invalid_argument("Nao e possivel cancelar uma visita ja realizada.");
    }
    _status = StatusVisita::CANCELADA;
}

void Visita::marcarComoRealizada(){
    if(_status == StatusVisita::CANCELADA){
        throw std::invalid_argument("Nao e possivel marcar como realizada uma visita cancelada.");
    }
    _status = StatusVisita::REALIZADA;
}

int Visita::getCodigo() const{
    return _codigo;
}

std::string Visita::getNomeVisitante() const {
    return _nomeVisitante;
}

std::string Visita::getDataVisita() const {
    return _dataVisita;
}

void Visita::setDataVisita(const std::string& novaData){
    if(_status == StatusVisita::REALIZADA){
        throw std::invalid_argument("Nao e possivel alterar a data de uma visita ja realizada.");
    }
    if(_status == StatusVisita::CANCELADA){
        throw std::invalid_argument("Nao e possivel alterar a data de uma visita cancelada.");
    }
    //formato padrao de data (dd/mm/aaaa)
    if(novaData.size()!= 10 || novaData[2]!= '/' || novaData[5] != '/'){
        throw std::invalid_argument("Data invalida.");
    }

    _dataVisita = novaData;
}


std::string Visita::getHorarioVisita() const{
    return _horarioVisita;
}

void Visita::setHorarioVisita(const std::string& novoHorario){
    if(_status == StatusVisita::REALIZADA){
        throw std::invalid_argument("Nao e possivel alterar o horario de uma visita ja realizada.");
    }
    if(_status == StatusVisita::CANCELADA){
        throw std::invalid_argument("Nao e possivel alterar o horario de uma visita cancelada.");
    }
    //forma padrao do horario (XX:XX)
    if(novoHorario.size() != 5 || novoHorario[2] != ':'){
        throw std::invalid_argument("Horario invalido.");
    }
    _horarioVisita = novoHorario;
}

StatusVisita Visita::getStatus() const {
    return _status;
}

std::string Visita::getStatusTexto() const{
    switch (_status) {
        case StatusVisita::AGENDADA:   return "Agendada";
        case StatusVisita::CONFIRMADA: return "Confirmada";
        case StatusVisita::REALIZADA:  return "Realizada";
        case StatusVisita::CANCELADA:  return "Cancelada";
    }
    return "";
}

Animal* Visita::getAnimal() const{
    return _animal;
}