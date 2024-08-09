#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t p = fork();

    //printf("\n %i, %i \n", p, getpid());
    if (p == 0){
        printf("Parent \n");
    } else {
        printf("Child \n");
    }

}