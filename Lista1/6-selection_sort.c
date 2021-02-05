#include <stdio.h>

#define MAX 1000

int vetor[MAX];

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
void selectionSort(int arr[], int n) 
{ 
    int i, j, min_idx; 
    for (i = 0; i < n-1; i++) 
    { 
        min_idx = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min_idx]) 
            min_idx = j; 
        swap(&arr[min_idx], &arr[i]); 
    } 
} 

int main() {
    
    int aux;
    int i = 0;

    while(scanf("%d", &aux) != EOF){
        vetor[i] = aux;
        i++;
    }

    selectionSort(vetor, i);


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