#include <stdio.h>

int main()
{
    int n= __INT_MAX__;
    float f = __FLT_MAX__;
    double d= __DBL_MAX__;
    printf("Integer Size: %lu , Integer Value: %d\n",sizeof(n),n);
    printf("FLoat Size: %lu , Float Value: %f\n",sizeof(f),f);
    printf("Double Size: %lu , Doable Value: %lf\n",sizeof(d),d);
}