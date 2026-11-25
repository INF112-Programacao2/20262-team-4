#include "registroMedico.hpp"
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <string>
#include <iomanip>

// Inicializa o contador de códigos da classe
int RegistroMedico::codigo = 0;

// Cria o arquivo de histórico caso ele ainda não exista
void CriarHistoricoMedico(){
    std::ofstream historico("Historico_Registro_Medico.txt", std::ios::app);

    if(!historico.is_open())
        throw std::runtime_error("Erro ao criar ou abrir historico de Registros Medicos");

    historico.close();
}

// Atualiza o código com base no maior código registrado no histórico
void AtualizarCodigoMedico(int &codigo){
    // Garante que o arquivo de histórico exista
    CriarHistoricoMedico();

    std::ifstream historico("Historico_Registro_Medico.txt");

    if(!historico.is_open())
        throw std::runtime_error("Erro ao abrir historico de Registros Medicos");

    std::string palavra;
    int codigoLido;

    // Percorre o arquivo procurando os códigos dos registros
    while(historico >> palavra){
        if(palavra == "CODIGO:"){
            // Lê o número que aparece depois de "CODIGO:"
            historico >> codigoLido;

            // Atualiza o código caso encontre um valor maior
            if(codigoLido > codigo)
                codigo = codigoLido;
        }
    }

    historico.close();
}

// Verifica se o arquivo de histórico está vazio
bool HistoricoMedicoVazio() {
    // Garante que o arquivo de histórico exista
    CriarHistoricoMedico();

    std::ifstream leitura("Historico_Registro_Medico.txt");

    if (!leitura.is_open())
        throw std::runtime_error("Erro ao abrir historico de Registros Medicos");

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

// Verifica se a descrição do tratamento é válida
void ValidarDescricao(std::string &descricaoTratamento){
    while(true){
        try{
            // Lança uma exceção se a descrição do tratamento for vazia
            if(descricaoTratamento.empty())
                throw std::invalid_argument("A descricao do tratamento nao pode ser vazia");

            break;
        // Captura a exceção, exibe a mensagem e solicita uma nova descrição do tratamento
        }catch(const std::invalid_argument &e){
            std::cout << e.what() << std::endl;
            std::cout << "Digite outra descricao: ";
            std::getline(std::cin >> std::ws, descricaoTratamento);
        }
    }
}

// Verifica se a data foi informada
void ValidarDataRegistro(std::string &data){
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

// Construtor da classe RegistroMedico
RegistroMedico::RegistroMedico(int codigoAnimal, std::string descricaoTratamento, std::string data) {
    // Verifica se a descrição e a data são válidas
    ValidarDescricao(descricaoTratamento);
    ValidarDataRegistro(data);

    // Atribui os dados aos atributos da classe
    this->codigoAnimal = codigoAnimal;
    this->descricaoTratamento = descricaoTratamento;
    this->data = data;

    // Atualiza o código com base no histórico de registros médicos
    AtualizarCodigoMedico(codigo);

    // Gera o próximo código do registro médico
    codigo++;
    this->codigoRegistro = codigo;
}

// Destrutor da classe RegistroMedico
RegistroMedico::~RegistroMedico() {};

int RegistroMedico::getCodigoRegistro() const {
    return codigoRegistro;
}

int RegistroMedico::getCodigoAnimal() const{
    return codigoAnimal;
}

std::string RegistroMedico::getDescricaoTratamento() const {
    return descricaoTratamento;
}

std::string RegistroMedico::getData() const {
    return data;
}

// Salva um novo registro médico no arquivo de histórico
void RegistroMedico::salvarRegistroClinico() const{
    // Verifica se o arquivo de histórico está vazio
    bool vazio = HistoricoMedicoVazio();

    // Abre o arquivo de histórico para adicionar um novo registro médico
    std::ofstream historico("Historico_Registro_Medico.txt", std::ios::app);

    if (!historico.is_open())
        throw std::runtime_error("Erro ao abrir historico de Registros Medicos");

    // Adiciona o título caso o arquivo esteja vazio
    if (vazio) {
        historico << "========== HISTORICO DE REGISTROS MEDICOS ==========" << std::endl;
        historico << std::endl;
    }

    // Registra os dados do atendimento
    historico << "CODIGO: " << std::setw(3) << std::setfill('0') << codigoRegistro << std::endl;
    historico << "CODIGO ANIMAL: " << std::setw(3) << std::setfill('0') << codigoAnimal << std::endl;
    historico << "DATA: " << data << std::endl;
    historico << "DESCRICAO: " << descricaoTratamento << std::endl;
    historico << std::endl;

    // Fecha o arquivo
    historico.close();
    std::cout << "Registro medico salvo com sucesso!" << std::endl;
}

// Exibe os registros médicos de um animal específico
void RegistroMedico::exibirRegistro(int codigoAnimal){
    std::ifstream arquivo("Historico_Registro_Medico.txt");

    if(!arquivo.is_open())
        throw std::runtime_error("Erro ao abrir historico de Registros Medicos");

    std::string palavra;
    int codigoLido;
    int codigoAnimalLido;
    std::string dataLida;
    std::string tratamentoLido;

    bool encontrou = false;

    // Percorre o arquivo procurando os registros médicos
    while(arquivo >> palavra){
        if(palavra == "CODIGO:"){
            // Armazena o código do registro médico
            arquivo >> codigoLido;

            // Lê e armazena o código do animal
            arquivo >> palavra; // CODIGO
            arquivo >> palavra; // ANIMAL:
            arquivo >> codigoAnimalLido;

            // Lê e armazena a data do atendimento
            arquivo >> palavra; // DATA:
            arquivo >> dataLida;

            // Lê a descrição do tratamento
            arquivo >> palavra; // DESCRICAO:
            std::getline(arquivo, tratamentoLido);

            // Verifica se o registro pertence ao animal procurado
            if(codigoAnimalLido == codigoAnimal){
                encontrou = true;

                std::cout << "\nCODIGO: " << std::setw(3) << std::setfill('0') << codigoLido << std::endl;
                std::cout << "CODIGO ANIMAL: " << codigoAnimalLido << std::endl;
                std::cout << "DATA: " << dataLida << std::endl;
                std::cout << "DESCRICAO:" << tratamentoLido << std::endl;
            }
        }
    }
    // Fecha o arquivo
    arquivo.close();

    // Informa caso nenhum registro tenha sido encontrado
    if(!encontrou){
        std::cout << "Nenhum registro medico encontrado para este animal." << std::endl;
    }
}
