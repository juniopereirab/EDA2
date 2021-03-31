#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node {
    int valor;
    Node *esq;
    Node *dir;
};

/*
    Pre-order: Visita o no, depois visita o no da esquerda e depois da direita.
    In-order: Visita o no da esquerda, depois visito o no, e depois da direita.
    Pos-order: Visita o no da esquerda, depois da direita e depois o no.
*/

void transversePre (Node *h){
    if(h == NULL) return;

    printf("%d ", h->valor);
    transversePre(h->esq);
    transversePre(h->dir);
}

void transverseIn (Node *h){
    if(h == NULL) return;

    transverseIn(h->esq);
    printf("%d ", h->valor);
    transverseIn(h->dir);
}

void transversePos (Node *h){
    if(h == NULL) return;

    transversePos(h->esq);
    transversePos(h->dir);
    printf("%d ", h->valor);
}

int isEmpty(Node *t){
    return t == NULL;
}

Node* init(){
    return NULL;
}

void insertTree(Node ** t, int num) {
    if(*t == NULL){
        *t = (Node*)malloc(sizeof(Node));
        (*t)->esq = NULL;
        (*t)->dir = NULL;
        (*t)->valor = num; 
    }
    else {
        if(num < (*t)->valor) {
            insertTree(&(*t)->esq, num);
        }
        if(num > (*t)->valor) {
            insertTree(&(*t)->dir, num);
        }
    }
}
int main () {
    Node *h = init();
    int x;

    while(scanf("%d", &x) != EOF){
        insertTree(&h, x);
    }

    transversePre(h);
    printf(".\n");
    transverseIn(h);
    printf(".\n");
    transversePos(h);
    printf(".\n");

    return 0;
}