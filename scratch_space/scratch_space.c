#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

void paws()
{
    uint8_t foo[] = "S 1 56 78 255 3 4 P 10000 S 45 6 8 9 62 2 P 2000 SR 1 32 54 234 E";

    uint8_t *next_tok;

    next_tok = strtok(foo, " ");

    do
    {

        if (strcmp(next_tok, "S") == 0)
        {
            printf("%s send ", next_tok);
            do
            {
                printf("%s ", next_tok);
                next_tok = strtok(NULL, " ");

            } while (isdigit(*next_tok));

            printf("\n");

            continue;
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

void test(){
    printf("%i \n", isdigit('9'));
}

int main()
{
    //test();
    paws();
}