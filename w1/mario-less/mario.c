# include <stdio.h>
# include <cs50.h>

void bricks_x(int n, string chr, bool break_line)
{
  for (int i = 0; i < n; i++) {
    printf("%s", chr);
  }

  if (break_line) printf("\n");
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
    bricks_x(x, chr, true);
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

  bool brk = true;

  while (i <= n) {
    bricks_x(n-i, " ", false);
    if (i >= n) brk = false;
    bricks_x(i, "#", brk);

    i++;
  }
}

