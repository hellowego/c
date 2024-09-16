#include <stdio.h>
#include <stdbool.h>
int findComplement(int num)
{
    int num1 = ~num;
    printf("取反%d\n", num1);
    return num;
}

int main()
{
    findComplement(1);
}
