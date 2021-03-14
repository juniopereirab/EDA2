#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <setjmp.h>

typedef int Item;
#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { int t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

int trapstop=0;
int trapsize=0;
jmp_buf env;


int separa(Item *V,int l,int r)
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

void insertionsort(Item *v,int l,int r)
{
  for(int i=r;i>l;i--)
    cmpexch(v[i-i],v[i]);

  for(int i=l+2;i<=r;i++)
  {
    int j=i; Item tmp=v[j];
    while(less(tmp,v[j-1]))
    {
      v[j]=v[j-1];
      j--;
    }
    v[j]=tmp;
  }
}

void merge(Item *V, int l, int m, int r)
{
  Item *R=malloc(sizeof(Item)*(r-l+1));
  int i=l,j=m+1,k=0;

  while(i<=m && j<=r)
  {
    if(lesseq(V[i],V[j]))
      R[k++]=V[i++];
    else
      R[k++]=V[j++];
  }

  while(i<=m)
      R[k++]=V[i++];
  while(j<=r)
      R[k++]=V[j++];


  k=0;
  for(i=l;i<=r;i++)
    V[i]=R[k++];
  free(R);
}

void mergesort(Item *V,int l, int r)
{
  if (l>= r) return;
  int meio=(l+r)/2;
  mergesort(V,l,meio);
  mergesort(V,meio+1,r);
  merge(V,l,meio,r);
}

static void quicksortM3(Item *V,int l, int r,int rec)
{
  if (r-l<=32) return;

  if(rec==0)
  {
    trapstop=1;
    longjmp(env,1);
    return;
  }

  exch(V[(l+r)/2],V[r-1]);
  cmpexch(V[l],V[r-1]);
  cmpexch(V[l],V[r]);
  cmpexch(V[r-1],V[r]);


  int j=separa(V,l+1,r-1);
  quicksortM3(V,l,j-1,rec-1);
  quicksortM3(V,j+1,r,rec-1);
}

void introsortquickmergelongjmp(Item *V,int l,int r)
{
  trapsize=2*((int)log2((double)(r-l+1)));
  setjmp(env);
  if(trapstop==0)
    quicksortM3(V,l,r,trapsize);

  if(trapstop==1)
  {
    mergesort(V,l,r);
  }
  else
    insertionsort(V,l,r);
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
    // introsortquickmerge(vetor, 0, N-1);     TIME LIMIT EXCEEDED 96%
    // introsortquickmergelongjmp(vetor, 0, N-1); TIME LIMIT EXCEEDED 96%
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