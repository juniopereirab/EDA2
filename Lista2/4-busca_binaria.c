#include <stdio.h>
#include <stdlib.h>

int
recursive_binary_search(int *vector, int begin, int end, int item)
{
    int i = (begin + end) / 2;

    if (vector[i] == item) {  /* Item encontrado */
        return i;
    }

    if (begin > end) {
        if(i == 0){
            return i;
        }
        else if(i == end) {
            return i;
        }
        if(vector[i] < item && vector[i+1] > item){
            return i;
        }  /* Ponto de parada. Item não está no vetor */
    }
    

    if (vector[i] < item) {  /* Item está no sub-vetor à direita */
        return recursive_binary_search(vector, i + 1, end, item);


    } else {  /* vector[i] > item. Item está no sub-vetor à esquerda */
        return recursive_binary_search(vector, begin, i - 1, item);
    }
}    

int buscar_iterativa(int item, const int *vector, int N){
    int a = 0, b = N - 1, m = 0;

    while(a <= b){
        m = a + (b-a)/2;

        if(vector[m] == item){
            return m;
        }

        else if(vector[m] > item){
            b = m - 1;
        }
        else{
            a = m + 1;
        }
    }

    if(a > b){
        if(m == N-1){
            return m+1;
        }
        else if(m == 0){
            return m;
        }
        else if(vector[m] < item && vector[m+1] > item){
            return m+1;
        }
    }
    return m;
   
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
        printf("%d\n", buscar_iterativa(aux, vetor, n));
    }

    return 0;

}