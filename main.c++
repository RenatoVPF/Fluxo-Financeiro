/*
Este é o arquivo principal do programa, onde a execução começa. 
Ele é responsável por carregar os usuários do arquivo, apresentar um menu para o usuário escolher entre cadastrar, 
fazer login, listar usuários ou sair, e salvar os usuários de volta no arquivo ao sair.
Ele utiliza as funções definidas em "usuarioService.h" para gerenciar os usuários e "arquivoUtils.h" para lidar com a leitura e escrita dos arquivos.
*/
#include <iostream>
#include <vector>
#include "services/usuarioService.h"
#include "utils/arquivoUtils.h"
#include "modelos/usuarios.h"
#include "modelos/lancamentos.h"
#include "services/lancamentoService.h"


int main() {
    std::vector<Usuario> usuarios;
    std::vector<Lancamento> lancamentos;
    Usuario usuarioLogado;

    // Parte responsável por carregar os usuários do arquivo ao iniciar o programa
    carregarUsuarios(usuarios, "dados/usuarios.txt"); // Ajuste o caminho conforme necessário
    carregarLancamentos(lancamentos, "dados/lancamentos.txt"); // Ajuste o caminho conforme necessário

    // Loop principal do programa, onde o usuário pode escolher entre cadastrar, fazer login, listar usuários ou sair
    int opcao;
    int opcaoUsuario;
    while (1) {
        std::cout << "\n========= BEM VINDO AO FLUXO FINANCEIRO =========\n";
        std::cout << "1. Cadastrar Usuario\n";
        std::cout << "2. Login\n";
        std::cout << "3. Listar Usuarios\n";
        std::cout << "4. Sair\n";
        std::cout << "Escolha: ";
        std::cin >> opcao;

        if (opcao == 4) {
            salvarUsuarios(usuarios, "../dados/usuarios.txt");
            std::cout << "Saindo...\n";
            break;
        }
        else if (opcao == 1) {
            cadastrarUsuario(usuarios);
            salvarUsuarios(usuarios, "../dados/usuarios.txt");
        }
        else if (opcao == 2) {
            if (fazerLogin(usuarios, usuarioLogado)) {
                std::cout << "Bem-vindo, " << usuarioLogado.nome << "!\n";

                // Menu do usuário logado
                while(1){
                    std::cout << "\n=== MENU DO USUÁRIO ===\n";
                    std::cout << "1. Cadastrar Lancamento\n";
                    std::cout << "2. Listar Lancamentos\n";
                    std::cout << "3. Mostrar Resumo Financeiro\n";
                    std::cout << "4. Logout\n";
                    std::cout << "Escolha: ";
                    std::cin >> opcaoUsuario;

                    if(opcaoUsuario == 4){
                        std::cout << "Fazendo logout...\n";
                        break;
                    }
                    else if(opcaoUsuario == 1){
                        cadastrarLancamento(lancamentos, usuarioLogado);
                        salvarLancamentos(lancamentos, "../dados/lancamentos.txt");
                    }
                    else if(opcaoUsuario == 2){
                        listarLancamentos(lancamentos, usuarioLogado);
                    }
                    else if(opcaoUsuario == 3){
                        
                        mostrarResumoFinaceiro(lancamentos, usuarioLogado);
                    }
                    else{
                        std::cout << "Opcao invalida. Tente novamente.\n";
                    }
                }
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