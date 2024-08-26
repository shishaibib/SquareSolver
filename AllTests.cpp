#include "HeaderData.h"
int RunTests()
{
    double a, b, c;
    int nTest;
    double x1, x2, x1e, x2e;
    int N_roots, N_rootsE;

    FILE *testsdata;
    testsdata = fopen("testing.txt", "r");

    int ScanTest = fscanf (testsdata,"%d %lg %lg %lg %lg %lg %d\n", &nTest, &a, &b, &c, &x1e, &x2e, &N_rootsE);
    while(ScanTest == 7)
    {

            double x1=0,x2=0;
            int N_roots = Square_Solve (a, b, c, &x1, &x2);

            if(N_roots != N_rootsE || IsEqual(x1, x1e) || IsEqual(x2, x2e))
            {
                printf("ErrorTest %d, a = %lg, b = %lg, c = %lg,"
                       "x1 = %lg, x2 = %lg,N_roots = %d,"
                       "x1e = %lg,x2e = %lg,N_rootsE = %d",
                       nTest, a, b, c, x1, x2, N_roots,
                       x1e, x2e, N_rootsE);
                return 1;
            }

            printf("test %d passed\n",nTest);
            ScanTest = fscanf (testsdata,"%d %lg %lg %lg %lg %lg %d\n", &nTest, &a, &b, &c, &x1e, &x2e, &N_rootsE);

    }
}
