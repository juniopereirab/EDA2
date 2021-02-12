#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int vetor[MAX];

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int verificarFrequencia(int arr[], int n){
    int cont = 1;
    int m = arr[0];
    for(int i = 0; i < n; i++){
        if(arr[i] == m || arr[i] == 0){
            continue;
        }
        else{
            m = arr[i];
            cont++;
        }
    }

    return cont;
}

int main(){
    int N;
    scanf("%d", &N);
    int i = 0;

    while(i < N){
        scanf("%d", &vetor[i]);
        i++;
    }
    
    qsort(vetor, N, sizeof(int), compare);

    int resultado = verificarFrequencia(vetor, N);

    printf("%d\n", resultado);


    return 0;
}