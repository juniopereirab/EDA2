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

int main() {

    int N;
    int i;
    int vetor[1000000];
    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        scanf("%d", &vetor[i]);
    }

    quicksortM3(vetor, 0, N-1);

    for(int j = 0; j < N; j++){
        if(j == N-1){
            printf("%d\n", vetor[j]);
        }
        else{
            printf("%d ", vetor[j]);
        }
    }
}