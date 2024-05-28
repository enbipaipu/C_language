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
    int n; // 要素数 (The number of elements)
    Tweet tweets[100];
} Diary;

Diary *create_diary()
{
    Diary *d = (Diary *)malloc(sizeof(Diary));
    d->n = 0; // 初めの要素数は 0 (The number of elements starts by 0)
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

    add_tweet(diary, "Hello, World!");
    add_tweet(diary, "My second tweet!");
    add_tweet(diary, "My third tweet!");

    Tweet *tw = get_tweet(diary, 1);
    remove_tweet(diary, tw);

    add_tweet(diary, "My last tweet!");

    print_tweets(diary);

    return 0;
}
