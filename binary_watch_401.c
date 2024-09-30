#include <stdio.h>
/**
 * https://leetcode.cn/problems/binary-watch/
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **readBinaryWatch(int turnedOn, int *returnSize)
{
    char **ans = (char **)malloc(12 * 60 * sizeof(char *));
    *returnSize = 0;
    for (int h = 0; h < 13; h++)
    {
        for (int m = 0; m < 60; m++)
        {
            if (__builtin_popcount(h) + __builtin_popcount(m) == turnedOn)
            {
                char *tem = (char *)malloc(6 * sizeof(char *));
                sprintf(tem, "%d:%02d", h, m);
                ans[(*returnSize)++] = tem;
            }
        }
    }

    return ans;
}
int main()
{
    return 0;
}