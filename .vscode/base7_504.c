#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverseString(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

char *convertToBase7(int num)
{
    int tmp = num;
    num = abs(num);
    int numsize = 0;
    char *ans = (char *)malloc(12 * sizeof(char));
    memset(ans, '\0', 12);
    if (num == 0)
    {
        ans[numsize++] = '0';
    }

    while (num > 0)
    {
        ans[numsize++] = num % 7 + '0';
        num /= 7;
    }
    if (tmp < 0)
    {
        ans[numsize] = '-';
    }
    reverseString(ans);
    return ans;
}

int main()
{
    char *ans = convertToBase7(-101);
    printf("ans:");
    for (int i = 0; i < 10; i++)
    {
        printf("%c ", ans[i]);
    }

    printf("\n ans: %s \n", ans);

    return 0;
}