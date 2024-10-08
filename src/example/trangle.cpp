#include "trangle.h"

TriangleType GetTriangleType(int a, int b, int c)
{
    if (a < 0 || b < 0 || c < 0)
    {
        return Invalid;
    }

    if (!(a + b > c && a + c > b && b + c > a))
    {
        return Invalid;
    }

    if (a == b && b == c)
    {
        return Equilateral;
    }
    else if (a == b || b == c || a == c)
    {
        return Isosceles;
    }
    else
    {
        return Scalene;
    }
}