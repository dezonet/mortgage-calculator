cmake_minimum_required(VERSION 3.14)
project(MortgageCalculator_Project)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. A nossa biblioteca principal
add_library(mortgage_lib src/mortgage_calculator.cpp)
target_include_directories(mortgage_lib PUBLIC include)

# 2. Descarregar o Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)

# 3. Configurar os Testes
enable_testing()

# Criar o executável de testes
add_executable(mortgage_tests tests/test_mortgage.cpp)

# Ligar a nossa biblioteca e o GTest ao executável
target_link_libraries(mortgage_tests PRIVATE mortgage_lib gtest_main)

# Descobrir os testes automaticamente para o CTest/VS Code
include(GoogleTest)
gtest_discover_tests(mortgage_tests)