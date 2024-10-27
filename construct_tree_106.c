#include <stdlib.h>
#include <stdio.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int inIndex(int *inorder, int treeSize, int val)
{
    for (int i = 0; i < treeSize; i++)
    {
        if (inorder[i] == val)
        {
            return i;
        }
    }
    return 0;
}

struct TreeNode *dfs(int *inorder, int *postorder, int treeSize, int inLeft, int inRight, int postLeft, int postRight)
{
    if (inLeft > inRight || postLeft > postRight)
    {
        return NULL;
    }
    printf("inorder  ");
    for (int i = inLeft; i < inRight + 1; i++)
    {
        printf("%d   ", inorder[i]);
    }
    printf("\n  ");
    printf("postorder  ");
    for (int i = postLeft; i < postRight + 1; i++)
    {
        printf("%d   ", postorder[i]);
    }
    printf("\n  ");
    struct TreeNode *treeRoot = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    treeRoot->val = postorder[postRight];
    int inRootIndex = inIndex(inorder, treeSize, treeRoot->val);
    int leftLenth = inRootIndex - inLeft;
    int rightLenth = inRight - inRootIndex;
    treeRoot->left = dfs(inorder, postorder, treeSize, inLeft, inRootIndex - 1, postLeft, postLeft + leftLenth - 1);
    treeRoot->right = dfs(inorder, postorder, treeSize, inRootIndex + 1, inRight, postRight - rightLenth, postRight - 1);

    return treeRoot;
}

struct TreeNode *buildTree(int *inorder, int inorderSize, int *postorder, int postorderSize)
{
    return dfs(inorder, postorder, inorderSize, 0, inorderSize - 1, 0, inorderSize - 1);
}

int main()
{
    int inorder[] = {9, 3, 15, 20, 7};
    int postorder[] = {9, 15, 7, 20, 3};
    struct TreeNode *treeRoot = buildTree(inorder, 5, postorder, 5);

    return 0;
}