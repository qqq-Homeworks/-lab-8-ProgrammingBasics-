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

    double B[10][10];
    for (size_t i = 0; i < 10; i++)
    {
        for (size_t j = 0; j < 10; j++)
        {
            B[i][j] = i * 10 + j;
        }
    }
    double **D = new double *[10];
    for (int i = 0; i < 10; i++)
        D[i] = B[i];

    PrintMatrix(D, 10, 10, 0, 0);
    DestructMatrix(D,10);
}