#include <cs50.h>
#include <stdio.h>

int get_height()
{
    int n;

    do
    {
        n = get_int("Height: ");
    }
    while (n < 1);

    return n;
}

void print_row(int n, string chr)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s", chr);
    }
}

int main(void)
{
    int h = get_height();

    for (int i = 1; i <= h; i++)
    {
        print_row(h - i, " ");
        print_row(i, "#");
        printf("  ");
        print_row(i, "#");

        printf("\n");
    }
}
