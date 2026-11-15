#include "visita.hpp"
#include <iostream>

Visita::Visita(int Codigo, std::string DataVisita, std::string Status, std::string HorarioVisita): codigo(Codigo), dataVisita(DataVisita), status(Status), horarioVisita(HorarioVisita) {}

void Visita::confirmarAgendamento(){
    status = "Confirmada.";
    std::cout << "A visita" << codigo << " foi confirmada. \n";
}

void Visita::cancelarVisita(){
    status = "Cancelada.";
    std::cout << "A visita " << codigo << " foi cancelada.\n";
}

void Visita::marcarComoRealizada(){
    status = "Realizada";
    std::cout << "A visita " << codigo <<" foi marcada como realizada.\n";
}

int Visita::getCodigo() const{
    return codigo;
}

void Visita::setCodigo(int novoCodigo){
    codigo = novoCodigo;
}

std::string Visita::getDataVisita() const {
    return dataVisita;
}

void Visita::setDataVisita(std::string novaData){
    dataVisita = novaData;
}

std::string Visita::getHorarioVisita() const {
    return horarioVisita;
}

void Visita::setHorarioVisita(std::string novoHorario){
    horarioVisita = novoHorario;
}

std::string Visita::getStatus() const {
    return status;
}

void Visita::setStatus(std::string novoStatus){
    status = novoStatus;
}

Visita::~Visita(){}