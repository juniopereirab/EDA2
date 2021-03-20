#include <stdio.h>
#include <string.h>

//WRONG ANSWER 0%... Eh sobre isso sabe

int main() {
    char string[1000];

    scanf(" %[^\n]", string);

    if(strlen(string) > 0){
        for(int i = (int)strlen(string); i >= 0; i--){
            printf("%c", string[i]);
        }
    }
    return 0;
}