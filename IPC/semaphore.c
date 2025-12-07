#include <stdlib.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>

#define NAME "/semaphore0"


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
        sleep(1);
        sem_t * child_semaphore = sem_open(NAME, 0);
        for (int i = 0 ; i < 2; i++) {
            sem_wait(child_semaphore);
            printf("sem give \r\n");
        }        
        printf("child %i \r\n", getpid());
        exit(0);
    }
    else                                    // fork returns PID of new process for parent process
    {
        sem_t * parent_semaphore = sem_open(NAME, O_CREAT, 0660, 0);
        for (int i = 0 ; i < 2; i++) {
            sem_post(parent_semaphore);
            printf("sem give \r\n");
            sleep(1);
        }

        int child_status;
        waitpid(pid, &child_status, 0);     //wait for child to exit
        printf("parent %i \r\n", getpid());

        exit(0);
    }
};