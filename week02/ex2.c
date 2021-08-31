#include <stdio.h>
#include <string.h>

int main()
{
    char *s;
    printf("Enter a String.\n");
    scanf("%s",s);
    for (int i=0;i<strlen(s);i++)
    {
        printf("%c",s[strlen(s)-i-1]);
    }
    return 0;
}
