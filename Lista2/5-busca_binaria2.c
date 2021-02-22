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

int retorna_posicao(int *vector, int n, int item){
    for(int i = 0; i < n; i++){
        if(vector[i] == item){
            return i;
        }
    }

    return -1;
}

int main(){
    int n, m, aux, achou;

    int *vetor;
    int *original;

    scanf("%d %d", &n, &m);

    vetor = malloc(sizeof(int) * n);
    original = malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++){
        scanf("%d", &aux);
        vetor[i] = aux;
        original[i] = aux;
    }

    qsort(vetor, n, sizeof(int), compare);

    for(int i = 0; i < m; i++){
        scanf("%d", &aux);
        achou = recursive_binary_search(vetor, 0, n, aux);
        if(achou != -1){
            printf("%d\n", retorna_posicao(original, n, aux));
        }
        else {
            printf("-1\n");
        }
    }
    return 0;

}