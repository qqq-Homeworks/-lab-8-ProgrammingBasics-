#include "functions.hpp"

int main()
{
    int n, precision;
    bool isScientific;
    std::cout << "Enter n:\n";
    std::cin >> n;
    std::cout << "Scientific(1) or fixed(0)?\n";
    std::cin >> isScientific;
    std::cout << "Enter precision:\n";
    std::cin >> precision;
    double **matrix = CreateMatrix(n);

    PrintMatrix(matrix, n, n, isScientific, precision);
    DestructMatrix(matrix, n);
}