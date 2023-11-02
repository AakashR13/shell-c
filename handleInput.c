#include "header.h"

int handleInput(char* tokens[]){
    char input[BUFFER_SIZE];
    fgets(input,BUFFER_SIZE,stdin);
    if (input[0] == '\0')
        return -1; 
    char* token = strtok(input," \t\n");
    int count = 0;
    while(token != NULL){
        // printf("\"%s\"\n",token);
        tokens[count] = token;
        token = strtok(NULL," \t\n");
        count++;
    }
    tokens[count] = NULL;
    return count;

}
