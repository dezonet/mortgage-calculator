#include <iostream>
#include <iomanip>
#include "mortgage_calculator.h"

int main() {
    int gender_input, age, term;
    double salary, principal, rate;

    std::cout << "\n=== SIMULADOR DE HIPOTECA ===\n";
    
    std::cout << "Genero (0 para Masculino, 1 para Feminino): ";
    std::cin >> gender_input;
    Gender gender = (gender_input == 0) ? MALE : FEMALE;

    std::cout << "Idade: ";
    std::cin >> age;
    
    std::cout << "Salario Mensal: $";
    std::cin >> salary;
    
    std::cout << "Valor Solicitado (Principal): $";
    std::cin >> principal;
    
    std::cout << "Taxa de Juros Anual (ex: 4.5): ";
    std::cin >> rate;
    
    std::cout << "Prazo (Anos): ";
    std::cin >> term;

    std::cout << "\nProcessando...\n";

    try {
        MortgageResult result = calculateMortgage(gender, age, salary, principal, rate, term);
        
        std::cout << "\n=== RESULTADO DA ANALISE ===\n";
        std::cout << "Status: " << result.status_message << "\n";
        
        // Formatar a saída para 2 casas decimais
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Orcamento Maximo Aprovado: $" << result.max_mortgage << "\n";
        std::cout << "Pagamento Mensal Estimado: $" << result.monthly_payment << "\n";
        std::cout << "============================\n\n";
        
    } catch (const std::exception& e) {
        std::cout << "\n[ERRO]: " << e.what() << "\n\n";
    }

    return 0;
}