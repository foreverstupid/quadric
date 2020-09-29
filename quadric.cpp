#include "quadric.hpp"

double getA11(Point points[5])
{
    Matrix m(5);

    for (int i = 0; i < 5; i++)
    {    
        m(i, 0) = points[i].x * points[i].y;
        m(i, 1) = points[i].y * points[i].y;
        m(i, 2) = points[i].x;
        m(i, 3) = points[i].y;
        m(i, 4) = 1.0;
    }

    return getDeterminant(m);
}

double getA12(Point points[5])
{
    Matrix m(5);

    for (int i = 0; i < 5; i++)
    {    
        m(i, 0) = points[i].x * points[i].x;
        m(i, 1) = points[i].y * points[i].y;
        m(i, 2) = points[i].x;
        m(i, 3) = points[i].y;
        m(i, 4) = 1.0;
    }

    return -0.5 * getDeterminant(m);
}

double getA22(Point points[5])
{
    Matrix m(5);

    for (int i = 0; i < 5; i++)
    {    
        m(i, 0) = points[i].x * points[i].x;
        m(i, 1) = points[i].x * points[i].y;
        m(i, 2) = points[i].x;
        m(i, 3) = points[i].y;
        m(i, 4) = 1.0;
    }

    return getDeterminant(m);
}

double getB1(Point points[5])
{
    Matrix m(5);

    for (int i = 0; i < 5; i++)
    {    
        m(i, 0) = points[i].x * points[i].x;
        m(i, 1) = points[i].x * points[i].y;
        m(i, 2) = points[i].y * points[i].y;
        m(i, 3) = points[i].y;
        m(i, 4) = 1.0;
    }

    return -0.5 * getDeterminant(m);
}

double getB2(Point points[5])
{
    Matrix m(5);

    for (int i = 0; i < 5; i++)
    {    
        m(i, 0) = points[i].x * points[i].x;
        m(i, 1) = points[i].x * points[i].y;
        m(i, 2) = points[i].y * points[i].y;
        m(i, 3) = points[i].x;
        m(i, 4) = 1.0;
    }

    return 0.5 * getDeterminant(m);
}

double getC(Point points[5])
{
    Matrix m(5);

    for (int i = 0; i < 5; i++)
    {    
        m(i, 0) = points[i].x * points[i].x;
        m(i, 1) = points[i].x * points[i].y;
        m(i, 2) = points[i].y * points[i].y;
        m(i, 3) = points[i].x;
        m(i, 4) = points[i].y;
    }

    return -getDeterminant(m);
}



QuadricInvariants getInvariants(Point points[5])
{
    double a11 = getA11(points);
    double a12 = getA12(points);
    double a22 = getA22(points);

    double b1 = getB1(points);
    double b2 = getB2(points);

    double c = getC(points);

    QuadricInvariants res =
    {
        .I1 = a11 + a12,
        .I2 = a11*a22 - a12*a12,
        .I3 = a11*a22*c + 2*a12*b2*b1 - a22*b1*b1 - a12*a12*c - a11*b2*b2,
        .K  = (a11 + a22)*c - b1*b1 - b2*b2
    };
    
    return res;
}



QuadricType getQuadricType(QuadricInvariants inv)
{
    return
        isZero(inv.I2)
        ? isZero(inv.I3)
          ? isZero(inv.K)
            ? Line
            : inv.K > 0
              ? ImaginaryParallelLines
              : ParallelLines
          : Parabola
        : inv.I2 > 0
          ? isZero(inv.I3)
            ? SinglePoint
            : inv.I1*inv.I3 < 0
              ? Ellips
              : ImaginaryEllips
          : isZero(inv.I3)
            ? CrossLines
            : Hyperbola;
}
