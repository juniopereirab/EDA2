#include <stdio.h>
#include <stdlib.h>

int
recursive_binary_search(int *vector, int begin, int end, int item)
{
    int i = (begin + end) / 2;

    if (vector[i] == item) {  /* Item encontrado */
        return i;
    }

    if (begin >= end) {  /* Ponto de parada. Item não está no vetor */
        return i;
    }
    

    if (vector[i] < item) {  /* Item está no sub-vetor à direita */
        return recursive_binary_search(vector, i + 1, end, item);


    } else {  /* vector[i] > item. Item está no sub-vetor à esquerda */
        return recursive_binary_search(vector, begin, i - 1, item);
    }
}    

int main(){
    int n, m, aux;

    int *vetor;

    scanf("%d %d", &n, &m);
    vetor = malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }

    for(int i = 0; i < m; i++){
        scanf("%d", &aux);
        printf("%d\n", recursive_binary_search(vetor, 0, n, aux));
    }

    return 0;

}