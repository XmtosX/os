#include <stdio.h>

void swap(int *x, int *y)
{
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}

void bubble_sort(int n,int *a)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j] > a[j+1])
                swap(&a[j], &a[j+1]);
        }
    }
}


int main() 
{
    int n, a[202];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    bubble_sort(n,a);
    return 0;
}