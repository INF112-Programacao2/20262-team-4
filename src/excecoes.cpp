#include "excecoes.hpp"

AbrigoException::AbrigoException(const std::string &mensagem)
    : mensagem(mensagem) {}

AbrigoException::~AbrigoException() noexcept {}

const char* AbrigoException::what() const noexcept {
    return mensagem.c_str();
}

DadoInvalidoException::DadoInvalidoException(const std::string &mensagem)
    : AbrigoException(mensagem) {}

StatusInvalidoException::StatusInvalidoException(const std::string &status)
    : AbrigoException("Status invalido: '" + status +
                      "'. Use: Disponivel, Em tratamento, Em processo de adocao ou Adotado") {}

AnimalIndisponivelException::AnimalIndisponivelException(const std::string &nome)
    : AbrigoException("O animal '" + nome + "' nao esta disponivel para adocao") {}

RegistroNaoEncontradoException::RegistroNaoEncontradoException(const std::string &tipo, int codigo)
    : AbrigoException(tipo + " com codigo " + std::to_string(codigo) + " nao encontrado") {}

LimiteFavoritosException::LimiteFavoritosException(int limite)
    : AbrigoException("Limite de " + std::to_string(limite) + " favoritos atingido") {}