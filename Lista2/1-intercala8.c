#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000

int A[MAX];
int B[MAX];
int C[MAX];
int D[MAX];
int E[MAX];
int F[MAX];
int G[MAX];
int H[MAX];

int W[MAX];
int X[MAX];
int Y[MAX];
int Z[MAX];

int J[MAX];
int K[MAX];
int L[MAX];

void intercala2W(int A[], int M, int B[], int N){
  int i = 0, j = 0, k = 0;
  while(i < M && j < N){
    if(A[i] < B[j]){
      W[k] = A[i];
      i++;
      k++;
    }
    else{
      W[k] = B[j];
      j++;
      k++;
    }
  }

  if(i < M){W[k] = A[i]; i++; k++;}
  if(j < N){W[k] = B[j]; j++; k++;}

}

void intercala2X(int A[], int M, int B[], int N){
  int i = 0, j = 0, k = 0;
  while(i < M && j < N){
    if(A[i] < B[j]){
      X[k] = A[i];
      i++;
      k++;
    }
    else{
      X[k] = B[j];
      j++;
      k++;
    }
  }

  if(i < M){X[k] = A[i]; i++; k++;}
  if(j < N){X[k] = B[j]; j++; k++;}

}

void intercala2Y(int A[], int M, int B[], int N){
  int i = 0, j = 0, k = 0;
  while(i < M && j < N){
    if(A[i] < B[j]){
      Y[k] = A[i];
      i++;
      k++;
    }
    else{
      Y[k] = B[j];
      j++;
      k++;
    }
  }

  if(i < M){Y[k] = A[i]; i++; k++;}
  if(j < N){Y[k] = B[j]; j++; k++;}

}

void intercala2Z(int A[], int M, int B[], int N){
  int i = 0, j = 0, k = 0;
  while(i < M && j < N){
    if(A[i] < B[j]){
      Z[k] = A[i];
      i++;
      k++;
    }
    else{
      Z[k] = B[j];
      j++;
      k++;
    }
  }

  if(i < M){Z[k] = A[i]; i++; k++;}
  if(j < N){Z[k] = B[j]; j++; k++;}

}

void intercala2J(int A[], int M, int B[], int N){
  int i = 0, j = 0, k = 0;
  while(i < M && j < N){
    if(A[i] < B[j]){
      J[k] = A[i];
      i++;
      k++;
    }
    else{
      J[k] = B[j];
      j++;
      k++;
    }
  }

  if(i < M){J[k] = A[i]; i++; k++;}
  if(j < N){J[k] = B[j]; j++; k++;}

}

void intercala2K(int A[], int M, int B[], int N){
  int i = 0, j = 0, k = 0;
  while(i < M && j < N){
    if(A[i] < B[j]){
      K[k] = A[i];
      i++;
      k++;
    }
    else{
      K[k] = B[j];
      j++;
      k++;
    }
  }

  if(i < M){K[k] = A[i]; i++; k++;}
  if(j < N){K[k] = B[j]; j++; k++;}

}

void intercala2L(int A[], int M, int B[], int N){
  int i = 0, j = 0, k = 0;
  while(i < M && j < N){
    if(A[i] < B[j]){
      L[k] = A[i];
      i++;
      k++;
    }
    else{
      L[k] = B[j];
      j++;
      k++;
    }
  }

  if(i < M){L[k] = A[i]; i++; k++;}
  if(j < N){L[k] = B[j]; j++; k++;}

}

int main(void) {
  int tam;

  scanf("%d", &tam);
  int i = 0;
  int M = tam;
  while(tam--){
    scanf("%d", &A[i]);
    i++;
  }
  
  scanf("%d", &tam);
  i = 0;
  int N = tam;
  while(tam--){
    scanf("%d", &B[i]);
    i++;
  }

  scanf("%d", &tam);
  i = 0;
  int O = tam;
  while(tam--){
    scanf("%d", &C[i]);
    i++;
  }

  scanf("%d", &tam);  
  i = 0;
  int P = tam;
  while(tam--){
    scanf("%d", &D[i]);
    i++;
  }
 
  scanf("%d", &tam);
  i = 0;
  int Q = tam;
  while(tam--){
    scanf("%d", &E[i]);
    i++;
  }
  
  scanf("%d", &tam);
  i = 0;
  int R = tam;
  while(tam--){
    scanf("%d", &F[i]);
    i++;
  }
 
  scanf("%d", &tam);
  i = 0;
  int S = tam;
  while(tam--){
    scanf("%d", &G[i]);
    i++;
  }
  
  scanf("%d", &tam);
  i = 0;
  int T = tam;
  while(tam--){
    scanf("%d", &H[i]);
    i++;
  }
   
  intercala2W(A, M, B, N);
  intercala2X(C, O, D, P);
  intercala2Y(E, Q, F, R);
  intercala2Z(G, S, H, T);
  intercala2J(W, M+N, X, O+P);
  intercala2K(Y, Q+R, Z, S+T);
  intercala2L(J, M+N+O+P, K, Q+R+S+T);

  for(int i = 0; i < M+N; i++){
    if(i == (M+N)-1){
      printf("%d\n", W[i]);
    }
    else{
      printf("%d ", W[i]);
    }
  }

  for(int i = 0; i < O+P; i++){
    if(i == (O+P)-1){
      printf("%d\n", X[i]);
    }
    else{
      printf("%d ", X[i]);
    }
  }

  for(int i = 0; i < Q+R; i++){
    if(i == (Q+R)-1){
      printf("%d\n", Y[i]);
    }
    else{
      printf("%d ", Y[i]);
    }
  }

  for(int i = 0; i < S+T; i++){
    if(i == (S+T)-1){
      printf("%d\n", Z[i]);
    }
    else{
      printf("%d ", Z[i]);
    }
  }

  for(int i = 0; i < M+N+O+P; i++){
    if(i == (M+N+O+P)-1){
      printf("%d\n", J[i]);
    }
    else{
      printf("%d ", J[i]);
    }
  }

  for(int i = 0; i < Q+R+S+T; i++){
    if(i == (Q+R+S+T)-1){
      printf("%d\n", K[i]);
    }
    else{
      printf("%d ", K[i]);
    }
  }

  for(int i = 0; i < M+N+O+P+Q+R+S+T; i++){
    if(i == (M+N+O+P+Q+R+S+T)-1){
      printf("%d\n", L[i]);
    }
    else{
      printf("%d ", L[i]);
    }
  }
  return 0;
}

