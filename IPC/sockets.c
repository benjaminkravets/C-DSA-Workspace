#include <stdlib.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <unistd.h>



int main()
{


    pid_t pid = fork();

    if (pid == -1)
    {
        printf("woops");
        exit(1);
    }
    else if (pid == 0)                      // fork returns 0 for child process
    {
        printf("child %i \r\n", getpid());
        exit(0);
    }
    else                                    // fork returns PID of new process for parent process
    {
        int child_status;

        struct sockaddr_un addr;
        
        

        waitpid(pid, &child_status, 0);     //wait for child to exit
        printf("parent %i \r\n", getpid());
        exit(0);
    }
};