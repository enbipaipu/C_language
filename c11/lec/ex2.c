#include <stdio.h>

typedef enum
{
    Shoyu,
    Miso,
    Shio,
    Tonkotsu
} Flavor;

typedef struct
{
    Flavor flavor;
    int opt_large;
    int opt_seaweed;
    int opt_egg;
    int opt_pork;
    int opt_onion;
} Ramen;

int ramen_price(const Ramen *r)
{
    int price = (r->flavor == Miso) ? 700 : 650;

    if (r->opt_large)
        price += 100;
    if (r->opt_seaweed)
        price += 50;
    if (r->opt_egg)
        price += 50;
    if (r->opt_pork)
        price += 150;
    if (r->opt_onion)
        price += 50;

    return price;
}

int main()
{
    Ramen myramen = {
        .flavor = Shoyu,
        .opt_large = 0,
        .opt_seaweed = 1,
        .opt_egg = 1,
        .opt_pork = 0,
        .opt_onion = 0,
    };
    printf("price: %d yen\n", ramen_price(&myramen));
    return 0;
}