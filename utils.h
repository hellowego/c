
#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

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