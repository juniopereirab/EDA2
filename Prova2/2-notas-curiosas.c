#include <stdio.h>
#include <stdlib.h>

int vetor[1001];

int main () {
    
    int N, aux, pos, maior = 0;
    int nota;

    while(scanf("%d", &N)!=EOF){
        for(int i = 0; i < N; i++){
            scanf("%d", &aux);
            vetor[aux]++;
        }

        for(int j = 0; j <= 1000; j++){
            if(maior < vetor[j] || maior == vetor[j]){
                maior = vetor[j], nota = j;
            }
        }
    }

    printf("%d\n", nota);
    return 0;
}