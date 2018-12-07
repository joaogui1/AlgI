#include "BST.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    elem info;
    struct _node *left, *right;
} node;

struct _bst {
    node *root;
};

node *createNodeBST(elem x) {
    node *ret = malloc(sizeof(node));
    ret->left = ret->right = NULL;
    ret->info = x;
    return ret;
}

void destroyNodeBST(node *n) {
    //processamento em pós ordem para liberar memoria
    if(n == NULL) return;
    if(n->left != NULL)  destroyNodeBST(n->left);
    if(n->right != NULL)  destroyNodeBST(n->right);
    free(n);
}

node *searchNodeBST(node *n, elem x) {
    // busca iterativa, percorrendo a árvore de acordo 
    // aos valores encontrados (direta, se o nó for menor
    // do que x, esquerda se for maior)
    while(n != NULL && n->info != x){
        if(n->info > x) n = n->left;
        else if(n->info < x) n = n->right;
    }

    return n;
}

int insertNodeBST(node **root, elem x){
    //inserção iterativa, utilizando ponteiro duplo
    //para alterar valores na memória
    node **n = root;

    //percorre arvore procurando posição para inserir
    while (*n != NULL){
        if ((*n)->info > x) {
            n = &(*n)->left;
        } else if((*n)->info < x) {
            n = &(*n)->right;
        } else {
            return 1; //erro - valor já existe na arvore
        }
    }

    *n = createNodeBST(x);
    return 0;
}

//retorna quantidade de filhos de um nó
int getChildrenBST(node* n) {
    return (n->left != NULL) + (n->right != NULL);
}

//retorna o maior filho menor que n
node *getGreatestLeft(node* n) {
    node* aux = n->left;
    while(aux->right != NULL) {
       aux = aux->right;
    }
    return aux;
}


int removeNodeBST(node **n, elem x){

    //busca elemento para remover
    *n = searchNodeBST(*n, x);
    if((*n) == NULL)  return 1;

    //remoção feita de acordo à quantidade de filhos do nó
    node *aux;
    int children = getChildrenBST((*n));

    if(children == 0) { // folha - só tira
        free((*n));
        (*n) = NULL;
        return 0;
    }
    else if(children == 1) { // 1 filho - ele vira filho do avô
        aux = ((*n)->left != NULL) ? (*n)->left : (*n)->right;;
        free((*n));
        (*n) = aux;
    }
    else { // 2 filhos - ele vira o maior menor elemento 
        aux = getGreatestLeft((*n)); 
        (*n)->info = aux->info;
        removeNodeBST(&(*n)->left, (*n)->info);
    }

    return 0;
}

void internalPrintBST(node* n, int hight) {
    if (n == NULL) {
        putchar('\n');
        return;
    }
    internalPrintBST(n->right, hight + 1);
    for (int i = 0; i < hight; i++) putchar('\t');
    printf("[%d]\n", n->info);
    internalPrintBST(n->left, hight + 1);
}


//-----funções encapsuladas para a chamada do usuário------
BST *createBST() {
    BST *ret;
    ret = calloc(1, sizeof(BST));
    return ret;
}

void destroyBST(BST *t) {
    destroyNodeBST(t->root);
}

int searchBST(BST *t, elem x) {
    node* ans = searchNodeBST(t->root, x);
    return ans != NULL;
}

int insertBST(BST *t, elem x) {
    return insertNodeBST(&(t->root), x);
}

int removeBST(BST *t, elem x) {
    return removeNodeBST(&t->root, x);
}

void printBST(BST* t) {
    internalPrintBST(t->root, 0);
}
