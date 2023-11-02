#include "header.h"

int execute(char* tokens[], int count){
    printf("cmd1: %s \n",tokens[0]);
    printf("cmd1: \"%s\"\n",tokens[0]);
    // printf("comp: %s %d\n",tokens[0] , strcmp(tokens[0],"echo"));
    printf("%d", strcmp(tokens[0],"echo"));
    if(strcmp(tokens[0],"echo")==0)
    {
        printf("cmd2: \"%s\n\"",tokens[0]);
        echo(tokens,count);
    }

    else if(strcmp(tokens[0],"pwd")==0)
    {
        pwd(tokens,count);
    }

    else if(strcmp(tokens[0],"cd") ==0)
    {
        // printf("cd\n");
        cd(tokens,count);
    }
    
    else if(strcmp(tokens[0],"history")==0)
    {
        // history();
    }

    else if(strcmp(tokens[0],"exit")==0)
    {
        exit(0);
    }

    for(int i=0;i<count;i++)
        tokens[i] = NULL;
    printf("exits?");
    
    return -1;
}