// C program to show thread functions 
  
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>

char fmt[] = "%s %s %s %s \n";

void use_vprintf(char *fmt, ...)
{
    va_list arg_ptr;
    // va_start accesses a variable arg list, gets arguments up to fmt- the last fixed variable
    va_start(arg_ptr, fmt);
    char * first = va_arg(arg_ptr, char *);
    printf("%s \r\n", first);
    // vprintf can be passed a variable number of strings like printf, but this can be passed as a va_list
    //vprintf(fmt, arg_ptr);
    // resets ptr to null, must be called before return
    va_end(arg_ptr);
}

void pass_variadic()
{
    use_vprintf(fmt, "Hello", "world", "Goodbye", "world");
}
  
// Driver code 
int main() 
{ 
    pass_variadic();
    return 0; 
} 