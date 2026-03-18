// C program to show thread functions
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <iso646.h>

int global_var = 42; // global/static variable



int main()
{
    // int local_var = 10;         // local variable (stack)
    // int *heap_var = malloc(sizeof(int)); // heap variable
    // *heap_var = 99;

    // printf("Addresses in this process:\n");
    // printf("Code (main function)   : %p\n", (void*)main);
    // printf("Global variable       : %p\n", (void*)&global_var);
    // printf("Heap allocation       : %p\n", (void*)heap_var);
    // printf("Local variable (stack): %p\n", (void*)&local_var);

    // // Optional: mmap a region
    // void *mmap_ptr = mmap(NULL, 4096, PROT_READ | PROT_WRITE,
    //                       MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    // if (mmap_ptr != MAP_FAILED) {
    //     printf("Memory mapped region  : %p\n", mmap_ptr);
    //     munmap(mmap_ptr, 4096);
    // }

    // free(heap_var);

    // return 0;

    __uint8_t a = 1;

    printf("%i \r\n", a << 2);
}
