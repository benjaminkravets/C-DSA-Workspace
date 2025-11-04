#include <stdlib.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <unistd.h>



int main()
{
    int system_page_size = sysconf(_SC_PAGE_SIZE);
    int *shared = mmap(
        NULL,                               // specify virtual address of memory to mao or leave NULL for kernel to decide
        2 * system_page_size,               // length of allocation
        PROT_READ | PROT_WRITE | PROT_EXEC, // specify protections
        MAP_ANONYMOUS | MAP_SHARED,         // cusomtizations- MAP_ANONYMOUS says pages aren't backed by any file (like in malloc), MAP_SHARED or MAP_PRIVATE could specify whether pages are shared across processes or owned by one
        -1,                                 // file descriptor; -1 since mapping is anonymous
        0                                   // specify offset into file to map

    );

    if (shared == MAP_FAILED) {
        perror("mmap failed");
        exit(1);
    }

    pid_t pid = fork();

    if (pid == -1)
    {
        printf("woops");
        exit(1);
    }
    else if (pid == 0)                      // fork returns 0 for child process
    {
        printf("child %i \r\n", getpid());
        shared[0] = 0x41;
        exit(0);
    }
    else                                    // fork returns PID of new process for parent process
    {
        int child_status;
        waitpid(pid, &child_status, 0);     //wait for child to exit
        printf("parent %i \r\n", getpid());
        printf("%c \r\n", shared[0]);
        munmap(shared, 2 * system_page_size);                //unmap memory
        exit(0);
    }
};