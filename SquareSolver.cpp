#include "HeaderData.h"
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
        printf("error, enter correct a, b, c\n");         /*два раза работает принтф (пофиксить)*/

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


