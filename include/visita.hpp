#ifndef VISITA_HPP
#define VISITA_HPP
#include <string>

class Visita {
private:
    int codigo;
    std::string dataVisita;
    std::string horarioVisita;
    std::string status;
public:
    Visita(int codigo, std::string dataVisita, std::string status, std::string horarioVisita);
    ~Visita();
    void confirmarAgendamento();
    void cancelarVisita();
    void marcarComoRealizada();
    void listarHorariosDisponiveis();
    void definirOpcoesPadrao();

    //getters e setters
    int getCodigo() const;
    void setCodigo(int novoCodigo);

    std::string getDataVisita()const;
    void setDataVisita(std::string novaData);

    std::string getHorarioVisita()const;
    void setHorarioVisita(std::string novoHorario);

    std::string getStatus() const;
    void setStatus(std::string novoStatus);
};

#endif
