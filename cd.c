#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <stdbool.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/utsname.h>

void changeDirectory(char *input, char *home_dir, char *prev_dir, char *curr_dir)
{
    input += 2; // Skip the "cd" part
    while (*input == ' ' || *input == '\t')
        input++; // Skip any leading spaces

    char *arg = strtok(input, " \t");

    // Remove the newline at the end of the argument if it exists
    if (arg != NULL && arg[strlen(arg) - 1] == '\n')
    {
        arg[strlen(arg) - 1] = '\0';
    }

    char *extra_arg = strtok(NULL, " \t"); // Check if there's more than one argument

    if (arg == NULL)
    {
        // No arguments, go to the home directory
        if (chdir(home_dir) != 0)
        {
            perror("cd error");
        }
    }
    else if (extra_arg != NULL)
    {
        printf("cd: too many arguments\n");
    }
    else if (strcmp(arg, "..") == 0)
    {
        if (chdir("..") != 0)
        {
            perror("cd error");
        }
    }
    else if (strcmp(arg, "-") == 0)
    {
        if (prev_dir[0] == '\0')
        {
            printf("cd: OLDPWD not set\n");
        }
        else
        {
            printf("%s\n", prev_dir);
            if (chdir(prev_dir) != 0)
            {
                perror("cd error");
            }
        }
    }
    else if (strcmp(arg, "~") == 0)
    {
        if (chdir(home_dir) != 0)
        {
            perror("cd error");
        }
    }
    else
    {
        if (chdir(arg) != 0)
        {
            perror("cd error");
        }
    }

    // Store the previous directory
    strcpy(prev_dir, curr_dir);
}