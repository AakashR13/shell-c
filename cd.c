#include "header.h"

int cd(char* tokens[], int count){
    if(count >   2){
        printf("Error: cd only takes one argument\n");
        return -1;
    }
    else{
        if((!strcmp(tokens[1],"~")) || (!strcmp(tokens[1],"~/"))){
            chdir(pseudo_home);
            strcpy(curr_dir, pseudo_home);
            return 0;        
        }
        else if(!strcmp(tokens[1],"-")){
            printf("%s\n", prev_dir);
            getcwd(curr_dir, BUFFER_SIZE);
            int f = chdir(prev_dir);
            strcpy(prev_dir, curr_dir);
            if (f < 0)
            {
                printf("CD: error with flag\n");
            }        
        }
        else if(!strcmp(tokens[1],"..")){
            // GO up in the file hierarchy
            int f = chdir("..");
            strcpy(prev_dir, curr_dir);
            if (f < 0)
            {
                printf("CD: error with flag\n");
            }
        }
        else{
            chdir(tokens[1]);
        }
    }
    return 0;
}

