#include <stdio.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
  if (argc != 3) {
    printf("Usage: ./cp source dest\n");
    return 1;
  }

  FILE *src = fopen(argv[1], "rb");
  FILE *dst = fopen(argv[2], "wb");

  BYTE b;

  while (fread(&b, sizeof(b), 1, src) != 0) {
    fwrite(&b, sizeof(b), 1, dst);
  }

  fclose(src);
  fclose(dst);
}
