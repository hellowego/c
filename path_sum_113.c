#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "utils.h"

// struct TreeNode
// {
//     int val;
//     struct TreeNode *left;
//     struct Treenode *right;
// };

int **res;
int pathIndex = 0;
int *nodesPath;
int columnSize = 0;
int cnt = 0;
int *retColumnSize;

void dfs(struct TreeNode *root, int targetSum)
{
    if (root == NULL)
    {
        return;
    }
    nodesPath[pathIndex++] = root->val;
    targetSum -= root->val;
    if (root->left == NULL && root->right == NULL && targetSum == 0)
    {
        int *temp = (int *)malloc(pathIndex * sizeof(int));
        memcpy(temp, nodesPath, sizeof(int) * pathIndex);
        retColumnSize[cnt] = pathIndex;
        res[cnt++] = temp;
    }
    dfs(root->left, targetSum);
    dfs(root->right, targetSum);
    pathIndex--;
}

int **pathSum(struct TreeNode *root, int targetSum, int *returnSize, int **returnColumnSizes)
{
    res = (int **)malloc(2001 * sizeof(int *));
    retColumnSize = (int *)malloc(2001 * sizeof(int));
    nodesPath = (int *)malloc(sizeof(int) * 2001);
    pathIndex = cnt = 0;

    dfs(root, targetSum);
    *returnSize = cnt;
    *returnColumnSizes = retColumnSize;

    return res;
}

int main()
{
    struct TreeNode *root = createTreeNode(1);
    root->left = createTreeNode(2);
    root->right = createTreeNode(3);
    int *returnSize1 = (int *)malloc(sizeof(int));
    int **returnColumnSizes1;
    int **res1 = pathSum(root, 5, returnSize1, returnColumnSizes1);
    printf("returnSize1: %d \n", *returnSize1);

    for (int i = 0; i < *returnSize1; i++)
    {
        for (int j = 0; j < *returnColumnSizes1[i]; j++)
        {
            printf(" %d ", res1[i][j]);
        }
        printf("\n");
    }

    return 0;
}