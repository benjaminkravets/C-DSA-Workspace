#include <stdio.h>
 
struct Record {
    int x = 7;
};
 
// Driver Program
int main()
{
    struct Record s;
    printf("%d", s.x);
    return 0;
}