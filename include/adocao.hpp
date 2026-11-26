#ifndef ADOCAO_H_
#define ADOCAO_H_

#include <string>

//declaracoes das classes que "adocao" se relaciona
class Usuario;
class Funcionario;
class Animal;

class Adocao{
private:
    int _codigo;
    std::string _dataSolicitacao;
    std::string _dataAvaliacao;
    std::string _status;
    std::string _justificativa;

    Usuario* _solicitante; // user que solicita adocao
    Funcionario* _avaliador; // funcionario que avalia o processo de adocao
    Animal* _animal; // animal a ser adotado

public:
    Adocao(int codigo); //possui apenas (codigo) pois os demais dados so sao conhecidos posteriormente
                        // e sao preenchidos por outras funcoces
    void registrarSolicitacao(Usuario* usuario, Animal* animal, std::string data);      
    void aprovar(Funcionario* funcionario, std::string data, std::string justificativa);    
    void recusar(Funcionario* funcionario, std::string data, std::string justificativa);    
    void cancelarSolicitacao();

    // GETTERS - nao tem setters pois as informacoes sao definidadas em outros metodos dentro de adocao
    int getCodigo() const;
    std::string getDataSolicitacao() const;
    std::string getDataAvaliacao() const;
    std::string getStatus() const;
    std::string getJustificativa() const;

    Usuario* getSolicitante() const;
    Funcionario* getAvaliador() const;
    Animal* getAnimal() const;

    
};

#endif