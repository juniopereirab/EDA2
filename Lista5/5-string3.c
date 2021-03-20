#include <stdio.h>
#include <string.h>

int main() {
    int N;
    int maior = 0;
    char string[100];

    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        scanf(" %s", string);
        if((int)strlen(string) > maior){
            maior = (int)strlen(string);
        }
    }

    printf("%d\n", maior);
    return 0;
}