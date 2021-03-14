#include <stdio.h>
#include <stdlib.h>


int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

typedef int Item;
#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { int t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }
#define separa(v,l,r) separaSEDGEWICK(v,l,r)

int separaSEDGEWICK(Item *V,int l,int r)
{
  int i=l-1, j=r; Item v=V[r];
  for(;;)
  {
    while(less(V[++i],v));
    while(less(v,V[--j])) if(j==l) break;
    if(i>=j) break;
    exch(V[i],V[j]);
  }
  exch(V[i],V[r])
  return i;
}

void quicksortM3(Item *V,int l, int r)
{
  if (r<=l) return;

  cmpexch(V[(l+r)/2],V[r]);
    cmpexch(V[l],V[(l+r)/2]);
      cmpexch(V[r],V[(l+r)/2]);

  int j=separa(V,l,r);
  quicksortM3(V,l,j-1);
  quicksortM3(V,j+1,r);
}

int main() {
    int N, P, X;
    int *vetor;
    int i = 0;

    vetor = malloc(sizeof(int));

    scanf("%d %d %d", &N, &P, &X);
    while(i < N){
        scanf("%d", &vetor[i]);
        i++;
        vetor = (int*) realloc(vetor, sizeof(int) * (i+1));
    }
    // qsort(vetor, N, sizeof(int), compare);  TIME LIMIT EXCEEDED 93%
    // quicksortM3(vetor, 0, N-1);             TIME LIMIT EXCEEDED 96%
    for(int j = 0, k = P*X; j < X; j++){
        if(k == N){
            break;
        }
        else{
            printf("%d\n", vetor[k]);
            k++;
        }
    }
}