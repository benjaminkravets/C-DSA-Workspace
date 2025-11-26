#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <mqueue.h>
#include <string.h>

//use a message queue for asynchronous communication, message prioritization, and discrete messages

int main()
{

    char queue_name[] = "/queue_0";
    pid_t pid = fork();

    if (pid == -1)
    {
        printf("woops");
        exit(1);
    }
    else if (pid == 0)                     // fork returns 0 for child process
    {
        mqd_t mqd;
        struct mq_attr attr;
        char rcv_buffer[32];
        int priority;

        printf("child %i \r\n", getpid());

        mqd = mq_open(queue_name, O_RDONLY);
        if (mqd == (mqd_t)-1)
        {
            printf("mq_open failed \r\n");
            exit(1);
        }

        if (mq_getattr(mqd, &attr) == -1)
        {
            printf("mq_getattr failed \r\n");
            exit(1);
        }
        if (mq_receive(mqd, rcv_buffer, attr.mq_msgsize, &priority) == -1)
        {
            printf("mq_receive failed \r\n");
            exit(1);
        }

        printf("Recieved %s \r\n", rcv_buffer);

        exit(0);
    }
    else                                // fork returns PID of new process for parent process
    {
        int child_status;
        mqd_t mqd;
        struct mq_attr attr;

        attr.mq_flags = 0;              //may be O_NONBLOCK
        attr.mq_maxmsg = 10;            //max number of messages
        attr.mq_msgsize = 32;           //max message size
        attr.mq_curmsgs = 0;            //currently queued messages

        int priority = 10;             

        char send_buffer[32] = "hi";

        printf("parent %i \r\n", getpid());

        mqd = mq_open(queue_name, O_WRONLY | O_CREAT, 0666, &attr);

        if (mqd == -1)
        {
            printf("mq_open failed \r\n");
            exit(1);
        }

        if (mq_send(mqd, send_buffer, strlen(send_buffer), priority) == -1)
        {
            printf("mq_send failed \r\n");
            exit(1);
        }

        if (mq_close(mqd) == -1)
        {
            printf("mq_close failed \r\n");
            exit(1);
        }
        waitpid(pid, &child_status, 0); // wait for child to exit

        exit(0);
    }
};