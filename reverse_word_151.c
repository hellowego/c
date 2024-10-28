#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

char *reverseWords(char *s)
{
    int begin = 0;
    int len = strlen(s);
    char *ans = (char *)malloc((len + 1) * sizeof(char));
    int index = 0;
    bool b1 = false;
    for (int i = len - 1; i >= 0; i--)
    {
        if (s[i] != ' ' && !b1)
        {
            b1 = true;
            begin = i;
        }
        if ((s[i] == ' ' && b1) || (s[i] != ' ' && i == 0 && b1))
        {
            b1 = false;
            int j = i == 0 && s[i] != ' ' ? 0 : i + 1;
            for (; j <= begin; j++)
            {
                ans[index++] = s[j];
            }

            ans[index++] = ' ';
            printf("%s\n", ans);
        }
    }
    ans[index - 1] = '\0';

    return ans;
}

int main()
{
    char *s = " asdasd df f";
    char *res = reverseWords(s);
    printf("11%s11\n", res);
    return 0;
}