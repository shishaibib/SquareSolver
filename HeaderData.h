#ifndef HEADER_DATA_H
#define HEADER_DATA_H

#include <stdio.h>
#include <assert.h>
#include <math.h>

enum NUMBER_OF_ROOTS
{
    NO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2,
    INF_ROOTS = 3
};

int SolveSquare(double a,double b,double c,double* x1,double* x2);
bool IsZero(double a);
int RunTests();
bool IsEqual(double a,double b);
int CleanInput();
int ScanCoefficients(double *a, double *b, double *c);
int PrintRoots(int n_roots, double x1, double x2);
#endif

