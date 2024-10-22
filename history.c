#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <stdbool.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/utsname.h>
#define MAX_HISTORY 20
#define DISPLAY_HISTORY 10

void showHistory(char *home_dir)
{
    char history_dir[1024];
    strcpy(history_dir, home_dir);
    strcat(history_dir, "/history.txt");
    FILE *historyFile = fopen(history_dir, "r+");
    if (!historyFile)
    {
        perror("Error opening history file");
        return;
    }

    char history[MAX_HISTORY][1024] = {0};
    int count = 0;

    if (historyFile)
    {
        while (fgets(history[count], 1024, historyFile) && count < MAX_HISTORY)
        {
            if (history[count][strlen(history[count]) - 1] == '\n')
                history[count][strlen(history[count]) - 1] = '\0';
            count++;
        }
        fclose(historyFile);
    }

    int start = (count > DISPLAY_HISTORY) ? count - DISPLAY_HISTORY : 0;
    for (int i = start; i < count; i++)
    {
        printf("%d %s\n", i + 1, history[i]);
    }
}

void updateHistoryFile(char *command, char *home_dir)
{
    char history_dir[1024];
    strcpy(history_dir, home_dir);
    strcat(history_dir, "/history.txt");
    FILE *historyFile = fopen(history_dir, "r+");
    char history[MAX_HISTORY][1024] = {0};
    int count = 0;

    if (historyFile)
    {
        while (fgets(history[count], 1024, historyFile) && count < MAX_HISTORY)
        {
            if (history[count][strlen(history[count]) - 1] == '\n')
                history[count][strlen(history[count]) - 1] = '\0';
            count++;
        }
        fclose(historyFile);
    }

    if (count == 0 || strcmp(history[count - 1], command) != 0)
    {
        if (count == MAX_HISTORY)
        {
            for (int i = 1; i < MAX_HISTORY; i++)
            {
                strcpy(history[i - 1], history[i]);
            }
            count = MAX_HISTORY - 1;
        }
        strcpy(history[count], command);
        count++;
    }

    historyFile = fopen(history_dir, "w");
    if (!historyFile)
    {
        perror("Error opening history file");
        return;
    }
    for (int i = 0; i < count; i++)
    {
        fprintf(historyFile, "%s\n", history[i]);
    }
    fclose(historyFile);
}
