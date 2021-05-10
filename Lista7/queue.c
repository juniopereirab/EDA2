#include <stdio.h>
#include <stdlib.h>

#define vertex int
#define true 1
#define false 0
typedef int bool;
typedef struct queue *Queue;
typedef struct node *link;

struct node {
    vertex w;
    bool visitado;
    link next;
};

struct queue {
    link front, rear;
};

static link addNodeQueue(vertex w){
    link a = malloc(sizeof(struct node));
    a->w = w;
    a->next = NULL;
    return a;
}

Queue initQueue(){
    Queue Q = malloc(sizeof(*Q));
    Q->front = Q->rear = NULL;
    return Q;
}

bool isEmpty(Queue Q){
    if(Q->front == NULL){
        return(true);
    }
    return(false);
}

void enqueue(Queue Q, int k){
    link a = addNodeQueue(k);
    if(Q->rear == NULL){
        Q->front = Q->rear = a;
        return;
    }

    Q->rear->next = a;
    Q->rear = a;
}

static link dequeue(Queue Q){
    if(isEmpty(Q)){
        return NULL;
    }

    link a = Q->front;
    Q->front = Q->front->next;

    if(Q->front == NULL){
        Q->rear = NULL;
    }

    return a;
}

void freeQueue(Queue Q){
    if(isEmpty(Q)){
        free(Q);
        return;
    }

    while(Q->front){
        link a = Q->front;
        Q->front = Q->front->next;
        free(a);
    }

    free(Q);
}

int main() {
    return 0;
}