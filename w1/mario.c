# include <stdio.h>
# include <cs50.h>

void bricks_x(int n, string chr)
{
  for (int i = 0; i < n; i++) {
    printf("%s", chr);
  }
  printf("\n");
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
    n = get_int("Size: ");
  }
  while (n < 1);

  return n;
}

int main()
{

  int n = get_size();

  bricks_x(n, "?");
  bricks_y(n, "#");
  bricks(n, n, "#");
}

