#ifndef TRIANGLE_H
#define TRIANGLE_H

typedef enum
{
    Invalid,
    Equilateral,
    Isosceles,
    Scalene
} TriangleType;

extern TriangleType GetTriangleType(int a, int b, int c);

#endif