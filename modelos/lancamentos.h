#ifndef LANCAMENTOS_H
#define LANCAMENTOS_H

#include <string>

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