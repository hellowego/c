#include <stdio.h>
#include <stdbool.h>
int findComplement(int num)
{

    int num1 = num;
    int bit = 0;
    while (num1 > 0)
    {
        num1 = num1 >> 1;
        bit = (bit << 1) + 1;
    }
    int n1 = ~num & bit;

    // printf("取反%d\n", num1);
    // int n2 = num1 & 2147483647;
    return n1;
}

int main()
{
    findComplement(5);
}
