#include "HeaderData.h"
TestData data[] = {
                      {1, 1, 0, -4, 2, -2, TWO_ROOTS},
                      {2, 0, 0, 0, 0, 0, INF_ROOTS},
                      {3, 0, 2, -4, 2, 0, ONE_ROOT},
                      {4, 1, 0, 1, 0, 0, NO_ROOTS},
                      {5, 1, -2, 1, 1, 1, ONE_ROOT},
                      {6, 0, 0, 2, 0, 0, NO_ROOTS}
                  };
int RunTests()
{
    for(int i = 0; i < NTESTS; i++)
        {
            double a = data[i].a;
            double b = data[i].b;
            double c = data[i].c;
            int nTest = data[i].nTest;

            double x1=0,x2=0;
            int N_roots = Square_Solve (a, b, c, &x1, &x2);

            if(N_roots != data[i].N_rootsE || IsEqual(x1, data[i].x1e) || IsEqual(x2, data[i].x2e))
                {
                    printf("ErrorTest %d, a = %lg, b = %lg, c = %lg,"
                           "x1 = %lg, x2 = %lg,N_roots = %d,"
                           "x1e = %lg,x2e = %lg,N_rootsE = %d",
                           nTest, a, b, c, x1, x2, N_roots,
                           data[i].x1e, data[i].x2e, data[i].N_rootsE);
                    return 1;
                }

            printf("test %d passed\n",nTest);
    }
    return 0;
}
