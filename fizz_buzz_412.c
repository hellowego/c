#include <stdio.h>
#include <string.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **fizzBuzz(int n, int *returnSize)
{
    *returnSize = n;
    char **ans = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++)
    {
        int num = i + 1;
        if (num % 15 == 0)
        {
            char *tmp = (char *)malloc(9 * sizeof(char));
            strcpy(tmp, "FizzBuzz");
            ans[i] = tmp;
        }
        else if (num % 3 == 0)
        {
            char *tmp = (char *)malloc(5 * sizeof(char));
            strcpy(tmp, "Fizz");
            ans[i] = tmp;
        }
        else if (num % 5 == 0)
        {
            char *tmp = (char *)malloc(5 * sizeof(char));
            strcpy(tmp, "Buzz");
            ans[i] = tmp;
        }
        else
        {
            char *tmp = (char *)malloc(10 * sizeof(char));
            sprintf(tmp, "%d", num);
            ans[i] = tmp;
        }
    }
    return ans;
}
int main()
{
    int *returnSize = (int *)malloc(sizeof(int));
    char **res = fizzBuzz(3, returnSize);
    for (int i = 0; i < 3; i++)
    {
        printf("%s  ", res[i]);
    }
    printf("\n  ");
    free(res);
    return 0;
}