#include <stdio.h>

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

  int img_number = 0;
  FILE *image;
  char name[7];

  int creating = 0;

  while(fread(buffer, 1, BLOCK_SIZE, card) > 0)
  {
    for (int i = 0; i < BLOCK_SIZE; i++)
    {

      BYTE bytes[3] = {
        buffer[i],
        buffer[i + 1],
        buffer[i + 2],
      };

      BYTE byte_write[1] = { buffer[i] };

      switch (check_border(bytes)) {
        case -1:
          creating = 1;
          create_name(name, img_number);
          image = fopen(name, "w");
          img_number++;

        case 0:
          if (creating == 1)
            fwrite(byte_write, 1, 1, image);
          break;

        case 1:
          creating = 0;
          fwrite(bytes, 3, 1, image);
          i += 2;
          fclose(image);
          break;
      }
    }
  }

  fclose(card);
}
