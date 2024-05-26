#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void divide_name(const char *name, char **firstname, char **surname)
{
    const char *p = strchr(name, ' ');
    char *s = (char *)malloc(p - name + 1);

    memcpy(s, name, p - name);
    s[p - name] = '\0';

    *firstname = s;

    *surname = strdup(p + 1);
}

int main()
{
    char *fname, *sname;

    divide_name("Enryo Inoue", &fname, &sname);

    printf("%s %s\n", &fname, &sname);

    return 0;
}