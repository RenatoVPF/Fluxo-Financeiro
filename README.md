# 💰 Fluxo Financeiro

Sistema de controle financeiro desenvolvido em C++, com foco em organização de gastos, análise por período e cálculo de reserva de emergência.

---

## 📌 Objetivo

O objetivo do projeto é permitir que o usuário:

- Cadastre receitas e despesas
- Classifique gastos como obrigatórios ou não obrigatórios
- Visualize resumos financeiros por:
  - mês
  - período personalizado
  - período atual
- Calcule automaticamente uma **reserva de emergência**

---

## 🚀 Funcionalidades

### 👤 Usuário
- Cadastro de usuário
- Login
- Persistência em arquivo `.txt`

### 💸 Lançamentos
- Cadastro de:
  - Ganhos
  - Gastos obrigatórios
  - Gastos não obrigatórios
- Associação de lançamentos ao usuário logado

### 📊 Consultas
- Listagem de lançamentos
- Filtro por período
- Resumo financeiro por:
  - mês específico
  - período
  - período atual

### 🧠 Inteligência financeira
- Cálculo de:
  - saldo
  - média de gastos obrigatórios
  - reserva de emergência:
    - mínima (3 meses)
    - ideal (6 meses)
    - reforçada (12 meses)

---

## 🛠️ Tecnologias utilizadas

- C++
- STL (`vector`, `string`, `fstream`, etc.)
- Arquivos `.txt` para persistência

---

## 📂 Estrutura do projeto
Fluxo Financeiro/
│
├── main.cpp
├── modelos/
│ ├── usuarios.h
│ └── lancamentos.h
│
├── services/
│ ├── usuarioService.cpp
│ ├── usuarioService.h
│ ├── lancamentoService.cpp
│ └── lancamentoService.h
│
├── utils/
│ ├── arquivoUtils.cpp
│ └── arquivoUtils.h
│
├── data/
│ ├── usuarios.txt
│ └── lancamentos.txt
│
└── README.md
---

## ⚙️ Como compilar

No Linux:

```bash
g++ main.cpp services/lancamentoService.cpp services/usuarioService.cpp utils/arquivoUtils.cpp -o fluxoFinanceiro -Iservices -Iutils -Imodelos

./fluxoFinanceiro

```
## 📌 Observações

- Os dados são armazenados em arquivos `.txt`, utilizando leitura e escrita com `fstream`
- Cada usuário possui seus próprios lançamentos financeiros, vinculados pelo `idUsuario`
- O sistema não utiliza banco de dados neste momento, sendo focado em manipulação de arquivos para fins de estudo

---

## 🔧 Melhorias e evoluções planejadas

O projeto está em evolução contínua e as próximas implementações previstas incluem:

### 📊 Funcionalidades
- [ ] Editar lançamentos
- [ ] Excluir lançamentos
- [ ] Filtro por tipo de gasto
- [ ] Relatórios mais detalhados
- [ ] Comparação entre períodos

### 🧠 Inteligência financeira
- [ ] Análise de comportamento financeiro do usuário
- [ ] Sugestões de economia com base nos gastos
- [ ] Alertas de gastos excessivos

### 💻 Interface
- [ ] Interface gráfica (Qt - C++)
- [ ] Versão Web (HTML, CSS, JavaScript)
- [ ] Dashboard com gráficos (barras, pizza, evolução mensal)

### 🗄️ Persistência de dados
- [ ] Migração de `.txt` para banco de dados (SQLite)
- [ ] Estrutura de dados mais robusta
- [ ] Melhor controle de integridade dos dados

### 🔐 Segurança
- [ ] Criptografia de senha
- [ ] Validação de entrada de dados
- [ ] Sistema de autenticação mais seguro
