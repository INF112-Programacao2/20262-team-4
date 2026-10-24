#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include<string>

class Animal {
    private: 
        int codigo;
        std::string nome;
        std::string especie;
        std::string raca;
        int idade;
        std::string porte;
        std::string caracteristicaPrincipal;
        std::string status;

    public:
        Animal(int codigo, std::string nome, std::string especie, std::string raca, 
               int idade, std::string porte, std::string caracteristicaPrincipal, std::string status);
        ~Animal();

        std::string getNome() const;
        std::string getEspecie() const;
        std::string getRaca() const;
        int getIdade() const;
        std::string getPorte() const;
        std::string getCaracteristicaPrincipal() const;
        std::string getStatus() const;
        
        void setNome(std::string nome);
        void setEspecie(std::string especie);
        void setRaca(std::string raca);
        void setIdade(int idade);
        void setPorte(std::string porte);
        void setCaracteristicaPrincipal(std::string caracteristica);
        void setStatus(std::string status);

        void forneceDados() const;
};

#endif