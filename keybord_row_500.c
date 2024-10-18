#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 * https://leetcode.cn/problems/keyboard-row/description/
 */
char **findWords(char **words, int wordsSize, int *returnSize)
{
    *returnSize = 0;
    char **ans = (char **)malloc(wordsSize * sizeof(char *));
    int map[26] = {2, 3, 3, 2, 1, 2, 2, 2, 1, 2, 2, 2, 3, 3, 1, 1, 1, 1, 2, 1, 1, 3, 1, 3, 1, 3};
    for (int i = 0; i < wordsSize; i++)
    {
        bool bl = true;
        if (strlen(words[i]) < 2)
        {
            ans[(*returnSize)++] = strndup(words[i], strlen(words[i]));
            continue;
        }
        for (int j = 0; j < strlen(words[i]) - 1; j++)
        {
            printf("w(%d, %d) = %d   w(%d, %d) = %d \n", i, j, words[i][j], i, j + 1, words[i][j + 1]);
            if (map[toupper((words[i][j])) - 'A'] != map[toupper((words[i][j + 1])) - 'A'])
            {
                bl = false;
                break;
            }
        }

        if (bl)
        {
            ans[(*returnSize)++] = strndup(words[i], strlen(words[i]));
        }
    }
    return ans;
}

int main()
{
    char **words = (char **)malloc(4 * sizeof(char *));
    words[0] = strdup("cccd");
    words[1] = strdup("Alaska");
    words[2] = strdup("Dad");
    words[3] = strdup("Peace");

    int *returnSize = (int *)malloc(sizeof(int));

    char **ans = findWords(words, 4, returnSize);

    // 释放内存
    for (int i = 0; i < 4; i++)
    {
        free(words[i]);
    }
    free(words);
    return 0;
}