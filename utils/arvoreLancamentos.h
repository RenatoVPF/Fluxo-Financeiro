#ifndef ARVORE_LANCAMENTOS_H
#define ARVORE_LANCAMENTOS_H
#include <vector>
#include "../modelos/lancamentos.h"
/*
    Vou criar uma estrutura de dados em forma de arvore binaria para botar em pratica o aprendizado sobre estruturas de dados
    Essa arvore vai ser responsavel por reoganizar os lancamentos financeiros do usuario logado, para facilitar a consulta e o calculo dos resumos financeiros
    A ideia é que cada nodo da arvore seja um lancamento financeiro, e a arvore seja organizada por data.
    Assim, quando o usuario quiser consultar os lancamentos de um periodo especifico, a arvore vai facilitar a busca
*/
struct NoLancamento {
    Lancamento dado;
    NoLancamento* esquerda;
    NoLancamento* direita;
};

bool dataEMenor(const Lancamento& valorUm, const Lancamento& valorDois);

NoLancamento* criarNoLancamento(const Lancamento& lancamento);

NoLancamento* inserirNaArvore(NoLancamento* raiz, const Lancamento& lancamento);

void percursoEmOrdem(NoLancamento* raiz, std::vector<Lancamento>& lancamentos);

void liberarArvore(NoLancamento* raiz);

void ordenarLancamentosPorArvore(std::vector<Lancamento>& lancamentos);

#endif
