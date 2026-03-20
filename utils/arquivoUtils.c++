#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "arquivoUtils.h"

void salvarUsuarios(const std::vector<Usuario>& usuarios, const std::string& nomeArquivo) {
    std::ofstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        std::cout << "Erro ao abrir o arquivo para salvar usuarios.\n";
        return;
    }

    for (const Usuario& usuario : usuarios) {
        arquivo << usuario.id << ";"
                << usuario.nome << ";"
                << usuario.senha << "\n";
    }

    arquivo.close();
}

void carregarUsuarios(std::vector<Usuario>& usuarios, const std::string& nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        return;
    }

    usuarios.clear();

    std::string linha;
    while (std::getline(arquivo, linha)) {
        std::stringstream ss(linha);
        std::string campo;
        Usuario usuario;

        std::getline(ss, campo, ';');
        usuario.id = std::stoi(campo);

        std::getline(ss, usuario.nome, ';');
        std::getline(ss, usuario.senha, ';');

        usuarios.push_back(usuario);
    }

    arquivo.close();
}