#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

bool issentence(char chr)
{
  return (
    chr == '.' ||
    chr == '!' ||
    chr == '?'
  );
}

void counter_lsw(int *lsw, string text)
{
  int l = 0;
  int s = 0;
  int w = 1;

  for (int i = 0; i < strlen(text); i++) {
    char chr = text[i];

    if (isalpha(chr)) l++;
    if (issentence(chr)) s++;
    if (isspace(chr)) w++;
  }

  lsw[0] = l;
  lsw[1] = s;
  lsw[2] = w;
}

int main(void)
{
  string text = get_string("Text: ");

  int lsw[3];

  counter_lsw(lsw, text);

  int letters = lsw[0];
  int sentences = lsw[1];
  int words = lsw[2];

  float L = ((float)letters / words) * 100;
  float S = ((float)sentences / words) * 100;

  int index = round(0.0588 * L - 0.296 * S - 15.8);

  if (index < 1)
    printf("Before Grade 1");
  else if (index >= 1 && index <= 16)
    printf("Grade %i", index);
  else if (index > 16)
    printf("Grade 16+");

  printf("\n");
  }
