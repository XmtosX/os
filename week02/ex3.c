#include <stdio.h>

void calc (int n)
{
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (j>=(n-i))
                printf("* ");
            else
                printf("  ");
        }
        printf("* ");
        for (int j=n-1;j>=0;j--)
        {
            if (j>=(n-i))
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
}

int main(int argc, char* argv[])
{
    int n;
    sscanf(argv[1],"%d",&n);
    calc(n);
    return 0;
}
