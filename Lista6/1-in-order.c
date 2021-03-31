#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node {
    int valor;
    Node *esq;
    Node *dir;
};

