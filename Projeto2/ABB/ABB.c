#include "ABB.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    elem info;
    struct _node *left, *right;
} node;

struct _abb {
    node *root;
};

node *createNodeABB(elem x) {
    node *ret = malloc(sizeof(node));
    ret->left = ret->right = NULL;
    ret->info = x;
    return ret;
}

void destroyNodeABB(node *n) {
    //processamento em pós ordem para liberar memoria
    if(n == NULL) return;
    if(n->left != NULL)  destroyNodeABB(n->left);
    if(n->right != NULL)  destroyNodeABB(n->right);
    free(n);
}

node *searchNodeABB(node *n, elem x) {
    // busca iterativa, percorrendo a árvore de acordo 
    // aos valores encontrados (direta, se o nó for menor
    // do que x, esquerda se for maior)
    while(n != NULL && n->info != x){
        if(n->info > x) n = n->left;
        else if(n->info < x) n = n->right;
    }

    return n;
}

int insertNodeABB(node **root, elem x){
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

    *n = createNodeABB(x);
    return 0;
}

//retorna quantidade de filhos de um nó
int getChildrenABB(node* n) {
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


int removeNodeABB(node **n, elem x){

    //busca elemento para remover
    *n = searchNodeABB(*n, x);
    if((*n) == NULL)  return 1;

    //remoção feita de acordo à quantidade de filhos do nó
    node *aux;
    int children = getChildrenABB((*n));

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
        removeNodeABB(&(*n)->left, (*n)->info);
    }

    return 0;
}

void internalPrint(node* n, int hight) {
    if (n == NULL) {
        putchar('\n');
        return;
    }
    abb_print_debug(n->right, hight + 1);
    for (int i = 0; i < hight; i++) putchar('\t');
    printf("[%d]\n", n->info);
    abb_print_debug(n->left, hight + 1);
}


//-----funções encapsuladas para a chamada do usuário------
ABB *createABB() {
    ABB *ret;
    ret = calloc(1, sizeof(ABB));
    return ret;
}

void destroyABB(ABB *t) {
    destroyNodeABB(t->root);
}

int searchABB(ABB *t, elem x) {
    node* ans = searchNodeABB(t->root, x);
    return ans != NULL;
}

int insertABB(ABB *t, elem x) {
    return insertNodeABB(&(t->root), x);
}

int removeABB(ABB *t, elem x) {
    return removeNodeABB(&t->root, x);
}

void printAbb(ABB* t) {
    internalPrint(t->root, 0);
}
