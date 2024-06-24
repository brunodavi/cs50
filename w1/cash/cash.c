#include <cs50.h>
#include <stdio.h>

int get_cents()
{
    int cents = 0;

    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents <= 0);

    return cents;
}

int main(void)
{
    int cents = get_cents();
    int coins = 0;
    int rest = 0;

    int values[4] = {25, 10, 5, 1};

    for (int i = 0; i < 4; i++)
    {
        int value = values[i];

        if (cents >= value)
        {
            rest = cents % value;
            coins += (cents - rest) / value;
            cents = rest;
        }
    }

    printf("%i\n", coins);
}
