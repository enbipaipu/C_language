#include <stdio.h>

typedef enum
{
    Shoyu,
    Miso,
    Shio,
    Tonkotsu
} Flavor;

#define OPT_LARGE (0x01)
#define OPT_SEAWEED (0x02)
#define OPT_EGG (0x04)
#define OPT_PORK (0x08)
#define OPT_ONION (0x10)

typedef struct
{
    Flavor flavor;
    __uint32_t options;
} Ramen;

int ramen_price(const Ramen *r)
{
    int price = (r->flavor == Miso) ? 700 : 650;

    if (r->options & OPT_LARGE)
        price += 100;
    if (r->options & OPT_SEAWEED)
        price += 50;
    if (r->options & OPT_EGG)
        price += 50;
    if (r->options & OPT_PORK)
        price += 150;
    if (r->options & OPT_ONION)
        price += 50;

    return price;
}

int main()
{
    Ramen myramen = {
        .flavor = Shoyu,
        .options = OPT_SEAWEED | OPT_EGG,
    };

    printf("price: %d yen\n", ramen_price(&myramen));
    return 0;
}