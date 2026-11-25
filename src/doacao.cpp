#include "doacao.hpp"
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <string>
#include <iomanip>

int Doacao::codigo = 0;

// Cria o arquivo de histórico caso ele ainda não exista
void CriarHistorico(){
    std::ofstream historico("Historico_Doacoes.txt", std::ios::app);

    if(!historico.is_open())
        throw std::runtime_error("Erro ao criar ou abrir historico de doacoes");

    historico.close();
}

// Atualiza o código com base no maior código registrado no histórico
void AtualizarCodigo(int &codigo){
    // Garante que o arquivo de histórico exista
    CriarHistorico();

    std::ifstream historico("Historico_Doacoes.txt");

    if(!historico.is_open())
        throw std::runtime_error("Erro ao abrir historico de doacoes");

    std::string palavra;
    int codigoLido;

    // Percorre as palavras do arquivo até encontrar "CODIGO:"
    while(historico >> palavra){
        if(palavra == "CODIGO:"){
            // Lê o número que aparece depois de "CODIGO:"
            historico >> codigoLido;

            // Atualiza o código caso encontre um valor maior
            if(codigoLido > codigo)
                codigo = codigoLido;
        }
    }

    // Fecha o arquivo
    historico.close();
}

// Verifica se o arquivo de histórico está vazio
bool HistoricoVazio() {
    // Garante que o arquivo de histórico exista
    CriarHistorico();

    std::ifstream leitura("Historico_Doacoes.txt");

    if (!leitura.is_open())
        throw std::runtime_error("Erro ao abrir historico de doacoes");

    // Posiciona o ponteiro de leitura no final do arquivo
    leitura.seekg(0, std::ios::end);
    
    // Verifica se o arquivo não possui nenhum conteúdo
    if (leitura.tellg() == 0) {
        leitura.close();
        return true;
    }
    leitura.close();

    // Retorna false caso o arquivo possua algum conteúdo
    return false;
}

// Verifica se o valor da doação é válido
void ValidarValor(double &valor){
    while(true){
        try{
            // Lança uma exceção se o valor for <= 0
            if(valor <= 0)
                throw std::invalid_argument("Valor nao pode ser igual a 0 ou negativo");

            break;
        // Captura a exceção, exibe a mensagem e solicita um novo valor
        }catch(const std::invalid_argument &e){
            std::cout << e.what() << std::endl;
            std::cout << "Digite outro valor: ";
            std::cin >> valor;
        }
    }
}

// Verifica se a data da doação foi informada
void ValidarData(std::string &data){
    while(true){
        try{
            // Lança uma exceção caso a data esteja vazia
            if(data.empty())
                throw std::invalid_argument("A data nao pode ser vazia!");

            break;
        // Captura a exceção, exibe a mensagem e solicita uma nova data
        }catch(const std::invalid_argument &e){
            std::cout << e.what() << std::endl;
            std::cout << "Digite outra data: ";
            std::cin >> data;
        }
    }
}

// Verifica se o item da doação foi informado
void ValidarItem(std::string &item){
    while(true){
        try{
            // Lança uma exceção caso o item esteja vazio
            if(item.empty())
                throw std::invalid_argument("O item nao pode ser vazio!");

            break;
        // Captura a exceção, exibe a mensagem e solicita um novo item
        }catch(const std::invalid_argument &e){
            std::cout << e.what() << std::endl;
            std::cout << "Digite outro item: ";
            std::getline(std::cin >> std::ws, item);
        }
    }
}

// Verifica se a quantidade de itens doados é válida
void ValidarQuantidade(int &quantidade){
    while(true){
        try{
            // Lança uma exceção se a quantidade for <= 0
            if(quantidade <= 0)
                throw std::invalid_argument("Quantidade nao pode ser igual a 0 ou negativo");

            break;
        // Captura a exceção, exibe a mensagem e solicita uma nova quantidade
        }catch(const std::invalid_argument &e){
            std::cout << e.what() << std::endl;
            std::cout << "Digite outra quantidade: ";
            std::cin >> quantidade;
        }
    }
}

// Construtor para doações monetárias
Doacao::Doacao(double valor, std::string data) {
    // Verifica se o valor e data inseridos são válidos
    ValidarValor(valor);
    ValidarData(data);

    // Atribui os dados validados aos atributos da classe
    this->valor = valor;
    this->data = data;
    // Inicializa os atributos que não serão utilizados nesta doação
    this->item = "";
    this->quantidade = 0;

    this->monetaria = true;

    // Atualiza o código com base no histórico de doações
    AtualizarCodigo(codigo);

    // Gera o próximo código da doação
    codigo++;
    this->codigoDoacao = codigo;
}

// Construtor para doações materiais
Doacao::Doacao(std::string item, int quantidade, std::string data) {
    // Verifica se o item, a quantidade e a data informados são válidos
    ValidarItem(item);
    ValidarQuantidade(quantidade);
    ValidarData(data);

    // Atribui os dados validados aos atributos da classe
    this->item = item;
    this->quantidade = quantidade;
    this->data = data;

    // Inicializa o atributo que não será utilizado nesta doação
    this->valor = 0;

    this->monetaria = false;

    // Atualiza o código com base no histórico de doações
    AtualizarCodigo(codigo);

    // Gera o próximo código da doação
    codigo++;
    this->codigoDoacao = codigo;
}

// Destrutor da classe Doacao
Doacao::~Doacao() {};

int Doacao::getCodigoDoacao() const {
    return codigoDoacao;
}

double Doacao::getValor() const {
    return valor;
}

std::string Doacao::getData() const {
    return data;
}

std::string Doacao::getItem() const {
    return item;
}

int Doacao::getQuantidade() const {
    return quantidade;
}

// Registra uma nova doação no arquivo de histórico
void Doacao::RegistrarContribuicao() const{
    // Verifica se o arquivo de histórico está vazio
    bool vazio = HistoricoVazio();

    // Abre o arquivo de histórico para adicionar uma nova doação
    std::ofstream historico("Historico_Doacoes.txt", std::ios::app);

    if (!historico.is_open())
        throw std::runtime_error("Erro ao abrir historico de doacoes");

    // Adiciona o título caso o arquivo esteja vazio
    if (vazio) {
        historico << "========== HISTORICO DE DOACOES ==========" << std::endl;
        historico << std::endl;
    }

    historico << "CODIGO: " << std::setw(3) << std::setfill('0') << codigoDoacao << std::endl;

    // Registra as informações específicas de uma doação monetária
    if(monetaria) {
        historico << "TIPO: MONETARIA" << std::endl;
        historico << "VALOR: " << valor << std::endl;
    }

    // Registra as informações específicas de uma doação material
    if(!monetaria) {
        historico << "TIPO: MATERIAL" << std::endl;
        historico << "ITEM: " << item << std::endl;
        historico << "QUANTIDADE: " << quantidade << std::endl;
    }

    historico << "DATA: " << data << std::endl;
    historico << std::endl;
    
    historico.close();

    std::cout << "Doacao registrada com sucesso!" << std::endl;
    
}

// Emite um recibo com as informações da doação
void Doacao::EmitirRecibo() const {
    std::ofstream recibo;
    
    // Cria um arquivo de recibo utilizando o código da doação no nome
    recibo.open("Recibo_Doacao_" + std::to_string(codigoDoacao) + ".txt");

    if(!recibo.is_open())
            throw std::runtime_error("Erro ao criar o recibo de doacoes");

    // Escreve o cabeçalho do recibo
    recibo << "------- RECIBO DA DOACAO -------\n";
    recibo << "CODIGO: " << std::setw(3) << std::setfill('0') << codigoDoacao << std::endl;

    // Escreve as informações de acordo com o tipo da doação
    if(monetaria) {
        recibo << "TIPO: MONETARIA" << std::endl;
        recibo << "VALOR: R$ " << valor << std::endl;
    }

    if(!monetaria) {
        recibo << "TIPO: MATERIAL" << std::endl;
        recibo << "ITEM: " << item << std::endl;
        recibo << "QUANTIDADE: " << quantidade << std::endl;
    }

    recibo << "DATA: " << data << std::endl;
    recibo << "--------------------------------\n";

    recibo.close();

    std::cout << "Recibo emitido com sucesso!" << std::endl;
}

// Exibe o histórico de doações e o total arrecadado
void Doacao::VisualizarHistorico() {
    std::ifstream historico("Historico_Doacoes.txt");

    if (!historico.is_open())
        throw std::runtime_error("Erro ao abrir historico de doacoes");

    std::string linha;

    // Lê e exibe cada linha do arquivo no terminal
    while(std::getline(historico, linha)) {
        std::cout << linha << std::endl;
    }

    historico.close();

    // Abre novamente o arquivo para calcular o total arrecadado
    std::ifstream leitura("Historico_Doacoes.txt");

    if (!leitura.is_open())
        throw std::runtime_error("Erro ao abrir historico de doacoes");

    std::string palavra;
    double valorLido;
    double total = 0;

    // Percorre o arquivo para localizar os valores das doações monetárias
    while(leitura >> palavra) {
        if(palavra == "VALOR:") {
            leitura >> valorLido;
            total += valorLido;
        }
    }

    leitura.close();

   // Exibe o total arrecadado, mesmo que não existam doações monetárias
    std::cout << "\nTotal arrecadado em dinheiro: R$ " << total << std::endl;
}
