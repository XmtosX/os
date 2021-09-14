#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    for (int i=0;i<5;i++)
    {
        fork();
        sleep(5);
        system("pstree -p 9307");
    }
    return 0;
}