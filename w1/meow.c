# include <stdio.h>

void meow()
{
  printf("meow\n");
}

void meow_while(int times)
{
  while (times > 0)
  {
    meow();
    times--;
  }
}


void meow_for(int times)
{
  for (int i = 1; i <= times; i++)
  {
    meow();
  }
}

int main(void)
{
  meow_for(3);
}

