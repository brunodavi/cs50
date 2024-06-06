# include <cs50.h>
# include <stdio.h>

int main(void)
{
  int x = get_int("Type X value: ");
  int y = get_int("Type Y value: ");

  if (x < y) {
    printf("x less than y\n");
  } else if (x > y) {
    printf("x greater than y\n");
  } else {
    printf("x is equal to y\n");
  }
}
