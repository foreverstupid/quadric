#ifndef QUADRIC_QUADRIC_MODULE_HPP
#define QUADRIC_QUADRIC_MODULE_HPP

#include "matrix.hpp"

/* almost zero absolute value */
#define EPS 1e-12



/*
 * The type of the quadric line.
 */
enum QuadricType
{
    Ellips,
    Parabola,
    Hyperbola,

    Line,
    ParallelLines,
    CrossLines,

    SinglePoint,
    ImaginaryEllips,
    ImaginaryParallelLines
};



/*
 * The invariants of the quadric line.
 */
struct QuadricInvariants
{
    double I1;
    double I2;
    double I3;
    double K;
};



/*
 * The point on the plane.
 */
struct Point
{
    double x;
    double y;
};



/*
 * Gets the invariants of the quadric line, that contains the
 * given points.
 * 
 * Note: the quadric line is defined by the following equation:
 *       a11*x^2 + 2*a12*x*y + a22*y^2 + 2*b1*x + 2*b2*y + c = 0
 *
 *       The quadric line that contains the given
 *       points has to satisfy the following equation:
 *
 *       | x^2   x*y    y^2   x   y   1 |
 *       | x1^2  x1*y1  y1^2  x1  y1  1 |
 *       | x2^2  x2*y2  y2^2  x2  y2  1 | = 0
 *       | x3^2  x3*y3  y3^2  x3  y3  1 |
 *       | x4^2  x4*y4  y4^2  x4  y4  1 |
 *       | x5^2  x5*y5  y5^2  x5  y5  1 |
 *
 *       Thus, we can find coefficients a, b, and c as respective
 *       coefficients of the last equation.
 */
QuadricInvariants getInvariants(Point point[5]);



/*
 * Returns the type of the quadric line of the given inveriants.
 */
QuadricType getQuadricType(QuadricInvariants inv);



/*
 * Checks whether the given double is almost zero or not.
 */
inline bool ifZero(double a)
{
    return fabs(a) < EPS;
}

#endif
