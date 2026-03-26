#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "lancamentoService.h"


// Função resposavel por fazer o cadastro de um novo lançamento financeiro
void cadastrarLancamento(std::vector<Lancamento>& lancamentos, const Usuario& usuarioLogado){
    Lancamento novoLancamento;
    int escolhaTipo;
    //vai gerar um ID automático para o lançamento, baseado no último ID do vetor
    novoLancamento.id = lancamentos.empty() ? 1 : lancamentos.back().id + 1;
    //atribui o ID do usuário logado ao lançamento, garantindo que cada lançamento esteja associado ao usuário correto
    novoLancamento.idUsuario = usuarioLogado.id;

    std::cout <<"\n ==== Cadastro de Lancamento ====\n";
    std::cout << "\nDescricao: ";
    std::cin.ignore(); //limpa o buffer do teclado
    std::getline(std::cin, novoLancamento.descricao);

    // Escolha do tipo do lançamento
    std::cout << "Tipo do lancamento:\n";
    std::cout << "1 - Ganho\n";
    std::cout << "2 - Gasto obrigatorio\n";
    std::cout << "3 - Gasto nao obrigatorio\n";
    std::cout << "Escolha: ";
    std::cin >> escolhaTipo;

    if(escolhaTipo == 1){
        novoLancamento.tipo = "ganho";
    }
    else if(escolhaTipo == 2){
        novoLancamento.tipo = "obrigatorio";
    }
    else if(escolhaTipo == 3){
        novoLancamento.tipo = "nao_obrigatorio";
    }
    else{
        std::cout << "Opcao invalida. Lancamento nao cadastrado.\n";
        return;
    }

    //Le o valor do lançamento
    std::cout << "Valor: ";
    std::cin >> novoLancamento.valor;

    if(novoLancamento.valor < 0){
        std::cout << "Valor invalido. O valor nao pode ser negativo.\n";
        return;
    }

    //Le o mês do lançamento
    std::cout << "Mes (1-12): ";
    std::cin >> novoLancamento.mes;

    if(novoLancamento.mes < 1 || novoLancamento.mes > 12){
        std::cout << "Mes invalido. O mes deve ser entre 1 e 12.\n";
        return;
    }
    //Le o ano do lançamento
    std::cout << "Ano: ";
    std::cin >> novoLancamento.ano;

    if(novoLancamento.ano < 1900 || novoLancamento.ano > 2100){
        std::cout << "Ano invalido. O ano deve ser entre 1900 e 2100.\n";
        return;
    }

    lancamentos.push_back(novoLancamento);
    std::cout << "Lancamento cadastrado com sucesso!\n";


}

//Função responsavel por listar os lançamentos finaceiros do usuario logado
void listarLancamentos(const std::vector<Lancamento>& lancamentos, const Usuario& usuarioLogado){
    bool encontrou = false; // Variável para verificar se encontrou algum lançamento do usuário logado

    std::cout << "\n==== Lista de lancamentos de "<< usuarioLogado.nome << " ====\n";
    
    // Percorre todos os lançamentos e exibe apenas os que pertencem ao usuário logado
    for(const Lancamento& lancamento : lancamentos){
        // Verifica se o ID do usuário do lançamento corresponde ao ID do usuário logado
        if(lancamento.idUsuario == usuarioLogado.id){
            encontrou =true;

            std::cout << "ID: " << lancamento.id << "\n";
            std::cout << "Descricao: " << lancamento.descricao << "\n";
            std::cout << "Tipo: " << lancamento.tipo << "\n";
            std::cout << "valor: R$ " << std::fixed << std::setprecision(2) << lancamento.valor << "\n";
            std::cout << "Data: " << lancamento.mes << "/" << lancamento.ano << "\n\n";
            
        }
    }

    // Se não encontrou nenhum lançamento do usuário logado, exibe uma mensagem informando isso
    if(!encontrou){
        std::cout << "Nenhum lancamento encontrado para o usuario " << usuarioLogado.nome << ".\n";
    }
}

// Função responsável por calcular o total de ganhos do usuário logado
float calcularTotaisGanhos(const std::vector<Lancamento>& lancamentos, const Usuario& usuarioLogado){
    float totalGanhos= 0.0f;

    for(const Lancamento& lancamento : lancamentos){
        if(lancamento.idUsuario == usuarioLogado.id && lancamento.tipo == "ganho"){
            totalGanhos += lancamento.valor;
        }
    }

    return totalGanhos;
}

float calcularGastosObrigatorios(const std::vector<Lancamento>& lancamentos, const Usuario& usuarioLogado){
    float totalGastosObrigatorios= 0.0f;

    for(const Lancamento& lancamento : lancamentos){
        if(lancamento.idUsuario == usuarioLogado.id && lancamento.tipo == "obrigatorio"){
            totalGastosObrigatorios += lancamento.valor;
        }
    }

    return totalGastosObrigatorios;
    
}

float calcularGastosNaoObrigatorios(const std::vector<Lancamento>& lancamentos, const Usuario& usuarioLogado){
    float totalGastosNaoObrigatorios= 0.0f;

    for(const Lancamento& lancamento : lancamentos){
        if(lancamento.idUsuario == usuarioLogado.id && lancamento.tipo == "nao_obrigatorio"){
            totalGastosNaoObrigatorios += lancamento.valor;
        }
    }

    return totalGastosNaoObrigatorios;
}

// Função responsável por calcular o saldo mensal do usuário logado, subtraindo os gastos dos ganhos
float calcularSaldoMensal(const std::vector<Lancamento>& lancamentos, const Usuario& usuarioLogado){
    float totalGanhos = calcularTotaisGanhos(lancamentos, usuarioLogado);
    float totalGastosObrigatorios = calcularGastosObrigatorios(lancamentos, usuarioLogado);
    float totalGastosNaoObrigatorios = calcularGastosNaoObrigatorios(lancamentos, usuarioLogado);

    return totalGanhos - (totalGastosObrigatorios + totalGastosNaoObrigatorios);
    
}

void mostrarResumoFinaceiro(const std::vector<Lancamento>& lancamentos, const Usuario& usuarioLogado){
    float ganhos = calcularTotaisGanhos(lancamentos, usuarioLogado);
    float obrigatorios = calcularGastosObrigatorios(lancamentos, usuarioLogado);
    float naoObrigatorios = calcularGastosNaoObrigatorios(lancamentos, usuarioLogado);
    float saldo = calcularSaldoMensal(lancamentos, usuarioLogado);

    std::cout << "\n=== RESUMO FINANCEIRO ===\n";
    std::cout << "Usuario: " << usuarioLogado.nome << "\n";
    std::cout << "Ganhos: R$ " << std::fixed << std::setprecision(2) << ganhos << "\n";
    std::cout << "Gastos obrigatorios: R$ " << obrigatorios << "\n";
    std::cout << "Gastos nao obrigatorios: R$ " << naoObrigatorios << "\n";
    std::cout << "Saldo mensal: R$ " << saldo << "\n";
}
