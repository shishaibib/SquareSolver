#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <unistd.h>
const int NTESTS = 6;
const int INF_ROOTS = 3;
const int NO_ROOTS = 0;
const int ONE_ROOT = 1;
const int TWO_ROOTS = 2;
struct TestData
{
    int nTest;
    double a, b, c;
    double x1e, x2e;
    int N_rootsE;
};

int Square_Solve(double a,double b,double c,double* x1,double* x2);
int RunTests(TestData test1);
int IsZero(double a);
int RunTests();
int IsEqual(double a,double b);
