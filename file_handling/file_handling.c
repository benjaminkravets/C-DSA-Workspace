#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    //'w' destroy current file contents
    FILE *file_ptr = fopen("input_file.txt", "w");
    char data_for_file[100] = "Characters for file";

    // check if open succeeded, write string
    if (file_ptr != NULL)
    {

        if (strlen(data_for_file) > 0)
        {
            fputs(data_for_file, file_ptr);
            fputs("\n", file_ptr);
        }

        fclose(file_ptr);
    }
    else
    {
        printf("File open failed \r\n");
    }

    file_ptr = fopen("input_file.txt", "r");
    char data_from_file[100];

    // check if open succeeded, read string
    if (file_ptr != NULL)
    {

        fgets(data_from_file, 100, file_ptr);

        fclose(file_ptr);

        printf("Read from file: %s \r\n", data_from_file);
    }
    else
    {

        printf("File open failed \r\n");
    }
}