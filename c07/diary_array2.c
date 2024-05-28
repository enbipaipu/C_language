#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct
{
    time_t ts;         // 投稿時刻 (Posted time)
    char msg[280 + 1]; // メッセージ (Message)
} Tweet;

typedef struct
{
    int size;
    int n; // 要素数 (The number of elements)
    Tweet *tweets;
} Diary;

Diary *create_diary()
{
    int N = 100;
    Diary *d = (Diary *)malloc(sizeof(Diary));
    d->size = N;
    d->n = 0; // 初めの要素数は 0 (The number of elements starts by 0)
    d->tweets = (Tweet *)malloc(N * sizeof(Tweet));
    return d;
}

Tweet *get_tweet(Diary *d, int index)
{
    return &(d->tweets[index]);
}

void remove_tweet(Diary *d, Tweet *t)
{
    int remove_index = t - d->tweets;

    d->n--; // 要素数を1減らす (Decrement number of elements by one)

    for (int i = remove_index; i < d->n; i++)
    {
        d->tweets[i] = d->tweets[i + 1];
    }
}

void add_tweet(Diary *d, const char *msg)
{
    if (d->n >= d->size)
    {
        d->tweets = realloc(d->tweets, d->size + 1);
        printf("increase memory \n");
    }
    d->tweets[d->n].ts = time(NULL);
    strcpy(d->tweets[d->n].msg, msg);

    d->n++; // 要素数を1増やす (Increment number of elements by one)
}

void print_tweets(const Diary *d)
{
    for (int i = 0; i < d->n; i++)
    {
        char s[100];
        printf("%d: %s\t%s\n\n", i, ctime_r(&(d->tweets[d->n - i - 1].ts), s), d->tweets[d->n - i - 1].msg);
    }
}

int main()
{
    Diary *diary = create_diary();

    for (int n = 0; n < 110; n++)
    {
        char str[20];
        sprintf(str, "%d count", n);
        add_tweet(diary, str);
    }
    printf("finish to cleat tweets\n");

    print_tweets(diary);

    return 0;
}
