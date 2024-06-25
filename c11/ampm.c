#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline char *change(char *aorp)
{
    return (strcmp(aorp, "AM") == 0) ? "午前" : "午後";
}

int main(int argc, char *argv[])
{

    int time = atoi(argv[1]);

    char *aorp = "AM";

    if (time > 12)
    {

        aorp = "PM";
        time -= 12;
    };

    if (strcmp(argv[2], "-DLANG=1") == 0)
    {

        char *hour = change(aorp);

        printf("%s%dです\n", hour, time);
    }
    else
    {
        printf("It's %d%s\n", time, aorp);
    };
    return 0;
}