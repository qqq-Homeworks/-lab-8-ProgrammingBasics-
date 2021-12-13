#include <math.h>
#include <iostream>
#include <iomanip>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

int factorial(int);

double **CreateMatrix(int);

void DestructMatrix(double **, int);

void PrintMatrix(double **, int, int, bool, int);