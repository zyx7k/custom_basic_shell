#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "cd.h"
#include "pwd.h"
#include "history.h"
#include "echo.h"
#include "display.h"

int main()
{
    char *home_dir = malloc(sizeof(char) * 1024);
    if (getcwd(home_dir, 1024) == NULL)
    {
        perror("Error getting home directory");
        free(home_dir);
        return 1;
    }

    char prev_dir[1024] = "";

    while (1)
    {
        char userInput[1024];
        display(home_dir);
        fgets(userInput, sizeof(userInput), stdin);

        if (userInput[strlen(userInput) - 1] == '\n')
        {
            userInput[strlen(userInput) - 1] = '\0';
        }

        char curr_dir[1024];
        if (getcwd(curr_dir, 1024) == NULL)
        {
            perror("Error getting current working directory");
        }

        updateHistoryFile(userInput, home_dir);

        if (strncmp(userInput, "echo", 4) == 0)
        {
            parseInput(userInput);
        }
        else if (strncmp(userInput, "pwd", 3) == 0)
        {
            printWorkingDirectory();
        }
        else if (strncmp(userInput, "cd", 2) == 0)
        {
            changeDirectory(userInput, home_dir, prev_dir, curr_dir);
        }
        else if (strncmp(userInput, "history", 7) == 0)
        {
            showHistory(home_dir);
        }
    }

    free(home_dir);
    return 0;
}