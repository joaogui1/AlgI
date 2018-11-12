#define elem int
typedef struct node{
  elem info;
  node *left, *right;
} Node;
void DestroyNode(Node *n);
Node *searchNode(Node *n, elem x);
