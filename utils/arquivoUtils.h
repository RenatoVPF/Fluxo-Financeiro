#ifndef ARQUIVOUTILS_H
#define ARQUIVOUTILS_H

#include <vector>
#include <string>
#include "../modelos/usuarios.h"

void salvarUsuarios(const std::vector<Usuario>& usuarios, const std::string& nomeArquivo);
void carregarUsuarios(std::vector<Usuario>& usuarios, const std::string& nomeArquivo);


#endif // ARQUIVOUTILS_H