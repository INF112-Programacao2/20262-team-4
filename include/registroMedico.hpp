#ifndef REGISTROMEDICO_HPP
#define REGISTROMEDICO_HPP
#include <string>

class RegistroMedico{
    private: 
        static int codigo;
        int codigoRegistro;
        int codigoAnimal;
        std::string descricaoTratamento;
        std::string data;

    public:
        RegistroMedico(int codigoAnimal, std::string descricaoTratamento, std::string data);
        ~RegistroMedico();

        int getCodigoRegistro() const;
        int getCodigoAnimal() const;
        std::string getDescricaoTratamento() const;
        std::string getData() const;

        void salvarRegistroClinico() const;
        static void exibirRegistro(int codigoAnimal);
};

#endif
