#ifndef LANCAMENTOS_H
#define LANCAMENTOS_H

#include <string>
/*
O lancamentos.h é o arquivo que vai conter a struct Lancamento
que é a estrutura de dados que vai ser utilizada para armazenar as informações dos lancamentos, como descricao, tipo, valor, mes e ano.
essa struct vai ser utilizada em todo o projeto, principalmente no lancamentoService.h e lancamentoService.cpp
para cadastrar, listar, calcular totais, mostrar resumo, etc. dos lancamentos
*/
struct Lancamento {
    int id;
    int idUsuario;
    std::string descricao;
    std::string tipo; // ganho | obrigatorio | nao_obrigatorio
    float valor;
    int mes;
    int ano;
};

#endif