#include "stdafx.h"


bool DblsEqual(double lhs, double rhs)
{
    return abs(rhs - lhs) < DBL_EPSILON;
}