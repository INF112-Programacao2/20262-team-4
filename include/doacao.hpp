#ifndef DOACAO_HPP
#define DOACAO_HPP
#include<string>

class Doacao{
    private: 
        static int codigo;
        int codigoDoacao;
        double valor;
        std::string data;

    public:
        Doacao(double valor, std::string data);
        ~Doacao();

        int getCodigoDoacao() const;
        double getValor() const;
        std::string getData() const;

        void EmitirRecibo() const;
};

#endif