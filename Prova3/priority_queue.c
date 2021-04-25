#include <stdio.h>
#include <stdlib.h>

typedef int Item;
#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { int t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }
#define separa(v,l,r) separaSEDGEWICK(v,l,r)

#define LER 1
#define IMPRIME 2

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

int main() {

    int m[101];
    int opt, x;
    int idx = 0;

    while(scanf("%d %d", &opt, &x) != EOF){
        if(opt == LER) {
            if(idx >= 100){
                if(m[idx-1] > x){
                    m[idx-1] = x;
                    quicksort(m, 0, idx-1);
                }
            }
            else{
                m[idx] = x;
                quicksort(m, 0, idx);
                idx++;
            }
        }
        if(opt == IMPRIME){
            for(int i = 0; i < x; i++){
                if(i == x-1){
                    printf("%d\n", m[i]);
                }
                else {
                    printf("%d ", m[i]);
                }
            }
        }
    }

    return 0;
}