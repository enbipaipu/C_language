#include <stdio.h>
#include <string.h>

typedef struct date
{
    int year;
    int month;
    int day;
} date;

void data_to_str(const date *d, char *s)
{
    sprintf(s, "%04d-%02d-%02d", d->year, d->month, d->day);
}

int main()
{
    date today = {
        .year = 2021,
        .month = 5,
        .day = 24,

    };
    char i[30];
    data_to_str(&today, i);
    printf("%s\n", i);
    return 0;
}