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

    std::cout << "Data do lancamento:\n";
    std::cout << "Dia (1-31): ";
    std::cin >> novoLancamento.dia;

    if(novoLancamento.dia < 1 || novoLancamento.dia > 31){
        std::cout << "Dia invalido. O dia deve ser entre 1 e 31.\n";
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
    //Adiciona o novo lançamento ao vetor de lançamentos
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

//Função responsável por verificar se um lançamento está dentro de um período
bool estaDentroDoPeriodo(const Lancamento& lancamento, int mesInicial, int anoInicial, int mesFinal, int anoFinal){
    // Para comparar as datas, convertemos o mês e o ano em um único valor (ano * 12 + mês), o que facilita a comparação
    int dataLancamento = lancamento.ano * 12 + lancamento.mes;
    int dataInicial = anoInicial * 12 + mesInicial;
    int dataFinal = anoFinal * 12 + mesFinal;

    return dataLancamento >= dataInicial && dataLancamento <= dataFinal;
}

bool obterPeriodoMaisRecente(const std::vector<Lancamento>& lancamentos, const Usuario& usuarioLogado, int& mesMaisRecente, int& anoMaisRecente){
   
    bool encontrou = false;

    int maiorData = 0;

    for(const Lancamento& lancamento : lancamentos){
        
        // Verifica se o lançamento pertence ao usuário logado
        if (lancamento.idUsuario == usuarioLogado.id) {

            // Converte a data do lançamento para facilitar a comparação
            int dataAtual = lancamento.ano * 12 + lancamento.mes;

            // Se ainda não encontrou nenhum lançamento
            // ou se a data atual for mais recente, atualiza
            if (!encontrou || dataAtual > maiorData) {
                encontrou = true;
                maiorData = dataAtual;
                mesMaisRecente = lancamento.mes;
                anoMaisRecente = lancamento.ano;
            }
        }
    }
    return encontrou;
}

// Função responsável por calcular o total de ganhos do usuário logado
float calcularTotaisGanhosPeriodo(const std::vector<Lancamento>& lancamentos, const Usuario& usuarioLogado, int mesInicial, int anoInicial, int mesFinal, int anoFinal){
    float totalGanhos= 0.0f;

    for(const Lancamento& lancamento : lancamentos){
        if(lancamento.idUsuario == usuarioLogado.id && lancamento.tipo == "ganho" && estaDentroDoPeriodo(lancamento, mesInicial, anoInicial, mesFinal, anoFinal)){
            totalGanhos += lancamento.valor;
        }
    }

    return totalGanhos;
}

float calcularGastosObrigatoriosPeriodo(const std::vector<Lancamento>& lancamentos, const Usuario& usuarioLogado, int mesInicial, int anoInicial, int mesFinal, int anoFinal){
    float totalGastosObrigatorios= 0.0f;

    for(const Lancamento& lancamento : lancamentos){
        if(lancamento.idUsuario == usuarioLogado.id && lancamento.tipo == "obrigatorio" && estaDentroDoPeriodo(lancamento, mesInicial, anoInicial, mesFinal, anoFinal)){
            totalGastosObrigatorios += lancamento.valor;
        }
    }

    return totalGastosObrigatorios;
    
}

float calcularGastosNaoObrigatoriosPeriodo(const std::vector<Lancamento>& lancamentos, const Usuario& usuarioLogado, int mesInicial, int anoInicial, int mesFinal, int anoFinal){
    float totalGastosNaoObrigatorios= 0.0f;

    for(const Lancamento& lancamento : lancamentos){
        if(lancamento.idUsuario == usuarioLogado.id && lancamento.tipo == "nao_obrigatorio" && estaDentroDoPeriodo(lancamento, mesInicial, anoInicial, mesFinal, anoFinal)){
            totalGastosNaoObrigatorios += lancamento.valor;
        }
    }

    return totalGastosNaoObrigatorios;
}

// Função responsável por calcular o saldo mensal do usuário logado, subtraindo os gastos dos ganhos
float calcularSaldoMensalPeriodo(const std::vector<Lancamento>& lancamentos, const Usuario& usuarioLogado, int mesInicial, int anoInicial, int mesFinal, int anoFinal){
    float totalGanhos = calcularTotaisGanhosPeriodo(lancamentos, usuarioLogado, mesInicial, anoInicial, mesFinal, anoFinal);
    float totalGastosObrigatorios = calcularGastosObrigatoriosPeriodo(lancamentos, usuarioLogado, mesInicial, anoInicial, mesFinal, anoFinal);
    float totalGastosNaoObrigatorios = calcularGastosNaoObrigatoriosPeriodo(lancamentos, usuarioLogado, mesInicial, anoInicial, mesFinal, anoFinal);

    return totalGanhos - (totalGastosObrigatorios + totalGastosNaoObrigatorios);
    
}

int calcularQuantidadeMesesPeriodo(int mesInicial, int anoInicial, int mesFinal, int anoFinal){

    int dataInicial = anoInicial * 12 + mesInicial;
    int dataFinal = anoFinal * 12 + mesFinal;
    // +1 para incluir o mês inicial no cálculo
    return dataFinal - dataInicial + 1; 

}

float calcularMediaGastosObrigatoriosPeriodo(const std::vector<Lancamento>& lancamentos, const Usuario& usuarioLogado, int mesInicial, int anoInicial, int mesFinal, int anoFinal){
    // Calcula o total de gastos obrigatórios no período
    float totalObrigatorios = calcularGastosObrigatoriosPeriodo(lancamentos, usuarioLogado, mesInicial, anoInicial, mesFinal, anoFinal);
    // Calcula a quantidade de meses no período
    int quantidadeMeses = calcularQuantidadeMesesPeriodo(mesInicial, anoInicial, mesFinal, anoFinal);

    // Evita divisão por zero
    if (quantidadeMeses <= 0) {
        return 0.0f;
    }
    // Retorna a média mensal de gastos obrigatórios
    return totalObrigatorios / quantidadeMeses;

}

// Função responsável por calcular a reserva mínima recomendada para o periodo de 3 meses
float calcularReservaMinimaPeriodo(const std::vector<Lancamento>& lancamentos, const Usuario& usuarioLogado, int mesInicial, int anoInicial, int mesFinal, int anoFinal){
    // A reserva mínima recomendada é geralmente considerada como 3 vezes os gastos obrigatórios mensais
    float mediaGastosObrigatorios = calcularMediaGastosObrigatoriosPeriodo(lancamentos, usuarioLogado, mesInicial, anoInicial, mesFinal, anoFinal);
    return mediaGastosObrigatorios * 3;

}

// Função responsável por calcular a reserva ideal recomendada para o periodo de 6 meses
float calcularReservaIdealPeriodo(const std::vector<Lancamento>& lancamentos, const Usuario& usuarioLogado, int mesInicial, int anoInicial, int mesFinal, int anoFinal){
    // A reserva ideal recomendada é geralmente considerada como 6 vezes os gastos obrigatórios mensais
    float mediaGastosObrigatorios = calcularMediaGastosObrigatoriosPeriodo(lancamentos, usuarioLogado, mesInicial, anoInicial, mesFinal, anoFinal);
    return mediaGastosObrigatorios * 6;
}

// Função responsável por calcular a reserva reforçada recomendada para o periodo de 12 meses
float calcularReservaReforcadaPeriodo(const std::vector<Lancamento>& lancamentos, const Usuario& usuarioLogado, int mesInicial, int anoInicial, int mesFinal, int anoFinal){
    // A reserva reforçada recomendada é geralmente considerada como 12 vezes os gastos obrigatórios mensais
    float mediaGastosObrigatorios = calcularMediaGastosObrigatoriosPeriodo(lancamentos, usuarioLogado, mesInicial, anoInicial, mesFinal, anoFinal);
    return mediaGastosObrigatorios * 12;
}

// Função responsável por listar os lançamentos do usuário logado dentro de um período específico
void listarLancamentosPeriodo(const std::vector<Lancamento>& lancamentos, const Usuario& usuarioLogado, int mesInicial, int anoInicial, int mesFinal, int anoFinal){
    bool encontrou = false;

    std::cout << "\n=== LANCAMENTOS DO PERIODO ===\n";
    std::cout << "Usuario: " << usuarioLogado.nome << "\n";
    std::cout << "Periodo: " << mesInicial << "/" << anoInicial
              << " ate " << mesFinal << "/" << anoFinal << "\n\n";

    for (const Lancamento& lancamento : lancamentos) {
        if (lancamento.idUsuario == usuarioLogado.id &&
            estaDentroDoPeriodo(lancamento, mesInicial, anoInicial, mesFinal, anoFinal)) {

            encontrou = true;

            std::cout << "ID: " << lancamento.id << "\n";
            std::cout << "Descricao: " << lancamento.descricao << "\n";
            std::cout << "Tipo: " << lancamento.tipo << "\n";
            std::cout << "Valor: R$ " << std::fixed << std::setprecision(2) << lancamento.valor << "\n";
            std::cout << "Mes/Ano: " << lancamento.mes << "/" << lancamento.ano << "\n\n";
        }
    }

    if (!encontrou) {
        std::cout << "Nenhum lancamento encontrado para este periodo.\n";
    }
}
// Função responsável por mostrar o resumo financeiro do usuário logado em um período específico, incluindo ganhos, gastos e recomendações de reserva de emergência
void mostrarResumoFinanceiroPeriodo(const std::vector<Lancamento>& lancamentos, const Usuario& usuarioLogado, int mesInicial, int anoInicial, int mesFinal, int anoFinal){
    float ganhos = calcularTotaisGanhosPeriodo(lancamentos, usuarioLogado, mesInicial, anoInicial, mesFinal, anoFinal);
    float gastosObrigatorios = calcularGastosObrigatoriosPeriodo(lancamentos, usuarioLogado, mesInicial, anoInicial, mesFinal, anoFinal);
    float gastosNaoObrigatorios = calcularGastosNaoObrigatoriosPeriodo(lancamentos, usuarioLogado, mesInicial, anoInicial, mesFinal, anoFinal);
    float saldo = calcularSaldoMensalPeriodo(lancamentos, usuarioLogado, mesInicial, anoInicial, mesFinal, anoFinal);

    float mediaObrigatorios = calcularMediaGastosObrigatoriosPeriodo(lancamentos, usuarioLogado, mesInicial, anoInicial, mesFinal, anoFinal);
    float reservaMinima = calcularReservaMinimaPeriodo(lancamentos, usuarioLogado, mesInicial, anoInicial, mesFinal, anoFinal);
    float reservaIdeal = calcularReservaIdealPeriodo(lancamentos, usuarioLogado, mesInicial, anoInicial, mesFinal, anoFinal);
    float reservaReforcada = calcularReservaReforcadaPeriodo(lancamentos, usuarioLogado, mesInicial, anoInicial, mesFinal, anoFinal);

    std::cout << "\n=== RESUMO FINANCEIRO DO PERIODO ===\n";
    std::cout << "Usuario: " << usuarioLogado.nome << "\n";
    std::cout << "Periodo: " << mesInicial << "/" << anoInicial << " ate " << mesFinal << "/" << anoFinal << "\n";

    std::cout << "Ganhos: R$ " << std::fixed << std::setprecision(2) << ganhos << "\n";
    std::cout << "Gastos obrigatorios: R$ " << gastosObrigatorios << "\n";
    std::cout << "Gastos nao obrigatorios: R$ " << gastosNaoObrigatorios << "\n";
    std::cout << "Saldo: R$ " << saldo << "\n";

    std::cout << "\n=== RESERVA DE EMERGENCIA ===\n";
    std::cout << "Media mensal de gastos obrigatorios: R$ " << mediaObrigatorios << "\n";
    std::cout << "Reserva minima (3 meses): R$ " << reservaMinima << "\n";
    std::cout << "Reserva ideal (6 meses): R$ " << reservaIdeal << "\n";
    std::cout << "Reserva reforcada (12 meses): R$ " << reservaReforcada << "\n";
}

// Função responsável por mostrar o resumo mais recente do usuário logado
void mostrarResumoFinanceiroAtual(const std::vector<Lancamento>& lancamentos, const Usuario& usuarioLogado) {
    int mesMaisRecente;
    int anoMaisRecente;

    // Verifica se existe pelo menos um lançamento do usuário
    if (!obterPeriodoMaisRecente(lancamentos, usuarioLogado, mesMaisRecente, anoMaisRecente)) {
        std::cout << "\nNenhum lancamento encontrado para o usuario.\n";
        return;
    }

    std::cout << "\n==== RESUMO ATUAL ====\n";

    // Usa o mês mais recente como período inicial e final
    mostrarResumoFinanceiroPeriodo(lancamentos, usuarioLogado, mesMaisRecente, anoMaisRecente, mesMaisRecente, anoMaisRecente);
}

// Função responsável por buscar o índice de um lançamento pelo ID, considerando apenas os lançamentos do usuário logado. Retorna -1 se o lançamento não for encontrado.
int buscarIndiceLancamentoPorId(const std::vector<Lancamento>& lancamentos, int idLancamento, const Usuario& usuarioLogado) {
    
    for (int i = 0; i < lancamentos.size(); ++i) {
        if (lancamentos[i].id == idLancamento && lancamentos[i].idUsuario == usuarioLogado.id) {
            return i; // Retorna o índice do lançamento encontrado
        }
    }
    return -1; // Retorna -1 se o lançamento não for encontrado
}


// Função responsável por editar um lançamento do usuário logado
void editarLancamento(std::vector<Lancamento>& lancamentos, const Usuario& usuarioLogado) {
    int idLancamento;

    std::cout << "\n=== EDITAR LANCAMENTO ===\n";
    std::cout << "Informe o ID do lancamento que deseja editar: ";
    std::cin >> idLancamento;
    
    // Utiliza a função de busca para encontrar o índice do lançamento a ser editado, garantindo que o usuário só possa editar seus próprios lançamentos
    int indice = buscarIndiceLancamentoPorId(lancamentos, idLancamento, usuarioLogado);

    if (indice == -1) {
        std::cout << "Lancamento nao encontrado.\n";
        return;
    }

    int opcaoTipo;

    std::cout << "Nova descricao: ";
    std::cin.ignore();
    std::getline(std::cin, lancamentos[indice].descricao);

    std::cout << "Novo tipo do lancamento:\n";
    std::cout << "1 - Ganho\n";
    std::cout << "2 - Gasto obrigatorio\n";
    std::cout << "3 - Gasto nao obrigatorio\n";
    std::cout << "Escolha: ";
    std::cin >> opcaoTipo;

    if (opcaoTipo == 1) {
        lancamentos[indice].tipo = "ganho";
    }
    else if (opcaoTipo == 2) {
        lancamentos[indice].tipo = "obrigatorio";
    }
    else if (opcaoTipo == 3) {
        lancamentos[indice].tipo = "nao_obrigatorio";
    }
    else {
        std::cout << "Tipo invalido. Edicao cancelada.\n";
        return;
    }

    std::cout << "Novo valor: ";
    std::cin >> lancamentos[indice].valor;

    if (lancamentos[indice].valor < 0) {
        std::cout << "Valor invalido.\n";
        return;
    }

    std::cout << "Novo dia: ";
    std::cin >> lancamentos[indice].dia;

    std::cout << "Novo mes: ";
    std::cin >> lancamentos[indice].mes;

    std::cout << "Novo ano: ";
    std::cin >> lancamentos[indice].ano;

    if (lancamentos[indice].dia < 1 || lancamentos[indice].dia > 31) {
        std::cout << "Dia invalido.\n";
        return;
    }

    if (lancamentos[indice].mes < 1 || lancamentos[indice].mes > 12) {
        std::cout << "Mes invalido.\n";
        return;
    }

    if (lancamentos[indice].ano < 0) {
        std::cout << "Ano invalido.\n";
        return;
    }

    std::cout << "Lancamento editado com sucesso!\n"; // Fazer a parte de edicao é a parte mais chatinha de se fazer, ter que refazer toda a parte de cadastro é muito repetitivo.
}

// Função responsável por excluir um lançamento do usuário logado
void excluirLancamento(std::vector<Lancamento>& lancamentos, const Usuario& usuarioLogado) {
    int idLancamento;

    std::cout << "\n=== EXCLUIR LANCAMENTO ===\n";
    std::cout << "Informe o ID do lancamento que deseja excluir: ";
    std::cin >> idLancamento;

    int indice = buscarIndiceLancamentoPorId(lancamentos, idLancamento, usuarioLogado);

    if (indice == -1) {
        std::cout << "Lancamento nao encontrado.\n";
        return;
    }

    lancamentos.erase(lancamentos.begin() + indice);

    std::cout << "Lancamento excluido com sucesso!\n";
}