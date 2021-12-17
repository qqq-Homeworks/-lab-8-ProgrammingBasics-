#include "functions.hpp"

int factorial(int n)
{
    if (n <= 1)
        return 1;
    else
        return (n * factorial(n - 1));
}

double **CreateMatrix(int N)
{
    double **matrix = new double *[N];
    for (int i = 0; i < N; ++i)
    {
        matrix[i] = new double[N];
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j)
            {
                matrix[i][j] = 1;
            }
            else if (i < j)
            {
                matrix[i][j] = pow(1, i) / pow(factorial(j), i);
            }
            else if (i > j)
            {
                matrix[i][j] = pow(-1, i) / pow(factorial(j), i);
            }
        }
    }

    return matrix;
}

void DestructMatrix(double **matrix, int N)
{
    for (int i = 0; i < N; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void PrintMatrix(double **matrix, int n, int m, bool isScientific, int precision)
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    int count = 0;
    int widthq = precision + 4 + 5 * isScientific;
    int z = 0;
    int q = 0;
    count = w.ws_col / widthq;
    for (z = 0; z < m / count; z++)
    {
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = count * z; j < count * (z + 1); j++)
            {
                if (isScientific)
                {
                    std::cout << std::scientific << std::setprecision(precision) << std::setw(widthq) << matrix[i][j];
                }
                else
                    std::cout << std::fixed << std::setprecision(precision) << std::setw(widthq) << matrix[i][j];

                q = j;
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    if (q + 1 < m)
    {
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = q + 1; j < m; j++)
            {
                if (isScientific)
                {
                    std::cout << std::scientific << std::setprecision(precision) << std::setw(widthq) << matrix[i][j];
                }
                else
                    std::cout << std::fixed << std::setprecision(precision) << std::setw(widthq) << matrix[i][j];
            }
            std::cout << std::endl;
        }
    }
}