#include "HeaderData.h"

bool IsEqual (double a, double b)
{
    double eps = 0.00001;
    return (fabs(a - b) <= eps);
}

bool IsZero(double a)
{
    IsEqual(a, 0);
}



