#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int dfs(int *nums, int numsSize, int index)
{
    if (index == numsSize)
    {
        return 0;
    }
    return 0;
}

bool canJump(int *nums, int numsSize)
{
    return 0;
}

int jump(int *nums, int numsSize)
{
    int index = numsSize;
    int cnt = 0;
    if (numsSize == 1)
    {
        return 0;
    }
    while (index > 0)
    {
        for (int i = 0; i < index; i++)
        {
            if (nums[i] + i >= index)
            {
                index = i;
                cnt++;
                break;
            }
        }
    }
    return cnt;
}

int main()
{
    int nums[] = {2, 3, 1, 1, 4};
    for (int i = 0; i < 5; i++)
    {
        printf("%d  ", nums[i]);
    }
    printf("\n");
    int ans = jump(nums, 5);

    return 0;
}
