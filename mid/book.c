#include <stdio.h>
#include <string.h>

typedef struct
{
    char title[40];
    int price;
} Book;

void init_book(Book *p, char *title, int price)
{
    strcpy(p->title, title);
    p->price = price;
}

int main()
{
    Book book;
    init_book(&book, "Dragon Ball", 400);
    printf("%s (%d)\n", book.title, book.price);
    return 0;
}