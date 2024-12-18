#include <cs50.h>
#include <stdio.h>

void bricks_x(int n, string chr)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s", chr);
    }
}

void bricks_y(int n, string chr)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", chr);
    }
}

void bricks(int x, int y, string chr)
{
    for (int i = 0; i < y; i++)
    {
        bricks_x(x, chr);
    }
}

int get_size()
{
    int n;

    do
    {
        n = get_int("Height: ");
    }
    while (n < 1);

    return n;
}

int main()
{
    int n = get_size();
    int i = 1;

    while (i <= n)
    {
        bricks_x(n - i, " ");
        bricks_x(i, "#");
        printf("\n");

        i++;
    }
}
