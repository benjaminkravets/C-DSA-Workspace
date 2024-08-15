#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

#define MSGSIZE 16

char *msg1 = "Hello, World! 1";
char *msg2 = "Hello, World! 2";
char *msg3 = "Hello, World! 3";

char * msg[3] = {"Hello, World! 1", "Hello, World! 2", "Hello, World! 3"};

int pipe_interprocess()
{
    
    int p[2];
    char rx_msg[16];
    if (pipe(p) < 0)
        exit(1);

    pid_t pid = fork();

    if (pid == 0)
    {
        printf("Child sender %i \n", pid);
        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);
        return 0;
    }

    else
    {
        printf("Parent receiver %i \n", pid);
        for (int i = 0; i < 3; i++){
            read(p[0], rx_msg, MSGSIZE);
            printf("%s \n", rx_msg);
        }
        return 0;
    }
    return 0;

    
}

void pipe_intraprocess()
{
    int p[2];
    char rx_msg[16];

    if (pipe(p) < 0)
        exit(1);

    write(p[1], msg[0], MSGSIZE);
    write(p[1], msg[1], MSGSIZE);
    write(p[1], msg[2], MSGSIZE);

    for (int i = 0; i < 3; i++)
    {
        read(p[0], rx_msg, MSGSIZE);
        printf("%s \n", rx_msg);
    }
}

int main()
{
    pipe_intraprocess();
    //pipe_interprocess();
    return 0;
}