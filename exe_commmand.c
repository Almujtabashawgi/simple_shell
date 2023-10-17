#include "main.h"
/***/
int exe_command(char **commmand)
{
    int status;
    pid_t pid;

    pid = fork();
    if(pid == -1)
    {
        return(0);
    }

    if (pid == 0)
    {
        if(execve(commmand[0], commmand, environ) == -1)
        {
            perror(environ[0]);
            freeArray(commmand);
            exit (127);
        }
    }
    else
    {
        waitpid(pid, &status, 0);
        freeArray(commmand);
    }

    return(WEXITSTATUS(status));
}