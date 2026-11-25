#ifndef DOACAO_HPP
#define DOACAO_HPP
#include <string>

class Doacao{
    private: 
        static int codigo; // Armazena o último código utilizado nas doações
        int codigoDoacao;
        bool monetaria; // Indica se a doação é monetária ou material
        double valor;
        std::string data;
        std::string item; // Item doado, como alimentos, produtos de limpeza, saúde, conforto e acessórios
        int quantidade; // Quantidade de itens doados

    public:
        // Construtores para os dois tipos de doação
        Doacao(double valor, std::string data);
        Doacao(std::string item, int quantidade, std::string data);

        ~Doacao();

        int getCodigoDoacao() const;
        double getValor() const;
        std::string getData() const;
        std::string getItem() const;
        int getQuantidade() const;

        // Exibe todas as doações registradas e o total arrecadado em dinheiro
        static void VisualizarHistorico();
        
        // Registra a doação no arquivo de histórico 
        void RegistrarContribuicao() const;
        // Emite o recibo
        void EmitirRecibo() const;
};

#endif
