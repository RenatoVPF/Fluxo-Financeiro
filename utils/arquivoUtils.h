#ifndef ARQUIVOUTILS_H
#define ARQUIVOUTILS_H

#include <vector>
#include <string>
#include "../modelos/usuarios.h"
#include "../modelos/lancamentos.h"

void salvarUsuarios(const std::vector<Usuario>& usuarios, const std::string& nomeArquivo);
void carregarUsuarios(std::vector<Usuario>& usuarios, const std::string& nomeArquivo);
void salvarLancamentos(const std::vector<Lancamento>& lancamentos, const std::string& nomeArquivo);
void carregarLancamentos(std::vector<Lancamento>& lancamentos, const std::string& nomeArquivo);


#endif // ARQUIVOUTILS_H