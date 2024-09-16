#include <stdio.h>

int min(int x, int y)
{
    return (x < y) ? x : y;
}

int max(int x, int y)
{
    return (x > y) ? x : y;
}

int maxProfit(int *prices, int priceSize)
{
    int maxprofit = 0;
    int minprice = 1e9;
    for (int i = 0; i < priceSize; i++)
    {
        minprice = min(minprice, prices[i]);
        maxprofit = max(maxprofit, prices[i] - minprice);
    }

    return maxprofit;
}

int main()
{

    return 0;
}