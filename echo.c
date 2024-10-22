#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <stdbool.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/utsname.h>

void parseInput(char *input)
{
    input += 4; // Skip the "echo" part
    while (*input == ' ' || *input == '\t')
        input++;

    bool inQuotes = false;
    while (*input != '\0')
    {
        if (*input == '\"')
        {
            inQuotes = !inQuotes;
        }
        else if (*input == ' ' || *input == '\t')
        {
            if (!inQuotes)
            {
                printf(" ");
                while (*input == ' ' || *input == '\t')
                    input++;
                input--;
            }
            else
            {
                printf("%c", *input);
            }
        }
        else
        {
            printf("%c", *input);
        }
        input++;
    }
    printf("\n");
}
