#include <iostream>
#include <vector>
#include "services/usuarioService.h"
#include "utils/arquivoUtils.h"
#include "modelos/usuarios.h"


int main() {
    std::vector<Usuario> usuarios;
    Usuario usuarioLogado;

    carregarUsuarios(usuarios, "../dados/usuarios.txt");

    int opcao;
    while (1) {
        std::cout << "\n========= BEM VINDO AO FLUXO FINANCEIRO =========\n";
        std::cout << "1. Cadastrar Usuario\n";
        std::cout << "2. Login\n";
        std::cout << "3. Listar Usuarios\n";
        std::cout << "4. Sair\n";
        std::cout << "Escolha: ";
        std::cin >> opcao;

        if (opcao == 4) {
            salvarUsuarios(usuarios, "usuarios.txt");
            std::cout << "Saindo...\n";
            break;
        }
        else if (opcao == 1) {
            cadastrarUsuario(usuarios);
            salvarUsuarios(usuarios, "usuarios.txt");
        }
        else if (opcao == 2) {
            if (fazerLogin(usuarios, usuarioLogado)) {
                std::cout << "Bem-vindo, " << usuarioLogado.nome << "!\n";
            }
        }
        else if (opcao == 3) {
            listarUsuarios(usuarios);
        }
        else {
            std::cout << "Opcao invalida. Tente novamente.\n";
        }
    }

    return 0;
}