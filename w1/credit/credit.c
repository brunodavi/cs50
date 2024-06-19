#include <stdio.h>
#include <cs50.h>
#include <string.h>

string get_card_number()
{
  string s;

  do
  {
    s = get_string("Number: ");
  } while (strlen(s) <= 13);

  return s;
}

int chr2int(char chr)
{
  return chr - '0';
}

bool valid_card(string cn)
{
  int len = strlen(cn);

  int tt1 = 0;
  int tt2 = 0;

  for (int i = 0; i < len; i += 2)
  {
    int n1 = chr2int(cn[i]);
    int n2 = chr2int(cn[i + 1]);

    char sn1[4];
    n1 = (n1 * 2);

    sprintf(sn1, "%i", n1);
    int slen = strlen(sn1);

    if (slen > 1)
    {
      for (int j = 0; j < slen; j++)
      {
        tt1 += chr2int(sn1[j]);
      }
    } else {
      tt1 += n1;
    }

    tt2 += n2;
  }

  int tt = tt1 + tt2;
  char stt[4];

  sprintf(stt, "%i", tt);

  return stt[strlen(stt) - 1] == '0';
}

void print_card(string cn)
{
  char c[4];
  int size = strlen(cn);
  sprintf(c, "%c%c", cn[0], cn[1]);

  int fc = atoi(c);

  if ((fc == 34 || fc == 37) && size == 15) {
    printf("AMEX\n");
  } else if ((fc >= 40 && fc <= 49) && (size >= 13 && size <= 16)) {
    printf("VISA\n");
  } else if ((fc >= 51 && fc <= 55) && size == 16) {
    printf("MASTERCARD\n");
  } else {
    printf("INVALID\n");
  }
}

int main()
{
  string cn = get_card_number();

//  string cn = "4003600000000014";

  bool is_valid = valid_card(cn);

  if (is_valid) {
    print_card(cn);
  } else {
    printf("INVALID\n");
  }
}
