#include <stdio.h>
#include <stdlib.h>

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

void quickselect(int *v, int l, int r, int k){
    int i;
    if(r <= l){
        return;
    }

    i = separa(v, l, r);
    if(i > k) quickselect(v, l, i-1, k);
    if(i < k) quickselect(v, i+1, r, k);
}


int main() {
    int N, P, X;
    int *vetor;
    int i = 0;
    int c, f;

    vetor = malloc(sizeof(int));

    scanf("%d %d %d", &N, &P, &X);
    while(i < N){
        scanf("%d", &vetor[i]);
        i++;
        vetor = (int*) realloc(vetor, sizeof(int) * (i+1));
    } 
    
    c = P*X;
    f = c+X-1;

    quickselect(vetor, 0, N-1, c);
    quickselect(vetor, c+1, N-1, f);
    quicksortM3(vetor, c, f);

    for(int j = c; j <= f; j++){
        printf("%d\n", vetor[j]);
    }

    return 0;
}