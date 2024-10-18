#include <stdio.h>
#include <stdlib.h>
/**
 * Definition for a binary tree node.

 */

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
/**
 * Note: The returned array must be malloced, assume caller calls free().
 * https://leetcode.cn/problems/find-mode-in-binary-search-tree/
 */

int cnt;
int maxcnt;
int base;
int *ans;
int ansSize;

void update(struct TreeNode *node)
{
    if (node->val == base)
    {
        cnt++;
    }
    else
    {
        cnt = 1;
        base = node->val;
    }
    if (cnt == maxcnt)
    {
        ans[ansSize++] = node->val;
    }
    if (cnt > maxcnt)
    {
        base = node->val;
        maxcnt = cnt;
        ansSize = 0;
        ans[ansSize++] = node->val;
    }
}

void dfs(struct TreeNode *node)
{
    if (node == NULL)
    {
        return;
    }

    dfs(node->left);
    update(node);
    dfs(node->right);
}

int *findMode(struct TreeNode *root, int *returnSize)
{
    base = cnt = maxcnt = 0;
    ans = (int *)malloc(4000 * sizeof(int));
    ansSize = 0;
    dfs(root);
    *returnSize = ansSize;
    return ans;
}

// 创建新节点并初始化
struct TreeNode *createTreeNode(int val)
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 释放二叉树内存
void freeTree(struct TreeNode *root)
{
    if (root == NULL)
        return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main()
{
    struct TreeNode *root = createTreeNode(0);
    // root->right = createTreeNode(2);
    // root->right->left = createTreeNode(2);
    int *returnsize = (int *)malloc(sizeof(int));

    ansSize = 0;
    int *a = findMode(root, returnsize);
    return 0;
}