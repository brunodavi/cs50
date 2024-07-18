#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int number;
  struct node *next;
}
node;

int main(int argc, char *argv[])
{
  node *list = NULL;
  node *n = malloc(sizeof(node));

  if (n == NULL) return 1;

  n->number = 1;
  n->next = NULL;

  list = n;
  n = malloc(sizeof(node));
  if (n == NULL) return 1;

  n->number = 2;
  n->next = NULL;

  n->next = list;
  list = n;

  printf(
    "l=%i ln=%i\n",
    list->number,
    list->next->number
  );

  printf(
    "n=%i nn=%i\n",
    n->number,
    n->next->number
  );
}
