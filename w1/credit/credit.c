#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

string get_card_number()
{
    string s;

    do
    {
        s = get_string("Number: ");
    }
    while (strlen(s) <= 0);

    return s;
}

int chr2int(char chr)
{
    return chr - '0';
}

bool valid_card(string cn)
{
  int size = strlen(cn);
  bool valid = false;

  int total = 0;

  for (int i = size - 1; i >= 0; i -= 2) {
    int digit = chr2int(cn[i]);
    total += digit;
  }

  for (int i = size - 2; i >= 0; i -= 2) {
    int digit = chr2int(cn[i]);

    digit *= 2;
    if (digit > 9) digit -= 9;

    total += digit;
  }

  return total % 10 == 0;
}

void print_card(string cn)
{
    char c[4];
    int size = strlen(cn);
    sprintf(c, "%c%c", cn[0], cn[1]);

    int fc = atoi(c);

    if ((fc == 34 || fc == 37) && size == 15)
    {
        printf("AMEX\n");
    }
    else if ((fc >= 40 && fc <= 49) && (size == 13 || size == 16))
    {
        printf("VISA\n");
    }
    else if ((fc >= 51 && fc <= 55) && size == 16)
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

int main()
{
    string cn;
    // string cn = get_card_number();

    cn = "4003600000000014"; // Example VISA (20)

    // cn = "378282246310005"; // AMEX
    // cn = "371449635398431"; // AMEX
    // cn = "4222222222222"; // VISA
    // cn = "1234567890"; // INVALID (a)
    // cn = "4062901840"; // INVALID (l)
    // cn = "4222222222223"; // INVALID (c)
    // cn = "430000000000000"; // VISA
    
    bool is_valid = valid_card(cn);

    if (is_valid)
        print_card(cn);
    else
        printf("INVALID\n");
}
