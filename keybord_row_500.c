#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 * https://leetcode.cn/problems/keyboard-row/description/
 */
char **findWords(char **words, int wordsSize, int *returnSize)
{
    char **ans = (char **)malloc(wordsSize * sizeof(char *));
    int map[26] = {2, 3, 3, 2, 1, 2, 2, 2, 1, 2, 2, 2, 3, 3, 1, 1, 1, 1, 2, 1, 1, 3, 1, 3, 1, 3};
    for (int i = 0; i < wordsSize; i++)
    {
        for (int j = 0; j < strlen(words[i]) - 2; j++)
        {
            if (map[toupper((words[i][j])) - 'A'] != map[toupper((words[i][j + 1])) - 'A'])
            {
                continue;
            }
        }

        ans[(*returnSize)++] =
    }
}

int main()
{
    char **words = (char **)malloc(4 * sizeof(char *));
    words[0] = strdup("Hello");
    words[1] = strdup("Alaska");
    words[2] = strdup("Dad");
    words[3] = strdup("Peace");

    // 释放内存
    for (int i = 0; i < 4; i++)
    {
        free(words[i]);
    }
    free(words);
    return 0;
}