#include <stdio.h>
typedef enum week
{
    SUN,
    MON,
    TUE,
    WED,
    THU,
    FRI,
    SAT
} week;

typedef enum color
{
    BLACK = 0,
    RED = 2,
    BLUE = 1
} color;

int main()
{
    week w = SAT;
    color c;

    switch (w)
    {
    case SUN:
        c = RED;
        break;

    case SAT:
        c = BLUE;
        break;
    default:
        c = BLACK;
        break;
    }
    printf("week = %d, color = %d\n", w, c);
    return 0;
}