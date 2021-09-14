#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    char s[200];
    while (1)
    {
        fgets(s,sizeof(s),stdin);
        system(s);
    }
    return 0;
}