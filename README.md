# shell-c!

### Steps to Run The Shell :

- Clone the repository into the system.
- cd into the corresponding directory.
- run `make shell` to compile
- run `make clean` to remove all .o files.
- run `make cleanHistory` to remove the history.txt file.
- use `./shell` to run the shell.
- To exit the shell use quit/exit

Note : 
- Run the shell in the directory that it has been cloned into. 
- The home directory for commands are considered to be the directory where we run the shell.

### Files and functions :

Supporting Files :

- main.c - Calls the prompt() from prompt.c and calls tokenize() which takes input string as argument and does the tokenizing and executing the command.
- execute.c - Calls the respective functions for the commands that have been entered.
- handleInput.c - Handles the input string and tokenizes it.
- display.c - Displays the prompt and the username and hostname.

Command Files :

- pwd.c - calls the `pwd` function.
- echo.c - calls the `echo` function with the required string.
- cd.c - calls the `cd` function which helps in navigating between different directories.
- history.c - Adds commands to a file history.txt and keeps record of the last 20 commands. It loads and writes the history.txt at appropriate times.

### Commands implemented :

- `cd` : cd command changes the directory. The cd command has been implemented with the flags -  { cd . , cd .. , cd - , cd ~ , cd `<directory>` }.
- `pwd` : pwd helps in printing the absolute path of the current working directory.
- `echo` - echo helps in printing a string on the terminal, it neglects tabs and spaces. echo with no arguments prints a blank new line.

      Usage :  echo string
- `history` :  The history command returns the last 10 commands entered and preserves it over multiple terminal sessions. By default it stores the last 20 commands in history.txt

- `quit` : helps us to exit from the current shell session. `exit` also works to quit the session.

### Coding Style :

This code is completely modular and is distributed over multiple .c and corresponding .h files for each of the functionality. The header.h consists of all the libraries to be used, some declarations of the values to be used and the global variables. To add any function to the shell, we just need to add the corresponding .c file and add the declaration to the header.h file. Compilation of all the .c files is done in the Makefile. Hence modularity is maintained.

### Assumptions made :

- Input command string doesn't exceeds 8192 characters.
- Files and directory names do not contain special characters or spaces/tabs.
- Only commands that are valid are stored in history.txt.