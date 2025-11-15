#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>

// pipes are unidirectional byte stream between processes implementated as a FIFO in the kernel. Used in pipe on command line. Anonymous pipes are destroyed when processes with associated file descriptors terminate.

int main()
{
    int pipe_ret;
    int pipe_fd[2];
    char test_string[] = "test string";
    char parent_read_buff[32];

    pipe_ret = pipe(pipe_fd);

    if (pipe_ret != 0)
    {
        perror("pipe creation failed");
        exit(1);
    }

    pid_t pid = fork();

    if (pid == -1)
    {
        printf("woops");
        exit(1);
    }
    else if (pid == 0) // fork returns 0 for child process
    {
        printf("child %i \r\n", getpid());
        close(pipe_fd[0]); // close read end to make sure write calls don't hang

        if (strlen(test_string) != write(pipe_fd[1], test_string, strlen(test_string)))
        {
            printf("write failed \r\n");
            exit(1);
        }
        exit(0);
    }
    else // fork returns PID of new process for parent process
    {
        printf("parent %i \r\n", getpid());
        close(pipe_fd[1]); // close write end to make sure read calls don't hang
        if (strlen(test_string) != read(pipe_fd[0], parent_read_buff, strlen(test_string)))
        {
            printf("read failed \r\n");
            exit(1);
        }

        printf("read %s from pipe \r\n", parent_read_buff);
        exit(0);
    }
}