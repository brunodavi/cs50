#include <stdio.h>
#include <stdlib.h>

int get_int()
{
  int i;

  scanf("%i", &i);

  return i;
}

char *get_string()
{
  char *s = malloc(4);
  if (s == NULL) return "";

  scanf("%s", s);

  return s;
}

int main()
{
  printf("x: ");
  int x = get_int();

  printf("y: ");
  char *y = get_string();

  printf("----\n");
  printf("x: %i\n", x);
  printf("y: %s\n", y);

  free(y);
}
