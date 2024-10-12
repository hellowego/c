#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// https://leetcode.cn/problems/teemo-attacking/

int findPoisonedDuration(int *timeSeries, int timeSeriesSize, int duration)
{
    int ans = 0;
    for (int i = 0; i < timeSeriesSize - 1; i++)
    {
        ans += timeSeries[i + 1] - timeSeries[i] < duration ? timeSeries[i + 1] - timeSeries[i] : duration;
    }

    return ans + duration;
}

int main()
{
    int a[2] = {1, 4};
    int ans = findPoisonedDuration(a, 2, 2);
    return 0;
}