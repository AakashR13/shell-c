#include "header.h"

    
int display(){
    // username
    if(getlogin() == NULL){
        printf("Error: Username not found\n");
        return 1;
    }
    // system_name
    else if(gethostname(hostname, BUFFER_SIZE) != 0){
        printf("Error: Hostname not found\n");
        return 2;
    }
    // current directory (Relative path?)
    else if(getcwd(curr_dir,BUFFER_SIZE) == NULL){
        printf("Error: current directory not found\n");
        return 3;
    }
    else if (strstr(curr_dir, home))
            printf("<%s@%s:~%s>",getlogin(),hostname, curr_dir + strlen(home));

    else
            printf("<%s@%s:%s>", getlogin(),hostname, curr_dir);
    // printf("<%s@%s:%s>",getlogin(),hostname,curr_dir);
    return 0;
}