#include <stdio.h>

int main()
{
  char *s = "Hi!";

  printf("%c\n", s[0]);
  printf("%c\n", s[1]);
  printf("%c\n", s[2]);

  printf("\n");

  printf("%c\n", *s);
  printf("%c\n", *(s + 1));
  printf("%c\n", *(s + 2));
}
