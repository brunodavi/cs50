#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void usage()
{
  printf("Usage: ./caesar key\n");
}

char rotate(char chr, int key)
{
  key = key % 26;

  string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int rotation = toupper(chr) - 'A';
  
  do
  {
    rotation++;
    if (rotation >= 26) rotation = 0;

    key --;
  } while (key > 0);

  return (
    isupper(chr)
      ? alpha[rotation]
      : tolower(alpha[rotation])
  );
}

int main(int argc, char *argv[])
{
  if (argc == 1 || argc >= 3 || isalpha(argv[1][0])) {
    usage();
    return 1;
  }

  int key = atoi(argv[1]);

  string plaintext = get_string("plaintext: ");
  int len = strlen(plaintext);

  for (int i = 0; i < len; i++)
  {
    char chr = plaintext[i];

    if (isalpha(chr))
      plaintext[i] = rotate(chr, key);
  }

  printf("ciphertext %s\n", plaintext);
  return 0;
}
