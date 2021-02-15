#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char aux[21];

typedef struct {
    char nome[21];
    int nota;
} Aluno;

Aluno alunos[100];

int compararNota (const void *x, const void *y){
    return (((Aluno *)x)->nota - ((Aluno *)y)->nota);
}

int compararNome (const void *x, const void *y){
    return strcmp(((Aluno *)x)->nome, ((Aluno *)y)->nome);
}

int verificarReprovado(Aluno vetor[], int N){
    int contador = 1;
    int index = 0;
    Aluno pos = vetor[0];
    for(int i = 1; i < N; i++){
        if(pos.nota == vetor[i].nota){
            contador++;
        }
        else{
            break;
        }
    }

    if(contador > 1){
        qsort(vetor, contador, sizeof(Aluno), compararNome);
        return contador-1;
    }
    else{
        return index;
    }
}

int main(){
    int N;
    int i = 0;
    int num;
    int instancia = 1;

    while(scanf("%d", &N) != EOF){
        while(i < N){
            scanf("%s", aux);
            scanf("%d", &num);

            stpcpy(alunos[i].nome, aux);
            alunos[i].nota = num;

            i++;
        }

        qsort(alunos, N, sizeof(Aluno), compararNota);
        
        int result = verificarReprovado(alunos, N);
        printf("Instancia %d\n", instancia);
        printf("%s\n", alunos[result].nome);
        instancia++;
        i = 0;
        printf("\n");
    }

    return 0;
}