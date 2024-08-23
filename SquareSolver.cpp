#include <stdio.h>
#include <assert.h>
#include <math.h>    /*тест коммита*/
#include <unistd.h>      /* ещё один тест */
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
struct TestData data[] = {
                          {1, 1, 0, -4, 2, -2, TWO_ROOTS},
                          {2, 0, 0, 0, 0, 0, INF_ROOTS},
                          {3, 0, 2, -4, 2, 0, ONE_ROOT},
                          {4, 1, 0, 1, 0, 0, NO_ROOTS}
                         };
int Square_Solve(double a,double b,double c,double* x1,double* x2) ;
int RunTests(TestData test1);
int IsZero(double a);
int RunTests();
int IsEqual(double a,double b);
int IsZero(double a)
{
    double eps = 0.00001;

    if(a-eps <= 0 && a + eps >= 0)
    {
        return 1;
    }

    return 0;
}
int IsEqual (double a,double b)
{
    double eps = 0.00001;

    if(fabs(a - b) <= eps)
    {
        return 0;
    }

    return 1;
}


int Square_Solve(double a,double b,double c,double* x1,double* x2)
{

    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);
    double d = b*b - 4*a*c;
    if(IsZero(a))
    {
        if(IsZero(b))
        {
            return (IsZero(c))? INF_ROOTS : 0;
        }
        else
        {
            *x1 = -c/b;
            return ONE_ROOT;
        }
    }
    else
    {
        if(IsZero(d))
        {
            *x1= *x2= -b/(2*a);
            return(ONE_ROOT);
        }

        if(d < 0)
        {
            return(NO_ROOTS);
        }

        *x1=(-b+sqrt(d))/(2*a);
        *x2=(-b-sqrt(d))/(2*a);

        return TWO_ROOTS;
    }

}


int RunTests()
{
    for(int i = 0; i <= 3; i++)
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

int main(){

    printf("SquareSolver\n");
    RunTests();
    printf("Enter a,b,c\n");
    double a = 0,b = 0,c = 0;

    int res = scanf("%lg %lg %lg/n",&a, &b, &c);

    while(res != 3)
    {

        res = scanf("%lg %lg %lg/n",&a, &b, &c);
        getchar();
        fflush(stdin);
        printf("error, enter correct a,b,c\n");

    }

    double x1 = 0, x2 = 0;
    int N_roots = 0;
                                                          /* идея - очищать строку ввода когда res ретурн что-то кроме 3 */
    N_roots = Square_Solve(a ,b ,c ,&x1,&x2);

    switch(N_roots)
    {
        case NO_ROOTS:
        printf("no roots");
        break;

        case ONE_ROOT:
        printf("x= %lg\n",x1);
        break;

        case TWO_ROOTS:
        printf("x1= %lg, x2= %lg",x1,x2);
        break;

        case INF_ROOTS:
        printf("any number");
        break;

        default:
        printf("error");
        break;
    }

}
/*!!!!!kapshay!!!!!*/

/*  int x = 0;

    if ( userInput == 123 ) {
        x = 1;
    } else {
        x = 2;
    }

    int x = (userInput == 123) ? 1 : 2; */


