#include <stdio.h>

typedef struct person /* <-このperson抜きの無名構造体にすることも可能 */
{
    char name[10];
    int age;
} person;

void show_person(const person *someone)
{
    printf("%s (%d)\n", someone->name, someone->age);
}

int main()
{
    person enryo =
        {
            .name = "Enryo",
            .age = 24,
        };

    show_person(&enryo);
    return 0;
}