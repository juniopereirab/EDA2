#include <stdio.h>
#include <stdlib.h>

void merge(int *v, int *c, int i, int m, int f) {
  int z,
      iv = i, ic = m + 1;

  for (z = i; z <= f; z++) c[z] = v[z];

  z = i;

  while (iv <= m && ic <= f) {
    

    if (c[iv] < c[ic]) v[z++] = c[iv++];
    else v[z++] = c[ic++];
  }

  while (iv <= m) v[z++] = c[iv++];

  while (ic <= f) v[z++] = c[ic++];
}

void sort(int *v, int *c, int i, int f) {
  if (i >= f) return;

  int m = (i + f) / 2;

  sort(v, c, i, m);
  sort(v, c, m + 1, f);

  if (v[m] <= v[m + 1]) return;

  merge(v, c, i, m, f);
}


void mergesort(int *v, int n) {
  int *c = malloc(sizeof(int) * n);
  sort(v, c, 0, n - 1);
  free(c);
}


int main() {
    int n;
    int *v;
    scanf("%d", &n);

    v = malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }

    mergesort(v, n);

    for(int i = 0; i < n; i++){
        if(i == n-1){
            printf("%d\n", v[i]);
        }
        else{
            printf("%d ", v[i]);
        }
    }
}