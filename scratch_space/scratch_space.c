#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

void spi_send_receive(uint8_t array_to_print[], uint32_t n)
{

    printf("SPI SEND: ");
    for (uint32_t i = 0; i < n - 1; i++)
    {
        printf("%i ", array_to_print[i]);
    }
    printf("\nReceive %i bytes\n", array_to_print[n-1]);

    //printf("\n");
}

void spi_pause(uint32_t pause_for)
{
    printf("PAUSE: %i", pause_for);

    printf("\n");
}

void paws()
{
    uint8_t foo[] = "SR 1 56 78 255 3 4 P 10000 SR 45 6 8 9 62 2 P 2000 SR 1 32 54 234 E";

    uint8_t *next_tok = strtok(foo, " ");
    
    while (next_tok != NULL)
    {
        uint8_t tx_buffer[256];
        uint32_t cursor = 0;

        if (strcmp(next_tok, "SR") == 0)
        {
            next_tok = strtok(NULL, " ");

            while (isdigit(*next_tok))
            {
                tx_buffer[cursor++] = atoi(next_tok);
                next_tok = strtok(NULL, " ");
            }

            spi_send_receive(tx_buffer, cursor);

            continue;
        }
        // else if (strcmp(next_tok, "R") == 0)
        // {
        //     printf("%s receive %s\n", next_tok, strtok(NULL, " "));
        // }
        else if (strcmp(next_tok, "P") == 0)
        {
            next_tok = strtok(NULL, " ");

            spi_pause(atoi(next_tok));
        }
        else if (strcmp(next_tok, "E") == 0)
        {
            printf("END\n");
        }

        next_tok = strtok(NULL, " ");
    }
}


int test(int a) {

    char * a = "Hi there";
    
    a = "ih ereht";


    return 0;
}

int main()
{
    test(5);
    //paws();
}