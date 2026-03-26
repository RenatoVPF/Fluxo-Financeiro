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
void listarLancamentos(const std::vector<Lancamento>& lancamentos, const Usuario& usuarioLogado){

}

float calcularTotaisGanhos(const std::vector<Lancamento>& lancamentos, const Usuario& usuarioLogado){
    
}

float calcularGastosobrifatorios(const std::vector<Lancamento>& lancamentos, const Usuario& usuarioLogado){
    
}

float calcularGastosNaoObrigatorios(const std::vector<Lancamento>& lancamentos, const Usuario& usuarioLogado){
    
}

float calcularSaldoMensal(const std::vector<Lancamento>& lancamentos, const Usuario& usuarioLogado){
    
}

void mostrarResumoFinaceiro(const std::vector<Lancamento>& lancamentos, const Usuario& usuarioLogado){

}
