#include <stdio.h>
#include "person.h"

#define offsetof(stype, filed) ((unsigned int)&(((stype *)0)->filed))
{
    return (a > b) ? a : b;
}

int main()
{
    printf("sizeof person = %ls\n", sizeof(struct person));
    printf("offset name = %ld\n", offsetof(struct person, name));
    printf("offset age = %ld\n", offsetof(struct person, age));
}