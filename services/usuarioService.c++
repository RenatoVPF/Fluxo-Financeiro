#include <iostream>
#include <vector>
#include <string>
#include "usuarioService.h"

// Função responsável por cadastrar um novo usuário
void cadastrarUsuario(std::vector<Usuario>& usuarios) {
    Usuario novoUsuario;

    // Exibe título da operação
    std::cout << "\n=== CADASTRO DE USUARIO ===\n";

    // Gera um ID automático:
    // Se o vetor estiver vazio começa em 1,
    // senão pega o último ID e soma +1
    novoUsuario.id = usuarios.empty() ? 1 : usuarios.back().id + 1;

    // Lê o nome do usuário
    std::cout << "Nome: ";
    std::cin.ignore(); // limpa o buffer do teclado
    std::getline(std::cin, novoUsuario.nome);

    // Lê a senha do usuário
    std::cout << "Senha: ";
    std::getline(std::cin, novoUsuario.senha);

    // Adiciona o novo usuário ao vetor
    usuarios.push_back(novoUsuario);

    // Confirmação para o usuário
    std::cout << "Usuario cadastrado com sucesso!\n";
}

// Função responsável por validar login
bool fazerLogin(const std::vector<Usuario>& usuarios, Usuario& usuarioLogado) {
    std::string nome;
    std::string senha;

    std::cout << "\n=== LOGIN ===\n";

    // Lê o nome digitado
    std::cout << "Nome: ";
    std::cin.ignore(); // limpa buffer
    std::getline(std::cin, nome);

    // Lê a senha digitada
    std::cout << "Senha: ";
    std::getline(std::cin, senha);

    // Percorre todos os usuários cadastrados
    for (const Usuario& usuario : usuarios) {

        // Verifica se nome e senha coincidem
        if (usuario.nome == nome && usuario.senha == senha) {

            // Se encontrou, copia os dados para usuarioLogado
            usuarioLogado = usuario;

            std::cout << "Login realizado com sucesso!\n";
            return true;
        }
    }

    // Caso não encontre nenhum usuário válido
    std::cout << "Nome ou senha incorretos.\n";
    return false;
}

// Função que lista todos os usuários cadastrados
void listarUsuarios(const std::vector<Usuario>& usuarios) {

    std::cout << "\n=== LISTA DE USUARIOS ===\n";

    // Verifica se o vetor está vazio
    if (usuarios.empty()) {
        std::cout << "Nenhum usuario cadastrado.\n";
        return;
    }

    // Percorre o vetor exibindo cada usuário
    for (const Usuario& usuario : usuarios) {
        std::cout << "ID: " << usuario.id
                  << " | Nome: " << usuario.nome << "\n";
    }
}