#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

void usage()
{
  printf("Usageu: ./caesar key\n");
}

int main(int argc, char *argv[])
{
  if (argc == 1 || argc >= 3) {
    usage();
    return 1;
  }

  int key = atoi(argv[1]);

  string plaintext = get_string("plaintext: ");
  int len = strlen(plaintext);

  for (int i = 0; i < len; i++)
  {
    char chr = plaintext[i];

    if (isalpha(chr)) {
      char cipher = (chr + key) % 26;

      plaintext[i] = cipher;
    }
  }

  printf("ciphertext %s\n", plaintext);
  return 0;
}
