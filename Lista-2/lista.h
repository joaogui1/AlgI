#include <stdlib.h>

struct Node{
  int value;
  struct Node* next;
};
typedef struct Node node;

struct List{
  node *start, *end;
};
typedef struct List list;

node *new_node(int value);

list *new_list();

void free_list(list *l, int n);

void add_node(list *l, node *n);

void remove_node(node *ant, node *n);
