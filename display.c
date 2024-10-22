#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <stdbool.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/utsname.h>

void display(char *home_dir)
{
    char hostname[1024];
    if (gethostname(hostname, 1024) != 0)
    {
        perror("Error getting hostname");
        return;
    }

    char cwd[1024];
    if (getcwd(cwd, 1024) == NULL)
    {
        perror("Error getting current working directory");
        return;
    }

    struct passwd *pws;
    pws = getpwuid(geteuid());
    if (pws == NULL)
    {
        perror("Error getting user information");
        return;
    }

    if (strstr(cwd, home_dir) != NULL)
    {
        char temp[1024];
        strcpy(temp, "~");
        strcat(temp, cwd + strlen(home_dir));
        printf("<%s@%s:%s>", pws->pw_name, hostname, temp);
    }
    else
    {
        printf("<%s@%s:%s>", pws->pw_name, hostname, cwd);
    }
}