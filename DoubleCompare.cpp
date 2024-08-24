#include <stdio.h>
#include <math.h>
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
