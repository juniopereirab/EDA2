#include <stdio.h>
#include <stdlib.h>

#define MAX 140000

int vetor[MAX];

int compare(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}

int recursive_binary_search(int vector[MAX], int begin, int end, int item){
    int i = (begin + end) / 2;

    if (begin > end) {
        return 0;
    }

    if (vector[i] == item) {
        return 1;
    }

    if (vector[i] < item) {
        return recursive_binary_search(vector, i + 1, end, item);


    } else {
        return recursive_binary_search(vector, begin, i - 1, item);
    }
}    

int main(){
    int N;
    int aux;
    int achou = 0;
    int i = 0;
    scanf("%d", &N);

    while(i < N){
        scanf("%d", &vetor[i]);
        i++;
    }

    qsort(vetor, N, sizeof(int), compare);

    

    while(scanf("%d", &aux) != EOF){
        achou = recursive_binary_search(vetor, 0, N, aux);
        if(!achou){
            printf("nao\n");
        }
        else {
            printf("sim\n");
        }
    }

    return 0;
}