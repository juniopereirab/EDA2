#include <stdio.h>
#include <string.h>

char nomes[100][20];
char aux[20];
int notas[100];

void insertionSort(int arr[], char vetor[][20], int n) 
{ 
    int i, key, j;
    char aux[20]; 
    for (i = 1; i < n; i++) { 
        key = arr[i];
        stpcpy(aux, vetor[i]);
        j = i - 1; 

        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j];
            strcpy(vetor[j+1], vetor[j]);
            j = j - 1; 
        } 
        arr[j + 1] = key; 
        strcpy(vetor[j+1], aux);
    } 
}

void insertionSortString(char arr[][20], int notas[], int n) 
{ 
    int i, j, chave;
    char key[20]; 
    for (i = 1; i < n; i++) { 
        strcpy(key, arr[i]);
        chave = notas[i];
        j = i - 1; 

        while (j >= 0 && arr[j] > key) { 
            strcpy(arr[j+1], arr[j]);
            notas[j+1] = notas[j];
            j = j - 1; 
        } 
        strcpy(arr[j+1], key);
        notas[j+1] = chave;
    } 
} 

int main(){
    int N;
    int i = 0;
    int num;
    scanf("%d", &N);

    while(i < N){
        scanf("%s", aux);
        scanf("%d", &num);

        stpcpy(nomes[i], aux);
        notas[i] = num;

        i++;
    }
    
    insertionSortString(nomes, notas, N);
    for(int i = 0; i < N; i++){
        printf("%s %d\n", nomes[i], notas[i]);
    }

    return 0;
}