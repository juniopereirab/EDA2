#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000

int *intercala(int *a, int *b, int n, int m);
int *intercala4(int *a, int *b, int *c, int *d, int m, int n, int o, int p);
int *intercala8(int *a, int *b, int *c, int *d, int *e, int *f, int *g, int *h, int m, int n, int o, int p, int q, int r, int s, int t);

int main() {
  int *A, *B, *C, *D, *E, *F, *G, *H;
  
  int tam = 0;
  scanf("%d", &tam);
  A = malloc(sizeof(int) * tam);
  int i = 0;
  int M = tam;
  while(tam--){
    scanf("%d", &A[i]);
    i++;
  }
  
  tam = 0;
  scanf("%d", &tam);
  B = malloc(sizeof(int) * tam);
  i = 0;
  int N = tam;
  while(tam--){
    scanf("%d", &B[i]);
    i++;
  }

  tam = 0;
  scanf("%d", &tam);
  C = malloc(sizeof(int) * tam);
  i = 0;
  int O = tam;
  while(tam--){
    scanf("%d", &C[i]);
    i++;
  }

  tam = 0;
  scanf("%d", &tam);
  D = malloc(sizeof(int) * tam); 
  i = 0;
  int P = tam;
  while(tam--){
    scanf("%d", &D[i]);
    i++;
  }
 
  tam = 0;
  scanf("%d", &tam);
  E = malloc(sizeof(int) * tam);
  i = 0;
  int Q = tam;
  while(tam--){
    scanf("%d", &E[i]);
    i++;
  }
  
  tam = 0;
  scanf("%d", &tam);
  F = malloc(sizeof(int) * tam);
  i = 0;
  int R = tam;
  while(tam--){
    scanf("%d", &F[i]);
    i++;
  }
 
  tam = 0;
  scanf("%d", &tam);
  G = malloc(sizeof(int) * tam);
  i = 0;
  int S = tam;
  while(tam--){
    scanf("%d", &G[i]);
    i++;
  }
  
  tam = 0;
  scanf("%d", &tam);
  H = malloc(sizeof(int) * tam);
  i = 0;
  int T = tam;
  while(tam--){
    scanf("%d", &H[i]);
    i++;
  }

  int *X = intercala8(A, B, C, D, E, F, G, H, M, N, O, P, Q, R, S, T);

  for(int i = 0; i < M+N+O+P+Q+R+S+T; i++){
    if(i == (M+N+O+P+Q+R+S+T)-1){
      printf("%d\n", X[i]);
    }
    else{
      printf("%d ", X[i]);
    }
  }
  return 0;
}

int *intercala8(int *a, int *b, int *c, int *d, int *e, int *f, int *g, int *h, int m, int n, int o, int p, int q, int r, int s, int t){
  int *x, *y, *z;
  x = intercala4(a, b, c, d, m, n, o, p);
  y = intercala4(e, f, g, h, q, r, s, t);
  z = intercala(x, y, (m+n+o+p), (q+r+s+t));
  return z;
}

int *intercala4(int *a, int *b, int *c, int *d, int m, int n, int o, int p){
  int *x, *y, *z;
  x = intercala(a, b, m, n);
  y = intercala(c, d, o, p);
  z = intercala(x, y, (m+n), (o+p));

  return z;
}

int *intercala(int *a, int *b, int n, int m){
    int i = 0, j = 0;
    int *c = (int*)malloc((n + m)*sizeof(int));
    int k = 0;
    while((i + j) < (n + m)){
        if(i >= n){
            for (; j < m; j++, k++){
                c[k] = b[j];
            }
            break;
        }
        else if(j >= m){
            for (; i < n; i++, k++){
                c[k] = a[i];
            }
            break;
        }
        if (a[i] < b[j])
            c[k] = a[i++];

        else 
            c[k] = b[j++];

        k++;
    } 
    return c;
}