#include <stdio.h>

void swapFunc (int *a,int *b)
{
    *a= *a+*b;
    *b= *a-*b;
    *a= *a-*b;
}



int main()
{
    int a,b;
    printf("Enter Two Integers To Be Swapped.\n");
    scanf("%d%d",&a,&b);
    swapFunc(&a,&b);
    printf ("%d %d",a,b);
}