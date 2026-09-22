#include "mortgage_calculator.h"
#include <cmath>

bool validateInputs(Gender gender, int age, double salary, double principal, double rate, int term) {
    // Validações básicas de limites
    if (age < 18 || age > 55) return false;
    if (salary < 0 || salary > 10000) return false;
    if (principal <= 0 || rate < 0 || term <= 0) return false;
    
    // Tratamento específico: Mulheres entre 51 e 55 anos não possuem fator definido
    if (gender == FEMALE && age >= 51 && age <= 55) return false;
    
    return true;
}

double selectFactor(Gender gender, int age) {
    if (gender == MALE) {
        if (age >= 18 && age <= 35) return 75.0;
        if (age >= 36 && age <= 45) return 55.0;
        if (age >= 46 && age <= 55) return 30.0;
    } else if (gender == FEMALE) {
        if (age >= 18 && age <= 30) return 70.0;
        if (age >= 31 && age <= 40) return 50.0;
        if (age >= 41 && age <= 50) return 35.0;
    }
    throw std::invalid_argument("Combinacao de genero e idade invalida para selecao de fator.");
}

double calculateMonthlyPayment(double principal, double annual_rate, int term_years) {
    if (annual_rate == 0.0) return principal / (term_years * 12.0); // Caso a taxa seja 0 (sem juros)
    
    double monthly_rate = (annual_rate / 100.0) / 12.0;
    int total_months = term_years * 12;
    double compound_factor = std::pow(1.0 + monthly_rate, total_months);
    
    return principal * monthly_rate * compound_factor / (compound_factor - 1.0);
}

MortgageResult calculateMortgage(Gender gender, int age, double salary, double principal, double rate, int term) {
    if (!validateInputs(gender, age, salary, principal, rate, term)) {
        throw std::invalid_argument("Entradas invalidas. Verifique a idade, salario ou demais parametros.");
    }

    double factor = selectFactor(gender, age);
    
    MortgageResult result;
    result.max_mortgage = salary * factor;
    result.monthly_payment = calculateMonthlyPayment(principal, rate, term);
    
    // Regra de aprovação
    if (principal > result.max_mortgage) {
        result.is_approved = false;
        result.status_message = "Mortgage not approved";
    } else {
        result.is_approved = true;
        result.status_message = "Approved";
    }
    
    return result;
}