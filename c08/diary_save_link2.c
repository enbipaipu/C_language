#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct tweet
{
    time_t ts;          // 投稿時刻 (Posted time)
    char msg[280 + 1];  // メッセージ (Message)
    struct tweet *prev; // 一つ前の要素 (Previous element)
    struct tweet *next; // 一つ先の要素 (Next element)
} Tweet;

typedef struct
{
    Tweet *first; // 最初の要素 (First element)
    Tweet *last;  // 最後の要素 (Last element)
} Diary;

Diary *create_diary()
{
    Diary *d = (Diary *)malloc(sizeof(Diary));
    d->first = d->last = NULL;
    return d;
}

Tweet *get_tweet(Diary *d, int index)
{
    Tweet *t = d->first;
    for (int i = 0; i < index; i++)
    {
        t = t->next;
    }
    return t;
}

void remove_tweet(Diary *d, Tweet *t)
{
    Tweet *prev = t->prev;
    Tweet *next = t->next;

    if (prev)
        prev->next = next;
    else
        d->first = next;

    if (next)
        next->prev = prev;
    else
        d->last = prev;

    free(t);
}

void add_tweet(Diary *d, const char *msg)
{
    Tweet *t = (Tweet *)malloc(sizeof(Tweet));

    t->ts = time(NULL);
    strcpy(t->msg, msg);

    t->prev = d->last;
    t->next = NULL;

    if (d->last)
        d->last->next = t;
    d->last = t;
    if (!d->first)
        d->first = t;
}

void print_tweets(const Diary *d)
{
    int i = 0;
    for (Tweet *t = d->last; t; t = t->prev)
    {
        char s[100];
        printf("%d: %s\t%s\n\n", i++, ctime_r(&(t->ts), s), t->msg);
    }
}

int save_diary(const Diary *d)
{
    FILE *fp = fopen("diary.csv", "w");
    if (!fp)
        goto error; // ファイルのオープンに失敗 (Failed to open file)

    char *bom = "\xef\xbb\xbf";

    fputs(bom, fp);

    Tweet *next = d->first;
    while (next)
    {
        fprintf(fp, "%ld,%s\n", next->ts, next->msg);
        next = next->next;
    }

    fclose(fp);
    return 0;

error:
    if (fp)
        fclose(fp);
    return 1;
}

Diary *load_diary()
{
    FILE *fp = fopen("diary.csv", "r");
    if (!fp)
        goto error; // ファイルのオープンに失敗 (Failed to open file)

    Diary *d = (Diary *)malloc(sizeof(Diary));
    if (!d)
        goto error;

    char *bom = "\xef\xbb\xbf";

    char buf[310];

    const int BOM_SIZE = 3;

    fread(buf, 1, BOM_SIZE, fp);
    if (memcmp(buf, bom, BOM_SIZE) != 0)
    {
        fseek(fp, 0, SEEK_SET);
    }

    while (fgets(buf, sizeof(buf), fp))
    {

        char *ts_str = strtok(buf, ",");
        char *text = strtok(NULL, "\n");
        time_t time = (time_t)strtol(ts_str, NULL, 10);

        Tweet *t = (Tweet *)malloc(sizeof(Tweet));
        t->ts = time;
        strcpy(t->msg, text);

        t->prev = d->last;
        t->next = NULL;

        if (d->last)
            d->last->next = t;
        d->last = t;
        if (!d->first)
            d->first = t;
    }

    return d;

error:
    if (fp)
        fclose(fp);
    return NULL;
}

int main()
{
    const char *messages[] = {
        "Hello, INIAD!",
        "How are you?",
        "Enryo sensei is cool!",
    };

    Diary *diary = load_diary();
    if (!diary)
    {
        diary = create_diary();
    }

    add_tweet(diary, messages[0]);
    add_tweet(diary, messages[1]);
    add_tweet(diary, messages[2]);
    save_diary(diary);
    print_tweets(diary);

    return 0;
}
