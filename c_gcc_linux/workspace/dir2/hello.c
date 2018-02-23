#include <stdio.h>
#include "world.c"
int main()
{
    int a1=33;
    int a2=21;
    int _max = max(a1,a2);
    printf("max=%d",_max);
    return 0;
}
