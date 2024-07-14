#include <stdio.h>

void swap(int a, int b)
{
  int tmp = a;

  a = b;
  b = tmp;
}

void swap_mem(int *a, int *b)
{
  int tmp = *a;

  *a = *b;
  *b = tmp;
}

int main()
{
  char *msg = "x=%i & y=%i\n";

  int x = 1;
  int y = 2;

  printf("Swap\n");
  printf(msg, x, y);
  swap(x, y);
  printf(msg, x, y);

  printf("\n");

  printf("Swap Memory\n");
  printf(msg, x, y);
  swap_mem(&x, &y);
  printf(msg, x, y);
}
