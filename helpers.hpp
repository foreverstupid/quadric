#ifndef QUADRIC_HELPERS_MODULE_HPP
#define QUADRIC_HELPERS_MODULE_HPP

#include <cmath>

/* almost zero absolute value */
#define EPS 1e-12



/*
 * Checks whether the given double is almost zero or not.
 */
inline bool isZero(double a)
{
    return fabs(a) < EPS;
}

#endif
