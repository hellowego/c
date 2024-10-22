#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *str[] = {"Gold Medal", "Silver Medal", "Bronze Medal"};
int cmp(const void *a, const void *b)
{
    const int *aa = (const int *)a;
    const int *bb = (const int *)b;
    return aa[0] - bb[0];
}
char **findRelativeRanks(int *score, int scoreSize, int *returnSize)
{
    int arr[scoreSize][2];
    *returnSize = 0;
    for (int i = 0; i < scoreSize; i++)
    {
        arr[i][0] = -score[i];
        arr[i][1] = i;
    }
    qsort(arr, scoreSize, sizeof(arr[0]), cmp);
    char **ans = (char **)malloc(scoreSize * sizeof(char *));
    for (int i = 0; i < scoreSize; i++)
    {
        for (int j = 0; j < scoreSize; j++)
        {
            if (score[i] == abs(arr[j][0]))
            {
                char *tmp = (char *)malloc(13 * sizeof(char));
                if (j < 3)
                {
                    // char *tmp1 = strndup(str[j], 12);
                    sprintf(tmp, "%s", str[j]);
                    // printf("%s\n", tmp);
                    ans[(*returnSize)++] = tmp;
                    break;
                }
                else
                {
                    sprintf(tmp, "%d", j + 1);
                    // printf("%s\n", tmp);
                    ans[(*returnSize)++] = tmp;
                    break;
                }
            }
        }
    }
    return ans;
}
int main()
{
    int arr[] = {10, 3, 8, 9, 4};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // qsort(arr, n, sizeof(arr[0]), cmp);

    int *returnsize = (int *)malloc(sizeof(int));
    char **ans = findRelativeRanks(arr, 5, returnsize);
    for (int i = 0; i < 5; i++)
    {
        printf("%s ", ans[i]);
    }
    printf("\n ");
    return 0;
}