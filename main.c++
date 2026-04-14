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
#include "utils/arvoreLancamentos.h"
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

    ordenarLancamentosPorArvore(lancamentos); // Ordena os lançamentos por data usando a árvore binária

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
            salvarLancamentos(lancamentos, "../dados/lancamentos.txt");
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
                    std::cout << "\n===== MENU DO USUARIO =====\n";
                    std::cout << "1 - Cadastrar lancamento\n";
                    std::cout << "2 - Listar meus lancamentos\n";
                    std::cout << "3 - Mostrar resumo atual\n";
                    std::cout << "4 - Mostrar resumo de um mes especifico\n";
                    std::cout << "5 - Mostrar resumo de um periodo\n";
                    std::cout << "6 - Editar lancamento\n";
                    std::cout << "7 - Excluir lancamento\n";
                    std::cout << "8 - Logout\n";
                    std::cout << "Escolha: ";
                    std::cin >> opcaoUsuario;

                    int mes, ano, mesInicial, anoInicial, mesFinal, anoFinal;


                   if (opcaoUsuario == 1) {
                        cadastrarLancamento(lancamentos, usuarioLogado);
                        ordenarLancamentosPorArvore(lancamentos);
                        salvarLancamentos(lancamentos, "../dados/lancamentos.txt");
                    }
                    else if (opcaoUsuario == 2) {
                        listarLancamentos(lancamentos, usuarioLogado);
                    }
                    else if (opcaoUsuario == 3) {
                        mostrarResumoFinanceiroAtual(lancamentos, usuarioLogado);
                    }
                    else if (opcaoUsuario == 4) {
                        std::cout << "Informe o mes: ";
                        std::cin >> mes;

                        std::cout << "Informe o ano: ";
                        std::cin >> ano;

                        if (mes < 1 || mes > 12) {
                            std::cout << "Mes invalido.\n";
                        }
                        else {
                            mostrarResumoFinanceiroPeriodo(lancamentos, usuarioLogado, mes, ano, mes, ano);
                        }
                    }
                    else if (opcaoUsuario == 5) {
                        std::cout << "Informe o mes inicial: ";
                        std::cin >> mesInicial;

                        std::cout << "Informe o ano inicial: ";
                        std::cin >> anoInicial;

                        std::cout << "Informe o mes final: ";
                        std::cin >> mesFinal;

                        std::cout << "Informe o ano final: ";
                        std::cin >> anoFinal;

                        if (mesInicial < 1 || mesInicial > 12 || mesFinal < 1 || mesFinal > 12) {
                            std::cout << "Mes invalido.\n";
                        }
                        else {
                            int dataInicial = anoInicial * 12 + mesInicial;
                            int dataFinal = anoFinal * 12 + mesFinal;

                            if (dataInicial > dataFinal) {
                                std::cout << "Periodo invalido. A data inicial nao pode ser maior que a data final.\n";
                            }
                            else {
                                mostrarResumoFinanceiroPeriodo(lancamentos, usuarioLogado, mesInicial, anoInicial, mesFinal, anoFinal);
                            }
                        }
                    }
                    else if (opcaoUsuario == 6) {

                        editarLancamento(lancamentos, usuarioLogado);

                        ordenarLancamentosPorArvore(lancamentos);

                        salvarLancamentos(lancamentos, "../dados/lancamentos.txt");
                    }
                    else if (opcaoUsuario == 7) {

                        excluirLancamento(lancamentos, usuarioLogado);

                        ordenarLancamentosPorArvore(lancamentos);
                        
                        salvarLancamentos(lancamentos, "../dados/lancamentos.txt");
                    }
                    else if (opcaoUsuario == 8) {
                        std::cout << "Logout realizado.\n";
                        break;
                    }
                    else {
                        std::cout << "Opcao invalida.\n";
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