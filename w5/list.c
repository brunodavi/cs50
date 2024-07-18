#include <stdlib.h>

int main()
{
  // List size 3
  int *list = malloc(3 * sizeof(int));
  if (list == NULL) return 1;

  list[0] = 1;
  list[1] = 2;
  list[2] = 3;

  // List size 4
  int *tmp = malloc(4 * sizeof(int));
  if (tmp == NULL)
  {
    free(list);
    return 1;
  }

  // Copy 3 items at list in tmp
  for (int i = 0; i < 3; i++)
    tmp[i] = list[i];

  tmp[3] = 4;
  free(list);

  list = tmp;

  for (int i = 0; i < 4; i++)
    printf(
      "list[%p]=%i -- tmp[%p]=%i\n",
      list,
      list[i],

      tmp,
      tmp[i]
    );

  free(list);
  return 0;
}
