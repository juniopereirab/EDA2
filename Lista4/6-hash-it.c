#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 101

char *hashtable[M];

int hash(char *key, int len){
    int r = 0;
    for(int i = 0; i < len; ++i){
        r += (key[i] * (i+1))%M;
    }

    return (19*r)%M;
}

int main() {
    int t;
    scanf("%d", &t);

    int n;
    char string[30], command, *key;
    int pos, flag, len, count;
    while(t--){

        count = 0;
        for(int i = 0; i < n; ++i)
            hashtable[i] = NULL;

        scanf("%d", &n);
        for(int i = 0; i < n; ++i){
            scanf("%s", string);
            key = &string[4];
            command = string[0];
            len = strlen(key);

            if(command == 'A'){
                flag = 1;
                for(int j = 0; j < 20; ++j){
                    pos = (hash(key, len) + j*j + 23*j) % M;
                    if(hashtable[pos] != NULL && strcmp(key, hashtable[pos])==0){
                        flag = 0;
                        break;
                    }
                }

                if(flag){
                    for(int j = 0; j < 20; ++j){
                        pos = (hash(key,len) + j*j + 23*j)%M;

                        if(hashtable[pos]==NULL){
                            hashtable[pos] = malloc(sizeof(char)*(len+1));
                            strcpy(hashtable[pos], key);
                            count++;
                            break;
                        }
                    }
                }

            }else if(command == 'D'){
                for(int j = 0; j < 20; ++j){
                    pos = (hash(key, len) + j*j + 23*j)%M;
                    if(hashtable[pos] != NULL && strcmp(hashtable[pos], key) == 0){
                        free(hashtable[pos]);
                        hashtable[pos] = NULL;
                        count--;
                        break;
                    }
                }
            }
        }
        printf("%d\n", count);
            for(int i = 0; i < M; ++i){
                if(hashtable[i] != NULL){
                    printf("%d:%s\n", i, hashtable[i]);
                }
            }
    }
    return 0;
}