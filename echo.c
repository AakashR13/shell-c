#include "header.h"

int echo(char* tokens[], int count){
    // printf("echo: ");
    for(int i=1;i<count;i++){
        printf("%s ",tokens[i]);
    }
    printf("\n");
    return 0;
}
