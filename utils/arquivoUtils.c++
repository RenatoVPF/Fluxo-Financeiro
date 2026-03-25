#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "arquivoUtils.h"

// Função responsável por salvar os usuários no arquivo
void salvarUsuarios(const std::vector<Usuario>& usuarios, const std::string& nomeArquivo) {

    // Abre o arquivo para escrita (sobrescreve o conteúdo)
    std::ofstream arquivo(nomeArquivo);

    // Verifica se abriu corretamente
    if (!arquivo.is_open()) {
        std::cout << "Erro ao abrir o arquivo para salvar usuarios.\n";
        return;
    }

    // Percorre todos os usuários e salva no formato:
    // id;nome;senha
    for (const Usuario& usuario : usuarios) {
        arquivo << usuario.id << ";"
                << usuario.nome << ";"
                << usuario.senha << "\n";
    }

    // Fecha o arquivo
    arquivo.close();
}

// Função responsável por carregar os usuários do arquivo
void carregarUsuarios(std::vector<Usuario>& usuarios, const std::string& nomeArquivo) {

    // Abre o arquivo para leitura
    std::ifstream arquivo(nomeArquivo);

    // Se não existir arquivo, simplesmente retorna
    if (!arquivo.is_open()) {
        return;
    }

    // Limpa o vetor antes de carregar novamente
    usuarios.clear();

    std::string linha;

    // Lê linha por linha do arquivo
    while (std::getline(arquivo, linha)) {

        std::stringstream ss(linha);
        std::string campo;
        Usuario usuario;

        // Lê o ID (até encontrar ;)
        std::getline(ss, campo, ';');
        usuario.id = std::stoi(campo); // converte string para inteiro

        // Lê o nome
        std::getline(ss, usuario.nome, ';');

        // Lê a senha
        std::getline(ss, usuario.senha, ';');

        // Adiciona o usuário ao vetor
        usuarios.push_back(usuario);
    }

    // Fecha o arquivo
    arquivo.close();
}