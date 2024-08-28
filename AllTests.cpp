#include "HeaderData.h"

int RunTests()
{

    double a = 0;
    double b = 0;
    double c = 0;
    int n_test = 0;

    double x1 = 0;
    double x2 = 0;
    double x1_exp = 0;
    double x2_exp = 0;

    int n_roots = 0;
    int n_roots_exp = 0;

    FILE *testsdata = fopen("testing.txt", "r");
    if (testsdata == NULL)
    {
        printf ("Test File Error\n ");
        return 5;
    }

    int ScanTest = fscanf (testsdata,"%d %lg %lg %lg %lg %lg %d\n", &n_test, &a, &b, &c, &x1_exp, &x2_exp, &n_roots_exp);

    while (ScanTest == 7)
    {

        double x1 = 0;
        double x2 = 0;
        int n_roots = SolveSquare (a, b, c, &x1, &x2);

        if(n_roots != n_roots_exp || !IsEqual(x1, x1_exp) || !IsEqual(x2, x2_exp))
        {
            printf("ErrorTest %d, a = %lg, b = %lg, c = %lg,"
                   "x1 = %lg, x2 = %lg,n_roots = %d,"
                   "x1_exp = %lg,x2_exp = %lg,n_roots_exp = %d",
                   n_test, a, b, c, x1, x2, n_roots,
                   x1_exp, x2_exp, n_roots_exp);
                   fclose (testsdata);
            return 1;
        }

        printf("test %d passed\n",n_test);
        ScanTest = fscanf (testsdata,"%d %lg %lg %lg %lg %lg %d\n", &n_test, &a, &b, &c, &x1_exp, &x2_exp, &n_roots_exp);
    }

    fclose (testsdata);
    return 0;

}
