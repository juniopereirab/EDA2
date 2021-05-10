#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
#define vertex int  
typedef int bool;
typedef struct node *link;
typedef struct graph *Graph;

struct node {
    vertex w;
    bool visitado;
    link next;
};

struct graph {
    int V;
    int A;
    link *adj;
};

static link addNode(vertex w, link next){
    link a = malloc(sizeof(struct node));
    a->w = w;
    a->next = next;
    a->visitado = false;
    return a;
}

Graph initGraph(int V){
    Graph G = malloc(sizeof *G);
    G->V = V;
    G->A = 0;
    G->adj = malloc(V * sizeof(link));
    for(vertex v = 0; v < V; ++v){
        G->adj[v] = NULL;
    }
    return G;
}

void addEdge(Graph G, vertex v, vertex w){
    if(!G) return;
    if(v < 0 || v >= G->V) return;
    if(w < 0 || w >= G->V) return;

    for(link a = G->adj[v]; a != NULL; a = a->next){
        if(a->w == w) return;
    }
    G->adj[v] = addNode(w, G->adj[v]);
    G->A++;
}

void BFS(Graph G, vertex s) {
    G->adj[s]->visitado = true;
    for(link a = G->adj[s]; a != NULL; a = a->next){
        if(G->adj[a->w]->visitado == false){
            G->adj[a->w]->visitado = true;
        }
    }
}

int main(void) {
    int N, M, J, K, A, B, C;
    Graph G;

    scanf("%d %d %d", &N, &M, &J);

    G = initGraph(N);
    
    for(int i = 0; i < N; i++){
        scanf("%d", &K);
        for(int j = 0; j < K; j++){
            scanf("%d", &A);
            addEdge(G, i, A);
        }
    }

    for(int i = 0; i < M; i++){
        scanf("%d", &B);
        BFS(G, B);
    }

    for(int i = 0; i < J; i++){
        scanf("%d", &C);
        if(G->adj[C]->visitado == true){
            printf("Eu vou estar la\n");
        }
        else{
            printf("Nao vou estar la\n");
        }
    }

    return 0;
}