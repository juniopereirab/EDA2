#include <stdio.h>
#include <string.h>


int main(){ 
    char string[1000];

    scanf(" %s", string);

    printf("%zu\n", strlen(string));
    
    return 0;
}