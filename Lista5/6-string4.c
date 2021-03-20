#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main () {
    int N;
    char string[100];
    char maior[100];
    int maior_tam=0;
    int tam = 0;

    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        scanf(" %s", string);
        tam = strlen(string);
        if(tam > maior_tam){
            maior_tam = tam;
            strcpy(maior, string);
        }
    }

    printf("%s\n", maior);

    return 0;
}