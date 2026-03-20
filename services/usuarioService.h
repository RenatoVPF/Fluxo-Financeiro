#ifndef USUARIOSERVICE_H
#define USUARIOSERVICE_H

#include <vector>
#include <string>
#include "../modelos/usuarios.h"

void cadastrarUsuario(std::vector<Usuario>& usuarios);
bool fazerLogin(const std::vector<Usuario>& usuarios, Usuario& usuarioLogado);
void listarUsuarios(const std::vector<Usuario>& usuarios);


#endif // USUARIOSERVICE_H