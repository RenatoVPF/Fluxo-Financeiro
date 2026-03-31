#ifndef LANCAMENTO_SERVICE_H
#define LANCAMENTO_SERVICE_H

/*
o lancamentoService.h é o arquivo que vai conter todas as funcoes relacinadas
aos lancamentos, como cadastrar, listar, caucular totais, mostrar resumo, etc.
Ele vai ser incluido no main.cpp para ser utilizado nas funcoes do menu do usuario logado.
aqui especificamente, são os prototipos das funcoes, e a implementacao delas vai ser feita no lancamentoService.cpp
*/

#include <vector>
#include "../modelos/lancamentos.h"
#include "../modelos/usuarios.h"

void cadastrarLancamento(std::vector<Lancamento>& lancamentos, const Usuario& usuarioLogado);

void listarLancamentos(const std::vector<Lancamento>& lancamentos, const Usuario& usuarioLogado);

bool estaDentroDoPeriodo(const Lancamento& lancamento, int mesInicial, int anoInicial, int mesFinal, int anoFinal);

bool obterPeriodoMaisResente(const std::vector<Lancamento>& lancamentos, const Usuario& usuarioLogado, int& mesMaisRecente, int& anoMaisRecente);

float calcularTotaisGanhosPeriodo(const std::vector<Lancamento>& lancamentos, const Usuario& usuarioLogado, int mesInicial, int anoInicial, int mesFinal, int anoFinal);

float calcularGastosObrigatoriosPeriodo(const std::vector<Lancamento>& lancamentos, const Usuario& usuarioLogado, int mesInicial, int anoInicial, int mesFinal, int anoFinal);

float calcularGastosNaoObrigatoriosPeriodo(const std::vector<Lancamento>& lancamentos, const Usuario& usuarioLogado, int mesInicial, int anoInicial, int mesFinal, int anoFinal);

float calcularSaldoMensalPeriodo(const std::vector<Lancamento>& lancamentos, const Usuario& usuarioLogado, int mesInicial, int anoInicial, int mesFinal, int anoFinal);

void mostrarResumoFinaceiroAtual(const std::vector<Lancamento>& lancamentos, const Usuario& usuarioLogado);

void mostrarResumoFinaceiroPeriodo(const std::vector<Lancamento>& lancamentos, const Usuario& usuarioLogado, int mesInicial, int anoInicial, int mesFinal, int anoFinal);






#endif // LANCAMENTO_SERVICE_H