#include <stdio.h>
#include <stdlib.h>

typedef struct speed {
    int download;
    int upload;
} Speed;

static Speed *v;
static int N;

#define exch(A,B) { Speed t; t=A;A=B;B=t; }

int compare(Speed a, Speed b){
  if(a.download < b.download) return 0;
  else if(a.download == b.download){
    if(a.upload < b.upload){
      return 0;
    }
    else{
      return 1;
    }
  }
  return 1;
}


int less(Speed a, Speed b){
  return compare(a, b);
}

void fixUp (int K){
  while(K > 1 && less(v[K/2], v[K])){
    exch(v[K], v[K/2]);
    K = K/2;
  }
}

void fixDown (int K, int N){
  int j;
  while(2*K <= N){
    j = 2*K;
    if( j < N && less(v[j], v[j+1])) j++;
    if(!less(v[K], v[j])) break;
    
    exch(v[K], v[j]);
    K = j;
  }
}

void PQInit(int maxN){
  v = malloc(sizeof(Speed) * (maxN+1));
  N = 0;
}

int PQEmpty(){
  return N == 0;
}

void PQInsert(Speed novo){
  v[++N] = novo;
  fixUp(N);
}

Speed PQdelMax(){
  exch(v[1], v[N]);
  fixDown(1, N-1);
  return v[N--];
}


int main() {
    int D, U, L, T;
    int limD = 0;
    int limU = 0;
    int auxD, auxU;
    Speed aux;
    int count = 0;

    scanf("%d %d %d %d", &D, &U, &L, &T);

    PQInit(T);

    limD =  D - (D * L / 100);
    limU =  U - (U * L / 100);

    limD--;
    limU--;

    for(int i = 0; i < T; i++){
        scanf("%d/%d", &auxD, &auxU);
        if(auxD < limD || auxU < limU){
            aux.download = auxD;
            aux.upload = auxU;
            PQInsert(aux);
            count++;
        }
    }

    while(!PQEmpty()){
      aux = PQdelMax();
      printf("%d/%d\n", aux.download, aux.upload);
    }

    free(v);
    return 0;
}