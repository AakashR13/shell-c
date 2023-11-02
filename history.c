#include "header.h"

#define MAX_HISTORY_ENTRIES 20
#define MAX_COMMAND_LENGTH 256
#define MAX_PRINT_ENTRIES 10

char hisfile_path[BUFFER_SIZE];

void init_history() {
    snprintf(hisfile_path, sizeof(hisfile_path), "%s/history.txt", pseudo_home);

    FILE *fp = fopen(hisfile_path, "r");
    if (!fp) {
        fp = fopen(hisfile_path, "w");
        if (!fp) {
            printf("Error: Unable to create history file\n");
            return;
        }
        his.num = 0;
        fclose(fp);
        return;
    }

    char line[MAX_COMMAND_LENGTH];
    while (fgets(line, sizeof(line), fp) != NULL) {
        int len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }
        if (his.num < MAX_HISTORY_ENTRIES) {
            strcpy(his.name[his.num], line);
            his.num++;
        }
    }
    fclose(fp);
}

void add_history(char *tokens[], int count) {
    if (count == 0 || tokens[0] == NULL) {
        return;
    }

    char new_command[MAX_COMMAND_LENGTH];
    snprintf(new_command, sizeof(new_command), "%s", tokens[0]);

    printf("Token History: %s\n", tokens[0]);
    for (int i = 1; i < count; i++) {
        // printf("Token History: %s\n", tokens[i]);
        strncat(new_command, " ", sizeof(new_command) - strlen(new_command) - 1);
        strncat(new_command, tokens[i], sizeof(new_command) - strlen(new_command) - 1);
    }

    if (his.num == 0 || strcmp(new_command, his.name[his.num - 1]) != 0) {
        if (his.num < MAX_HISTORY_ENTRIES) {
            strcpy(his.name[his.num], new_command);
            // printf("history: %s\n", his.name[his.num]);
            his.num++;
        } else {
            // Shift history entries to make room for the new one
            for (int i = 0; i < MAX_HISTORY_ENTRIES - 1; i++) {
                strcpy(his.name[i], his.name[i + 1]);
            }
            strcpy(his.name[MAX_HISTORY_ENTRIES - 1], new_command);
        }
    }
}

void write_history() {
    FILE *fp = fopen(hisfile_path, "w");
    if (!fp) {
        printf("Error: Unable to write to history file\n");
        return;
    }

    int start = (his.num <= MAX_HISTORY_ENTRIES) ? 0 : (his.num % MAX_HISTORY_ENTRIES);

    for (int i = 0; i < his.num; i++) {
        fprintf(fp, "%s\n", his.name[(start + i) % MAX_HISTORY_ENTRIES]);
    }

    fclose(fp);
}


void history(char* token[], int count) {
    if (count > 2) {
        printf("error: too many arguments\n");
        return;
    }

    int size = (his.num < MAX_HISTORY_ENTRIES) ? his.num : MAX_HISTORY_ENTRIES;
    size = (size > MAX_PRINT_ENTRIES) ? MAX_PRINT_ENTRIES : size; // Limit the size to 10

    if (token[1] == NULL) {
        if (size == 0) {
            printf("no history found\n");
            return;
        }

        int i = his.num - 1;
        int x = 0;
        do {
            printf("[%d]: %s\n", x + 1, his.name[i]);
            x++;
            i = (i - 1 + size) % size;
        } while (x < size);
    } else {
        int tot = atoi(token[1]);

        if (tot < 0) {
            printf("negative integer not allowed\n");
            return;
        }

        if (tot > his.num) {
            fprintf(stderr, "history only has %d entries\n\n", his.num);
            tot = his.num;
        }

        tot = (tot > MAX_PRINT_ENTRIES) ? MAX_PRINT_ENTRIES : tot; // Limit the total to 10

        int i = his.num - 1;
        int x = 0;
        do {
            printf("[%d]: %s\n", x + 1, his.name[i]);
            x++;
            i = (i - 1 + size) % size;
        } while (x < tot);
    }
}
