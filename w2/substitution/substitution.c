#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

int usage() {
  printf("Usage: ./substitution key\n");
  return 1;
}

void init_cipher(string key, char cipher[])
{
  for (int i = 0; i < 26; i++)
  {
    char chr = key[i];

    if ( isalpha(chr) ) {
      int index = 'A' + i;
      char chr_key = toupper(chr);

      cipher[index] = chr_key;
    }
  }
}

void encrypt(string text, char cipher[])
{
  for (int i = 0; i < strlen(text); i++) {
    char chr = text[i];

    if ( isalpha(chr) ) {
      int chr_i = toupper(chr);
      char chr_key = cipher[chr_i];

      text[i] = (
        islower(chr)
          ? tolower(chr_key)
          : chr_key
      );
    }
  }
}

int main(int argc, string argv[])
{
  if (argc != 2) return usage();

  string key = argv[1];

  if (strlen(key) != 26) {
    printf("Key must contain 26 characters.\n");
    return 1;
  }

  char cipher['A' + 26];
  init_cipher(key, cipher);

  string text = get_string("plaintext: ");
  encrypt(text, cipher);

  printf("ciphertext: %s\n", text);
  return 0;
}
