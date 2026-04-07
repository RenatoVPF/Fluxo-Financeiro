#ifndef USUARIOS_H
#define USUARIOS_H

#include <string>
/*
O usuarios.h é o arquivo que vai conter a struct Usuario, que é a estrutura de dados que vai ser utilizada para armazenar as informações dos usuários, como id, nome e senha.
essa struct vai ser utilizada em todo o projeto, principalmente no lancamentoService.h e lancamentoService.cpp
para cadastrar, listar, calcular totais, mostrar resumo, etc. dos lancamentos
*/
struct Usuario {
    int id;
    std::string nome;
    std::string senha;
};

#endif