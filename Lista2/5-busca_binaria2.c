#include <stdio.h>
#include <stdlib.h>

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int
recursive_binary_search(int *vector, int begin, int end, int item)
{
    int i = (begin + end) / 2;

    if (begin > end) {  /* Ponto de parada. Item não está no vetor */
        return -1;
    }

    if (vector[i] == item) {  /* Item encontrado */
        return i;
    }

    if (vector[i] < item) {  /* Item está no sub-vetor à direita */
        return recursive_binary_search(vector, i + 1, end, item);


    } else {  /* vector[i] > item. Item está no sub-vetor à esquerda */
        return recursive_binary_search(vector, begin, i - 1, item);
    }
}    

int main(){
    int n, m, auxi, indice;

    int *vetor;

    scanf("%d %d", &n, &m);

    vetor = malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }

    qsort(vetor, n, sizeof(int), compare);

    for(int i = 0; i < n; i++){
        printf("%d\n", vetor[i]);
    }
    for(int i = 0; i < m; i++){
        scanf("%d", &auxi);
        printf("%d\n", recursive_binary_search(vetor, 0, n, auxi));
    }

    //Ta errado pelo fato de que, tem que retornar baseado no valor do indice dentro do vetor original e nao do vetor ordenado.

    return 0;

}