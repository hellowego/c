#include <stdio.h>
#include <stdlib.h>
// https://leetcode.cn/problems/island-perimeter/description/
int islandPerimeter(int **grid, int gridSize, int *gridColSize)
{
    int ans = 0;
    int dx[4] = {0, 1, 0, 1};
    int dy[4] = {1, 0, 1, 0};
    // for (int i = 0; i < 4; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         printf("grid[%d][%d] = %d  ", i, j, grid[i][j]);
    //     }
    //     printf("\n");
    // }
    int m = gridSize;
    int n = *gridColSize;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int cnt = 0;
            if (grid[i][j])
            {
                for (int k = 0; k < 4; k++)
                {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (x < 0 || x >= m || y < 0 || y >= n || !grid[x][y])
                    {
                        cnt += 1;
                    }
                }
            }
            ans += cnt;
        }
    }
    return ans;
}

int dfs(int x, int y, int **grid, int m, int n)
{
    if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0)
    {
        return 1;
    }
    if (grid[x][y] == 2)
    {
        return 0;
    }
    int dx[4] = {0, 1, 0, 1};
    int dy[4] = {1, 0, 1, 0};
    int res = 0;

    grid[x][y] = 2;
    for (int k = 0; k < 4; k++)
    {
        int i = x + dx[k];
        int j = y + dy[k];
        res += dfs(i, j, grid, m, n);
    }

    return res;
}

int islandPerimeter1(int **grid, int gridSize, int *gridColSize)
{
    int ans = 0;
    int m = gridSize;
    int n = *gridColSize;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j])
            {
                ans += dfs(i, j, grid, m, n);
            }
        }
    }
    return ans;
}

int main()
{
    int a[4][4] = {{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};
    int **grid = (int **)malloc(4 * sizeof(int *));
    for (int i = 0; i < 4; i++)
    {
        grid[i] = (int *)malloc(4 * sizeof(int));
        for (int j = 0; j < 4; j++)
        {
            grid[i][j] = a[i][j];
        }
    }

    int *gridColSize = (int *)malloc(sizeof(int));
    *gridColSize = (int)4;
    int ans = islandPerimeter1(grid, 4, gridColSize);
    return 0;
}