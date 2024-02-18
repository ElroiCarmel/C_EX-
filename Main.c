#include "StrList.h"
#include <stdio.h>
#include <string.h>

int main()
{
    printf("size of const int: %ld\n", sizeof(const int));
    printf("size of int: %ld\n", sizeof(int));
    const int num = 45;
    const int *ptr = &num;
    int num2 = 22;
    ptr = &num2;
    return 0;
}