#include "s21_model.h"
#include <iostream>

int main() {
    s21::Model calculator;
    std::string expression = "2 + 2 * 2";
    bool error = false;
    double result = calculator.target(expression, &error, 0);
    if (!error) {
        std::cout << "Result: " << result << std::endl;
    } else {
        std::cout << "Invalid expression" << std::endl;
    }
    return 0;
}
