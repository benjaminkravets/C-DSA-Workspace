#include <stdio.h> 
#include <unistd.h> 
#include <stdlib.h>

#define MSGSIZE 16 

char* msg1 = "hello, world #1"; 
char* msg2 = "hello, world #2"; 
char* msg3 = "hello, world #3"; 

char rx_msg[16];
  
int main() 
{ 
    char inbuf[MSGSIZE]; 
    int p[2], i; 
  
    if (pipe(p) < 0) 
        exit(1); 
  
    write(p[1], msg1, MSGSIZE); 
    write(p[1], msg2, MSGSIZE); 
    write(p[1], msg3, MSGSIZE); 
    

    for(int i = 0; i < 3; i++){

        read(p[0], rx_msg, MSGSIZE);
        printf("%s \n", rx_msg);

    }


    return 0; 
} 