#include <stdio.h>

#define MAX 50000

int vetor[MAX];

void insertionSort(int arr[], int n) 
{ 
    int i, key, j; 
    for (i = 1; i < n; i++) { 
        key = arr[i]; 
        j = i - 1; 

        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
} 

int main() {
    
    int aux;
    int i = 0;

    while(scanf("%d", &aux) != EOF){
        vetor[i] = aux;
        i++;
    }

    insertionSort(vetor, i);


    for(int j = 0; j < i; j++){
        if(j != i-1){
            printf("%d ", vetor[j]);
        }
        else{
            printf("%d\n", vetor[j]);
        }
    }

    return 0;
}