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

void quicksort(Item *V,int l, int r)
{
  if (r<=l) return;
  int j=separa(V,l,r);
  quicksort(V,l,j-1);
  quicksort(V,j+1,r);
}

int vetor[1000000];

int main() {

    int N;
    int aux;
    int i;
    int maior = 0;
    int menor = 0;
    int res;
    while(scanf("%d", &N) && N){
        for(i = 0; i < N; i++){
            scanf("%d", &aux);
            vetor[i] = aux;
        }
        quicksort(vetor, 0, i-1);
        for(int j = 1; j < i; j++){
            if(vetor[j] != vetor[j-1] || j == i-1){
                menor++;
                if(menor > maior){
                    maior = menor;
                    res = vetor[j-1];
                }
                menor = 0;
                continue;
            }
            else if (vetor[j] == vetor[j-1]){
                menor++;
            }
        }

        printf("%d\n", res);
        maior = 0;
        menor = 0;
    }

    return 0;
}