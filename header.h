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


// Main
int main(int argc, char **argv);

// Function prototypes
int gethostname(char *name, size_t namelen);
char *getpwd(char *buffer, size_t size);
char *strtok(char *str, const char *delims);
int strcmp (const char* str1, const char* str2);
int display();
int handleInput(char* tokens[]);
int execute(char* tokens[], int count);
int echo(char* tokens[], int count);
int pwd(char* tokens[], int count);
int cd(char* tokens[], int count);
int history();

// Structs
struct his
{
    char name[MAX_HISTORY][BUFFER_SIZE];
    int num;
};
