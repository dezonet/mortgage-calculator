#ifndef MORTGAGE_CALCULATOR_H
#define MORTGAGE_CALCULATOR_H

#include <string>
#include <stdexcept>

// Enumeração para facilitar a leitura do código
enum Gender { MALE, FEMALE };

// Struct de saída com todos os dados solicitados
struct MortgageResult {
    double monthly_payment;
    double max_mortgage;
    bool is_approved;
    std::string status_message;
};

// Declaração das funções modulares
bool validateInputs(Gender gender, int age, double salary, double principal, double rate, int term);
double selectFactor(Gender gender, int age);
double calculateMonthlyPayment(double principal, double annual_rate, int term_years);

// Função principal orquestradora
MortgageResult calculateMortgage(Gender gender, int age, double salary, double principal, double rate, int term);

#endif // MORTGAGE_CALCULATOR_H