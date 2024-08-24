#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <unistd.h>
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
/*struct TestData data[] = {
                             {1, 1, 0, -4, 2, -2, TWO_ROOTS},
                             {2, 0, 0, 0, 0, 0, INF_ROOTS},
                             {3, 0, 2, -4, 2, 0, ONE_ROOT},
                             {4, 1, 0, 1, 0, 0, NO_ROOTS}
                         };  */
int Square_Solve(double a,double b,double c,double* x1,double* x2);
int RunTests(TestData test1);
int IsZero(double a);
int RunTests();
int IsEqual(double a,double b);

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


