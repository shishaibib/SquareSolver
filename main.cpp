#include "HeaderData.h"

#define TEST

int main()
{
    #ifdef TEST
    RunTests();
    #endif

    printf("SquareSolver\n"
           "Enter a, b, c\n");

    double a = 0;
    double b = 0;
    double c = 0;
    double x1 = 0;
    double x2 = 0;
    int n_roots = 0;

    ScanCoefficients(&a, &b, &c);

    n_roots = SolveSquare(a, b, c, &x1, &x2);

    PrintRoots(n_roots, x1, x2);

}



