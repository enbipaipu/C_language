#include <stdio.h>

static int saving = 0;

int withdraw(int amount)
{

    if (saving >= amount)
    {
        saving -= amount;
        return 1;
    }
    else
    {
        return 0;
    }
}
void deposit(int amount)
{
    saving += amount;
}

int balance()
{
    return saving;
}

int main()
{
    int ok;

    deposit(300);
    ok = withdraw(500);
    printf("Transaction %s\n", ok ? "succeeded" : "failed");

    deposit(400);

    ok = withdraw(500);
    printf("Transaction %s\n", ok ? "succeeded" : "failed");

    printf("Final balance = %d\n", balance());
    return 0;
}