#ifndef VISITA_HPP
#define VISITA_HPP
#include <string>
#include "animal.hpp"

enum class StatusVisita{
    AGENDADA,
    CONFIRMADA,
    REALIZADA,
    CANCELADA
};

class Visita {
private:
    int _codigo;
    std::string _nomeVisitante;
    std::string _dataVisita;
    std::string _horarioVisita;
    StatusVisita _status;
    Animal* _animal;                  //aponta para Animal, nullptr se for uma visita geral
public:
    //construtor para NOVAS VISITAS criadas no sistema:
    Visita(int codigo, const std::string& nomeVisitante,const std::string& dataVisita, const std::string& horarioVisita, Animal* animal = nullptr);
    //construtor para carregar visitas ja existentes(via arquivo .txt)
    Visita(int codigo, const std::string& nomeVisitante, const std::string& dataVisita, const std::string& horarioVisita, StatusVisita statusInicial, Animal* animal = nullptr);
    //transicoes de estado
    void confirmarAgendamento();
    void cancelarVisita();
    void marcarComoRealizada();

    //getters e setters
    int getCodigo() const;

    std::string getNomeVisitante() const;

    std::string getDataVisita()const;
    void setDataVisita(const std::string& novaData);

    std::string getHorarioVisita()const;
    void setHorarioVisita(const std::string& novoHorario);

    StatusVisita getStatus() const;
    std::string getStatusTexto() const;

    Animal* getAnimal() const;
};

#endif
