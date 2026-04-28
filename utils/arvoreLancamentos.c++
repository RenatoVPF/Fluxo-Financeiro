#include "arvoreLancamentos.h"
// Implementação da estrutura de dados em forma de árvore binária para organizar os lançamentos financeiros por data, facilitando consultas e cálculos de resumos financeiros. 
// Cada nodo da árvore representa um lançamento financeiro, e a árvore é organizada por data para permitir buscas eficientes em períodos específicos.
bool dataEMenor(const Lancamento& valorUm, const Lancamento& valorDois) {

    if (valorUm.ano != valorDois.ano) return valorUm.ano < valorDois.ano;
    if (valorUm.mes != valorDois.mes) return valorUm.mes < valorDois.mes;
    if (valorUm.dia != valorDois.dia) return valorUm.dia < valorDois.dia;

    return valorUm.id < valorDois.id; // Se as datas forem iguais, ordena por ID para garantir estabilidade

}

NoLancamento* criarNoLancamento(const Lancamento& lancamento) {
    NoLancamento* novoNo = new NoLancamento;
    novoNo->dado = lancamento;
    novoNo->esquerda = nullptr;
    novoNo->direita = nullptr;
    return novoNo;
}

NoLancamento* inserirNaArvore(NoLancamento* raiz, const Lancamento& lancamento) {
    if (raiz == nullptr){
        return criarNoLancamento(lancamento);
    }
    if (dataEMenor(lancamento, raiz->dado)) {
        raiz->esquerda = inserirNaArvore(raiz->esquerda, lancamento);
    } else {
        raiz->direita = inserirNaArvore(raiz->direita, lancamento);
    }
    return raiz;

}

void percursoEmOrdem(NoLancamento* raiz, std::vector<Lancamento>& lancamentos) {
    if (raiz == nullptr) return;

    percursoEmOrdem(raiz->esquerda, lancamentos);
    lancamentos.push_back(raiz->dado);
    percursoEmOrdem(raiz->direita, lancamentos);
    
}

void liberarArvore(NoLancamento* raiz) {
    if (raiz == nullptr) return;

    liberarArvore(raiz->esquerda);
    liberarArvore(raiz->direita);
    delete raiz;
}

void ordenarLancamentosPorArvore(std::vector<Lancamento>& lancamentos) {

    NoLancamento* raiz = nullptr;

    for (const Lancamento& lancamento : lancamentos) {
        raiz = inserirNaArvore(raiz, lancamento);
    }

    std::vector<Lancamento> ordenados;
    ordenados.reserve(lancamentos.size());

    percursoEmOrdem(raiz, ordenados);

    lancamentos = ordenados;

    liberarArvore(raiz);
}