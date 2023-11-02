#include "header.h"

int pwd(char* tokens[], int count){
    if(count > 1){
        printf("Error: pwd does not take any arguments\n");
        return 1;
    }
    char curr_dir[BUFFER_SIZE];
    if(getcwd(curr_dir,BUFFER_SIZE) == NULL){
        printf("Error: current directory not found\n");
        return 2;
    }
    printf("%s\n",curr_dir);
    return 0;
}