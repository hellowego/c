#include <stdio.h>
#include <stdlib.h>
// https://leetcode.cn/problems/max-consecutive-ones/
int findMaxConsecutiveOnes(int *nums, int numsSize)
{
    int max = 0;
    int cnt = 0;
    for (int i = 0; i < numsSize - 1; i++)
    {
        if (nums[i] == 1)
        {
            cnt++;
            if (nums[i + 1] == 0)
            {
                if (max < cnt)
                {
                    max = cnt;
                }
                cnt = 0;
            }
        }
    }
    if (nums[numsSize - 1] == 1)
    {
        return max > (cnt + 1) ? max : (cnt + 1);
    }
    return max;
}

int main()
{
    int a[5] = {1, 1, 0, 0, 1};
    int ans = findMaxConsecutiveOnes(a, 5);
    return 0;
}