#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    /* const char *messages[] = {
        "Hello, INIAD!",
        "How are you?",
        "Enryo sensei is cool!",
    }; */

    FILE *fp = fopen("test.txt", "r");

    /* for (int i = 0; i < 3; i++)
    {
        fprintf(fp, "%s\n", messages[i]);
    } */

    char buf[128];
    while (fgets(buf, sizeof(buf), fp))
    {
        char *ts_str = strtok(buf, ",");
        char *text = strtok(NULL, "\n");
        if (ts_str && text)
        {
            time_t ts = (time_t)strtol(ts_str, NULL, 10);
            printf("%ld, %s\n", (long)ts, text);
        }
    }

    fclose(fp);
}