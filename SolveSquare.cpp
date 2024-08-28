#include "HeaderData.h"

int SolveSquare(double a,double b,double c,double* x1,double* x2)
{

    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    double d = b*b - 4*a*c;

    if(IsZero(a))
    {
        if(IsZero(b))
        {
            return (IsZero(c)) ? INF_ROOTS : NO_ROOTS;
        }

        *x1 = -c/b;
        return ONE_ROOT;
    }

    if(IsZero(d))
    {
        *x1= *x2= -b/(2*a);
        return(ONE_ROOT);
    }

    if(d < 0)
    {
        return(NO_ROOTS);
    }

    double sqrtd = sqrt(d);

    *x1=(-b+sqrtd)/(2*a);
    *x2=(-b-sqrtd)/(2*a);

    return TWO_ROOTS;


}
