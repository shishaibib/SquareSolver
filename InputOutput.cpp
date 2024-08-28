#include "HeaderData.h"

int CleanInput()
{
    while(getchar() != '\n')
    {
        getchar();
    }
}

int ScanCoefficients(double *a, double *b, double *c)
{

    int res = scanf("%lg %lg %lg/n", a, b, c);

    while(res != 3)
    {

        getchar();
        printf("error, enter correct a, b, c\n");
        CleanInput();
        res = scanf("%lg %lg %lg/n", a, b, c);

    }
    return 6;
}

int PrintRoots(int n_roots, double x1, double x2)
{
    switch(n_roots)
    {
        case NO_ROOTS:
            printf("no roots");
            break;

        case ONE_ROOT:
            printf("x = %lg\n",x1);
            break;

        case TWO_ROOTS:
            printf("x1 = %lg, x2 = %lg",x1,x2);
            break;

        case INF_ROOTS:
            printf("any number");
            break;

        default:
            printf("error");
            break;
    }
}










