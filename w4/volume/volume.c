#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


const int HEADER_SIZE = 44;


int usage(int exit)
{
  printf("Usage: ./volume input.wav output.wav factor\n");
  return exit;
}

int file_error()
{
  printf("Could not open file.\n");
  return 1;
}


int main(int argc, char *argv[])
{
  if (argc != 4)
    return usage(1);


  FILE *input = fopen(argv[1], "r");

  if (input == NULL)
    return file_error();


  FILE *output = fopen(argv[2], "w");

  if (output == NULL)
    return file_error();


  int factor = atoi(argv[3]);

  uint8_t header[HEADER_SIZE];
  fread(header, HEADER_SIZE, 1, input);
  fwrite(header, HEADER_SIZE, 1, output);


  int16_t buffer;

  while (fread(&buffer, sizeof(int16_t), 1, input) != 0)
  {
    buffer *= factor;

    fwrite(&buffer, sizeof(int16_t), 1, output);
  }

  fclose(input);
  fclose(output);
}
