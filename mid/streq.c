#include <stdio.h>
#include <string.h>

int streq(char *s, char *t)
{
    int s_len = strlen(s);
    int t_len = strlen(t);
    if (s_len != t_len)
        return 0;

    for (int i = 0; i < s_len; i++)
    {
        char s_st = s[i];
        char t_st = t[i];

        if (s_st >= 65 && s_st <= 90)
            s_st += 32;

        if (t_st >= 65 && t_st <= 90)
            t_st += 32;

        if (s_st != t_st)
            return 0;
    }

    return 1;
}

int Streq(char *s, char *t)
{

    for (int i = 0; s[i] != '\0'; i++)
    {
        char s_st = s[i];
        char t_st = t[i];

        if (s_st >= 65 && s_st <= 90)
            s_st += 32;

        if (t_st >= 65 && t_st <= 90)
            t_st += 32;

        if (s_st != t_st)
            return 0;
    }

    return 1;
}

int main()
{
    printf("result1: %s\n", Streq("iniad", "iniAD") ? "True" : "False");
    printf("result2: %s\n", streq("INIAD", "INIADINI") ? "True" : "False");
    printf("result3: %s\n", streq("iNiAd", "InIaD") ? "True" : "False");
    return 0;
}