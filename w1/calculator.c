# include <stdio.h>
# include <cs50.h>

int main(void)
{
  int x = get_int("X value: ");
  int y = get_int("Y value: ");
  printf("%i\n", x + y);
}
