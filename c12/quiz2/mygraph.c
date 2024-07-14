#include <math.h>

typedef struct
{
    double x, y;
} Point;

double distance(const Point *A, const Point *B)
{
    double xdiff = A->x - B->x;
    double ydiff = A->y - B->y;
    return sqrt(xdiff * xdiff + ydiff * ydiff);
}