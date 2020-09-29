#include "quadric.hpp"

QuadricInvariants getInvariants(Point points[5])
{
    Matrix m(5);
    double f[5] = { -1.0, -1.0, -1.0, -1.0, -1.0 };

    for (int i = 0 ; i < 5; i++)
    {
        m(i, 0) = points[i].x * points[i].x;
        m(i, 1) = points[i].x * points[i].y;
        m(i, 2) = points[i].y * points[i].y;
        m(i, 3) = points[i].x;
        m(i, 4) = points[i].y;
    }

    solveGauss(m, f);

    double a11 = f[0];
    double a12 = f[1] * 0.5;
    double a22 = f[2];
    double b1 = f[3] * 0.5;
    double b2 = f[4] * 0.5;
    double c = f[5];

    QuadricInvariants res =
    {
        .I1 = a11 + a22,
        .I2 = a11*a22 - a12*a12,
        .I3 = a11*a22*c + 2*a12*b2*b1 - a22*b1*b1 - a12*a12*c - a11*b2*b2,
        .K  = (a11 + a22)*c - b1*b1 - b2*b2
    };
    
    return res;
}



QuadricType getQuadricType(QuadricInvariants inv)
{
    return
        ifZero(inv.I2)
        ? ifZero(inv.I3)
          ? ifZero(inv.K)
            ? Line
            : inv.K > 0
              ? ImaginaryParallelLines
              : ParallelLines
          : Parabola
        : inv.I2 > 0
          ? ifZero(inv.I3)
            ? SinglePoint
            : inv.I1*inv.I3 < 0
              ? Ellips
              : ImaginaryEllips
          : ifZero(inv.I3)
            ? CrossLines
            : Hyperbola;
}
