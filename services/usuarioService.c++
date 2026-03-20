#include <iostream>
#include <vector>
#include <string>
#include "usuarioService.h"


void cadastrarUsuario(std::vector<Usuario>& usuarios) {
    Usuario novoUsuario;

    std::cout << "\n=== CADASTRO DE USUARIO ===\n";

    novoUsuario.id = usuarios.empty() ? 1 : usuarios.back().id + 1;

    std::cout << "Nome: ";
    std::cin.ignore();
    std::getline(std::cin, novoUsuario.nome);

    std::cout << "Senha: ";
    std::getline(std::cin, novoUsuario.senha);

    usuarios.push_back(novoUsuario);

    std::cout << "Usuario cadastrado com sucesso!\n";
}

bool fazerLogin(const std::vector<Usuario>& usuarios, Usuario& usuarioLogado) {
    std::string nome;
    std::string senha;

    std::cout << "\n=== LOGIN ===\n";

    std::cout << "Nome: ";
    std::cin.ignore();
    std::getline(std::cin, nome);

    std::cout << "Senha: ";
    std::getline(std::cin, senha);

    for (const Usuario& usuario : usuarios) {
        if (usuario.nome == nome && usuario.senha == senha) {
            usuarioLogado = usuario;
            std::cout << "Login realizado com sucesso!\n";
            return true;
        }
    }

    std::cout << "Nome ou senha incorretos.\n";
    return false;
}

void listarUsuarios(const std::vector<Usuario>& usuarios) {
    std::cout << "\n=== LISTA DE USUARIOS ===\n";

    if (usuarios.empty()) {
        std::cout << "Nenhum usuario cadastrado.\n";
        return;
    }

    for (const Usuario& usuario : usuarios) {
        std::cout << "ID: " << usuario.id
                  << " | Nome: " << usuario.nome << "\n";
    }
}