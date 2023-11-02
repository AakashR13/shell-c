#include "header.h"

char home[BUFFER_SIZE];
char pseudo_home[BUFFER_SIZE];
char prev_dir[BUFFER_SIZE];
char username[BUFFER_SIZE];
char hostname[BUFFER_SIZE];
char curr_dir[BUFFER_SIZE];

int main(int argc, char **argv)
{
    getcwd(home, BUFFER_SIZE);
    getcwd(pseudo_home, BUFFER_SIZE);
    getcwd(prev_dir, BUFFER_SIZE);
    char* tokens[BUFFER_SIZE];
    init_history();
    while (true)
    {
        if(display()==0);
        int count = handleInput(tokens);
        if (count == 0 || count == -1)
            continue;
        // printf("%d\n", count);
        
        execute(tokens, count);
    }
    return 0;
}
