#ifndef EXCECOES_HPP
#define EXCECOES_HPP

#include <exception>
#include <string>

// classe base de todas as excecoes do sistema do abrigo
class AbrigoException : public std::exception {
    protected:
        std::string mensagem;

    public:
        explicit AbrigoException(const std::string &mensagem);
        virtual ~AbrigoException() noexcept;
        virtual const char* what() const noexcept override;
};

// dado de entrada invalido 
class DadoInvalidoException : public AbrigoException {
    public:
        explicit DadoInvalidoException(const std::string &mensagem);
};

// status que nao faz parte dos status permitidos para o animal
class StatusInvalidoException : public AbrigoException {
    public:
        explicit StatusInvalidoException(const std::string &status);
};

// operacao pedida para um animal que nao esta disponivel
class AnimalIndisponivelException : public AbrigoException {
    public:
        explicit AnimalIndisponivelException(const std::string &nome);
};

// busca por um codigo que nao existe
class RegistroNaoEncontradoException : public AbrigoException {
    public:
        explicit RegistroNaoEncontradoException(const std::string &tipo, int codigo);
};

// usuario tentou favoritar mais animais do que o permitido 
class LimiteFavoritosException : public AbrigoException {
    public:
        explicit LimiteFavoritosException(int limite);
};

#endif