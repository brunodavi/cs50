#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool strin(char chr, char *str)
{
  for (int i = 0; i < strlen(str); i++) {
    if (chr == str[i]) return true;
  }
  return false;
}

int letter_score(char letter)
{
  if (!isupper(letter) && !islower(letter)) {
    return 0;
  }

  char *p1 = "AEILNORSTU";
  char *p2 = "DG";
  char *p3 = "BCP";
  char *p4 = "FHVWY";
  char *p5 = "K";
  char *p8 = "JX";
  char *p10 = "QZ";

  if(strin(letter, p1)) return 1;
  if(strin(letter, p2)) return 2;
  if(strin(letter, p3)) return 3;
  if(strin(letter, p4)) return 4;
  if(strin(letter, p5)) return 5;
  if(strin(letter, p8)) return 8;
  if(strin(letter, p10)) return 10;

  return 0;
}

int compute_score(char *word)
{
  int counter = 0;

  for (int i = 0; i < strlen(word); i++) {
    char chr = word[i];
    chr = toupper(chr);
    counter += letter_score(chr);
  }

  return counter;
}

int main(void)
{
  char *player1 = get_string("Player 1: ");
  char *player2 = get_string("Player 2: ");

  int score1 = compute_score(player1);
  int score2 = compute_score(player2);

  if (score1 > score2) {
    printf("Player 1 wins!\n");
  } else if (score1 < score2) {
    printf("Player 2 wins!\n");
  } else {
    printf("Tie!\n");
  }
}
