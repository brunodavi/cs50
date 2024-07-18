#include <stdio.h>
#include <stdlib.h>


int BLOCK_SIZE = 512;

typedef uint8_t BYTE;

int usage()
{
  printf("Usage: ./recover FILE\n");
  return 1;
}

void create_name(char str[], int number)
{
  if (number <= 9)
    sprintf(str, "00%i.jpg", number);
  else if (number <= 99)
    sprintf(str, "0%i.jpg", number);
  else if (number <= 999)
    sprintf(str, "%i.jpg", number);
}

int check_border(BYTE b[3])
{
  BYTE s[3] = { 0xff, 0xd8, 0xff };
  BYTE e[3] = { 0x3f, 0xff, 0xd9 };

  if (
    s[0] == b[0] &&
    s[1] == b[1] &&
    s[2] == b[2]
  ) return -1;

  if (
    e[0] == b[0] &&
    e[1] == b[1] &&
    e[2] == b[2]
  ) return 1;

  return 0;
}

 
int main(int argc, char *argv[])
{
  if (argc != 2) return usage();

  FILE *card = fopen(argv[1], "r");
  BYTE buffer[BLOCK_SIZE];

  int img = 0;
  FILE *image;
  char name[7];

  while(fread(buffer, 1, BLOCK_SIZE, card) > 0)
  {
    for (int i = 0; i < BLOCK_SIZE; i += 2)
    {
      if (buffer[i+3] == 0x0)
        printf("fall: %i\n", i+3);

      buffer[i+3] = 2;
    }
  }

  fclose(card);
}
