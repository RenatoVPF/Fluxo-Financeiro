#ifndef LANCAMENTO_SERVICE_H
#define LANCAMENTO_SERVICE_H

#include <vector>
#include "../modelos/lancamentos.h"
#include "../modelos/usuarios.h"

void cadastrarLancamento(std::vector<Lancamento>& lancamentos, const Usuario& usuarioLogado);
void listarLancamentos(const std::vector<Lancamento>& lancamentos, const Usuario& usuarioLogado);

float calcularTotaisGanhos(const std::vector<Lancamento>& lancamentos, const Usuario& usuarioLogado);
float calcularGastosobrifatorios(const std::vector<Lancamento>& lancamentos, const Usuario& usuarioLogado);
float calcularGastosNaoObrigatorios(const std::vector<Lancamento>& lancamentos, const Usuario& usuarioLogado);
float calcularSaldoMensal(const std::vector<Lancamento>& lancamentos, const Usuario& usuarioLogado);

void mostrarResumoFinaceiro(const std::vector<Lancamento>& lancamentos, const Usuario& usuarioLogado);







#endif // LANCAMENTO_SERVICE_H