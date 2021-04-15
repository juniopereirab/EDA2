#include <stdio.h>

int main () {

    int N;
    int aux;
    scanf("%d", &N);

    for(int i = 0; i < N; i++){ 
        scanf("%d", &aux);

        if(aux % 2 == 0){
            printf("Jedi\n");
        }
        else {
            printf("Sith\n");
        }
    }

    return 0;
}