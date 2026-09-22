# 🏦 Mortgage Calculator - Software Engineering Project

## 1. Visão Geral do Projeto
Desenvolvimento de uma biblioteca C++ para cálculo e aprovação de hipotecas, aplicando as melhores práticas de Engenharia de Software: Design Modular, Testes Unitários (Google Test) e Integração Contínua (GitHub Actions).

## 2. Arquitetura e Especificações
* **Requisitos:** Avaliação de crédito baseada em Género, Idade e Salário, cruzada com a simulação de amortização (Pagamento Mensal e Orçamento Máximo).
* **Lógica de Decisão:** O sistema bloqueia financiamentos que excedam o limite seguro calculado e rejeita idades fora do limite definido.
* **Fluxograma Lógico:** [Inserir aqui o código Mermaid gerado na Etapa 2]

## 3. Matriz de Rastreabilidade (Traceability Matrix)
| Requirement | Design Element | Code Function | Google Test Case | CI Result / Evidence |
| :--- | :--- | :--- | :--- | :--- |
| Validar Regras de Negócio | Fator Multiplicador | `selectFactor()` | `MaleYoungBoundaryApproved` | Pass (Automated via GitHub Actions) |
| Recusa de Crédito | Validador de Orçamento | `calculateMortgage()` | `FemaleDeniedDueToBudget` | Pass (Automated via GitHub Actions) |
| Tratamento de Exceções | Limites de Idade/Salário | `validateInputs()` | `OutOfBoundsInputs` | Pass (Automated via GitHub Actions) |

## 4. Evidências de Qualidade (Quality Gates)
* ✅ **Correctness & Robustness:** Cobertura de testes de limites e partições de equivalência.
* ✅ **Team Collaboration:** Fluxo Git implementado com branches (`feature/*`), Commits atómicos e Pull Requests revisados.
* ✅ **CI Pipeline:** Workflow configurado (`ci.yml`) para compilar (CMake) e executar testes automaticamente no Ubuntu.
