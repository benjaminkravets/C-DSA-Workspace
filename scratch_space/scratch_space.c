#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>


void paws(){
    uint8_t foo[] = "S PBCDE P 1000 S EDFSJ P 0x10 S sde END";

    uint8_t *next_tok;

    next_tok = strtok(foo, " ");

    do
    {
        if (next_tok != NULL)

            if (strcmp(next_tok, "S") == 0)
            {
                printf("%s send %s\n", next_tok, strtok(NULL, " "));
            }
            else if (strcmp(next_tok, "R") == 0)
            {
                printf("%s receive %s\n", next_tok, strtok(NULL, " "));
            }
            else if (strcmp(next_tok, "P") == 0)
            {
                printf("%s pause %s\n", next_tok, strtok(NULL, " "));
            }
            else if (strcmp(next_tok, "END") == 0)
            {
                printf("%s end\n", next_tok);
            }

        next_tok = strtok(NULL, " ");

    } while (next_tok != NULL);

}

int main()
{

    paws();
}