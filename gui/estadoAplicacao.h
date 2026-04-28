#ifndef ESTADO_APLICACAO_H
#define ESTADO_APLICACAO_H
/*
esse parte vai trabalhar junto com a interface e o main

*/
#include <vector>
#include <string>
#include "../modelos/usuarios.h"
#include "../modelos/lancamentos.h"

struct EstadoAplicacao {
    std::vector<Usuario> usuarios;
    std::vector<Lancamento> lancamentos;
    Usuario usuarioLogado;
    bool usuarioAutenticado = false;

    int controleTela = 0; // 0 = tela de login/cadastro, e o resto anda vou definir, mas a ideia é essa mesma

    std::string nomeUsuario;
    std::string senhaUsuario;

    std::string mensagemLogin;

};

#endif // ESTADO_APLICACAO_H