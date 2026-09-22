#include <gtest/gtest.h>
#include "mortgage_calculator.h"
#include <cmath>

// Teste 1: Limite Inferior Masculino (Equivalence Partitioning & Boundary)
TEST(MortgageTest, MaleYoungBoundaryApproved) {
    // Male, 18 anos, 5000 salário. Fator = 75. Max Budget = 375,000.
    // Solicitado: 300,000 a 4.5% por 30 anos.
    auto result = calculateMortgage(MALE, 18, 5000, 300000, 4.5, 30);
    
    EXPECT_TRUE(result.is_approved);
    EXPECT_EQ(result.max_mortgage, 375000);
    // Verificação aproximada do pagamento mensal (tolerância de 0.01)
    EXPECT_NEAR(result.monthly_payment, 1520.06, 0.01); 
}

// Teste 2: Lógica de Recusa (Mortgage Not Approved)
TEST(MortgageTest, FemaleDeniedDueToBudget) {
    // Female, 35 anos, 3000 salário. Fator = 50. Max Budget = 150,000.
    // Solicitado: 250,000 (Excede o orçamento).
    auto result = calculateMortgage(FEMALE, 35, 3000, 250000, 4.5, 30);
    
    EXPECT_FALSE(result.is_approved);
    EXPECT_EQ(result.status_message, "Mortgage not approved");
}

// Teste 3: Caso Inválido Específico (Robustness Testing)
TEST(MortgageTest, FemaleInvalidAgeRangeThrowsException) {
    // Mulheres entre 51 e 55 anos não têm fator definido. Deve lançar exceção.
    EXPECT_THROW(calculateMortgage(FEMALE, 52, 5000, 100000, 5.0, 20), std::invalid_argument);
}

// Teste 4: Limites de Idade e Salário
TEST(MortgageTest, OutOfBoundsInputs) {
    // Idade < 18
    EXPECT_THROW(calculateMortgage(MALE, 17, 5000, 100000, 5.0, 20), std::invalid_argument);
    // Idade > 55
    EXPECT_THROW(calculateMortgage(MALE, 56, 5000, 100000, 5.0, 20), std::invalid_argument);
    // Salário > 10.000
    EXPECT_THROW(calculateMortgage(FEMALE, 30, 10001, 100000, 5.0, 20), std::invalid_argument);
}