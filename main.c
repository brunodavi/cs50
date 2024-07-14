#include <stdio.h>

void bubble_sort(int arr[])
{
  int i = 0;

  while (arr[i + 1] != '\0') {
    int j = i + 1;
    int ai = arr[i];
    int aj = arr[j];

    if (ai > aj)
    {
      arr[i] = aj;
      arr[j] = ai;

      if (i > 0) i--;
    }
    else i++;
  }
}

int main()
{
  int arr[] = { 3, 8, 5, 1, 7, 6, 2, 3 };
  bubble_sort(arr);

  for (int idx = 0; arr[idx] != '\0'; idx++)
    printf("%i\n", arr[idx]);
}
