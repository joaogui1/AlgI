#include "AVL.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct _node {
  elem info;
  int height;
  struct _node *left, *right;
} Node;

struct _avl{
  Node *root;
};


//retorna valor máximo
int max(int a, int b){
  return (a > b) ? a : b;
}

//retorna valor absoluto
int abs(int a){
  return a > 0 ? a : -a;
}

Node* createNodeAVL(elem x){
  Node *ret = calloc(1, sizeof(Node));
  ret->info = x;
  ret->height = 1;
  
  return ret;
}

void destroyNodeAVL(Node *n){
  // processamento em pós ordem para liberar memórias
  if(n == NULL) return;
  if(n->left != NULL)  destroyNodeAVL(n->left);
  if(n->right != NULL)  destroyNodeAVL(n->right);
  free(n);
}

//retorna altura do nó
int getHeight(Node *n){
  return (n == NULL) ? -1 : n->height;
}

//retorna fator de balanceamento do nó
int getBalance(Node *n){
  return getHeight(n->left) - getHeight(n->right);
}

//busca recursiva, retorna ponteiro para nó encontrado
//ou NULL se não for encontrado
Node *searchNodeAVL(Node *n, elem x){
  if(n == NULL || n->info == x) return n;
  if(n->info > x) return searchNodeAVL(n->left, x);
  if(n->info < x) return searchNodeAVL(n->right, x);
  return NULL;
}

//rotação para esquerda
Node *leftRotation(Node *n){
  Node *NewRoot = n->right;
  n->right = NewRoot->left;
  NewRoot->left = n;

  n->height = 1 + max(getHeight(n->left), getHeight(n->right));
  NewRoot->height = 1 + max(getHeight(NewRoot->left), getHeight(NewRoot->right));

  return NewRoot;
}

//rotação para direita
Node *rightRotation(Node *n){
  Node *NewRoot = n->left;
  n->left = NewRoot->right;
  NewRoot->right = n;

  n->height = 1 + max(getHeight(n->left), getHeight(n->right));
  NewRoot->height = 1 + max(getHeight(NewRoot->left), getHeight(NewRoot->right));

  return NewRoot;
}

//rotação para a esqueda e depois direita
Node *leftRightRotation(Node *n){
  n->left = leftRotation(n->left);
  return rightRotation(n);
}

//rotação para a direita e depois esquerda
Node *rightLeftRotation(Node *n){
  n->right = rightRotation(n->right);
  return leftRotation(n);
}

//balanceia a árvore, chamando funções de rotação
Node *bringBalance(Node *n){
  int balance = getBalance(n);
  if(balance >= 0)
    return getBalance(n->left) < 0 ? n = leftRightRotation(n) : rightRotation(n);
  else
    return getBalance(n->right) > 0 ? n = rightLeftRotation(n) : leftRotation(n);
}

//percorre recursivamente a árvore para encontrar posição para inserir
//cria e insere nó. Por fim, atualiza alturas
Node *insertNodeAVL(Node *n, elem x, int *erro){
  int BalanceFactor;
  if(n == NULL) n = createNodeAVL(x);
  else if(n->info > x)  n->left = insertNodeAVL(n->left, x, erro);
  else if(n->info < x)  n->right = insertNodeAVL(n->right, x, erro);
  else{ //erro - elemento já existe
    *erro = 1; 
    return n;
  }

  n->height = 1 + max(getHeight(n->left), getHeight(n->right));
  BalanceFactor = getBalance(n);
  if(abs(BalanceFactor) > 1)  return bringBalance(n);

  return n;
}

//retorna a quantidade de filhos de um nó
int getChildrenAVL(Node* n){
    return (n->left != NULL)  + (n->right != NULL);
}

Node *removeNodeAVL(Node *n, elem x, int *erro){
  if(n == NULL){
    *erro = 1;
    return NULL;
  }
  int children = 0;
  Node *aux, *AuxParent;

  //busca nó
  if(n->info > x) n->left = removeNodeAVL(n->left, x, erro);
  else if(n->info < x) n->right =  removeNodeAVL(n->right, x, erro);
  else if(n->info == x){
    //remoção depende da quantidade de filhos do nó
    int children = getChildrenAVL(n);

    if(children == 0){
      free(n);
      n = NULL;
      return n;
    }
    else if(children == 1){
      aux = (n->left != NULL) ? n->left : n->right;;
      free(n);
      n = aux;
    }
    else{
      aux = n->left;
      while(aux->right != NULL){
        aux = aux->right;
      }

      n->info = aux->info;
      n->left = removeNodeAVL(n->left, n->info, erro);
    }

  }

  //após remover, é preciso rebalancear
  n->height = 1 + max(getHeight(n->left), getHeight(n->right));
  int BalanceFactor = getBalance(n);
  if(abs(BalanceFactor) > 1)  return bringBalance(n);

  return n;
}

void internalPrint(Node* n, int hight) {
    if (n == NULL) {
        putchar('\n');
        return;
    }
    internalPrint(n->right, hight + 1);
    for (int i = 0; i < hight; i++) putchar('\t');
    printf("[%d]\n", n->info);
    internalPrint(n->left, hight + 1);
}


//-----funções encapsuladas para a chamada do usuário------
AVL *createAVL(){
  AVL *ret;
  ret = calloc(1, sizeof(AVL));
  return ret;
}

void destroyAVL(AVL *t){
  destroyNodeAVL(t->root);
}

int searchAVL(AVL *t, elem x){
  Node* ans = searchNodeAVL(t->root, x);
  return (ans != NULL);
}

int insertAVL(AVL *t, elem x){
  int erro = 0;
  t->root = insertNodeAVL(t->root, x, &erro);
  return erro;
}

int removeAVL(AVL *t, elem x){
  int erro = 0;
  t->root = removeNodeAVL(t->root, x, &erro);
  return erro;
}

void printAVL(AVL* t) {
    internalPrint(t->root, 0);
}