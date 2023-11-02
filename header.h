// Libraries
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

// Macros
#define BUFFER_SIZE 1024
#define MAX_TOKENS 100
#define MAX_HISTORY 20

// Global variables
extern char home[BUFFER_SIZE];
extern char pseudo_home[BUFFER_SIZE];
extern char prev_dir[BUFFER_SIZE];
extern char username[BUFFER_SIZE];
extern char hostname[BUFFER_SIZE];
extern char curr_dir[BUFFER_SIZE];
extern char hisfile_path[BUFFER_SIZE];

// Main
int main(int argc, char **argv);

// Function prototypes
int display();
int handleInput(char* tokens[]);
int execute(char* tokens[], int count);
int echo(char* tokens[], int count);
int pwd(char* tokens[], int count);
int cd(char* tokens[], int count);
void init_history();
void add_history(char *tokens[], int count);
void write_history();
void history(char* token[], int count);


// Structs
struct historyCont
{
    char name[MAX_HISTORY][BUFFER_SIZE];
    int num;
};

static struct historyCont his;