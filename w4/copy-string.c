#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char *s = get_string("s: ");
  int size = strlen(s);

  if (s == NULL) return 1;

  // Space in memory
  char *t = malloc(size + 1);

  // Space in memory
  char u[size];

  // Space in memory
  char *v = malloc(size + 1);

  // Copy string
  strcpy(v, s);

  // Copy chars
  for (int i = 0; i <= size; i++)
  {
    t[i] = s[i];
    u[i] = s[i];
  }

  t[0] = toupper(t[0]);
  u[0] = toupper(u[0]);
  v[0] = toupper(v[0]);

  printf("%s\n\n", s);

  printf("t=%s\n", t);
  printf("u=%s\n", u);
  printf("v=%s\n", v);
}
