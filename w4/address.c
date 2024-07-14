#include <stdio.h>

int main()
{
  int n = 50;
  int *p = &n;
  printf("n=%p p=%p\n", &n, p);
}
