#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

int usage()
{
  printf("Usage: ./plurality [candidates...]\n");
  return 1;
}

bool stralpha(string str)
{
  for (int i = 0; i < strlen(str); i++)
    if ( ! isalpha(str[i]) )
      return false;

  return true;
}

int index_of(string item, int size, string array[])
{
  for (int i = 0; i < size; i++) {
    if ( strcmp(item, array[i]) == 0 )
      return i;
  }

  return -1;
}

int check_winner(int size, int array[])
{
  int greather = 0;
  int winner = -1;

  for (int i = 0; i < size; i++) {
    int value = array[i];

    if (value > greather) {
      winner = i;
      greather = value;
    }
  }

  return winner;
}


int main(int argc, string argv[])
{
  if (argc <= 1) return usage();

  int size = argc - 1;

  string candidates[argc - 1];
  int votes[size];

  for (int i = 1; i < argc; i++) {
    string arg = argv[i];

    if ( ! stralpha(arg) )
      return usage();
    
    candidates[i-1] = arg;
    votes[i-1] = 0;
  }

  int voters = 0;

  do voters = get_int("Number of voters: ");
  while (voters < 0);

  for (int i = 0; i < voters; i++) {
    string vote = get_string("Vote: ");

    int index = index_of(vote, size, candidates);

    if ( index >= 0 )
      votes[index] += 1;
    else {
      printf("Invalid vote.\n");
      i--;
    }
  }

  int winner = check_winner(size, votes);

  string candidate;

  if (winner < 0) {
    printf("Fall\n");
    return 1;
  }

  candidate = candidates[winner];

  printf("%s\n", candidate);
  return 0;
}
