#include <cstdio>
#include "quadric.hpp"

const char *typeNames[9] =
{
    "Ellips",
    "Parabola",
    "Hyperbola",

    "Line",
    "Parallel lines",
    "Crossing lines",

    "Point",
    "Imaginary ellips",
    "Imaginary parallel lines"
};



void printType(QuadricType type)
{
    printf("%s\n", typeNames[type]);
}



int main(int argc, char **argv)
{
    Point points[5];
    for (int i = 0; i < 5; i++)
    {
        sscanf(argv[2 * i + 1], "%lf", &(points[i].x));
        sscanf(argv[2 * i + 2], "%lf", &(points[i].y));
    }

    QuadricInvariants inv = getInvariants(points);
    QuadricType type = getQuadricType(inv);

    printType(type);

    return 0;
}
