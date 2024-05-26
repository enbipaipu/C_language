#include <stdio.h>
#include <math.h>

typedef struct figure
{
    enum
    {
        RECTANGLE,
        CIRCLE,
    } type;

    union
    {
        struct
        {
            int height;
            int width;
        } rectangle;
        struct
        {
            int radius;
        } circle;
    };

} figure;

double area(const figure *p)
{
    double result;
    switch (p->type)
    {
    case RECTANGLE:
        result = (p->rectangle.height) * (p->rectangle.width);
        break;
    case CIRCLE:
        result = (p->circle.radius) * (p->circle.radius) * M_PI;
        break;
    }
    return result;
}

int main()
{
    figure re = {
        .type = RECTANGLE,
        .rectangle = {.height = 3, .width = 4},
    };
    figure ci = {
        .type = CIRCLE,
        .circle = {.radius = 3},
    };

    printf("RECTANGLE = %f\n", area(&re));
    printf("CIRCLE = %f\n", area(&ci));

    return 0;
}