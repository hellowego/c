#include <stdlib.h>
#include <stdio.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct Treenode *right;
};

int inorderRoot(int *inorder, int inorderSize, int rootVal)
{
    for (int i = 0; i < inorderSize; i++)
    {
        if (inorder[i] == rootVal)
        {
            return i;
        }
    }
    return 0;
}

struct TreeNode *dfs(int *preorder, int *inorder, int treeSize, int preleft, int preRight, int inLeft, int inRight)
{
    if (preleft > preRight)
    {
        return NULL;
    }
    int preorder_root = preleft;

    struct TreeNode *rootNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    int inorder_root = inorderRoot(inorder, treeSize, preorder[preleft]);
    int leftSize = inorder_root - inLeft;
    rootNode->val = preorder[preleft];
    rootNode->left = dfs(preorder, inorder, treeSize, preleft + 1, preleft + leftSize, inLeft, inorder_root - 1);
    rootNode->right = dfs(preorder, inorder, treeSize, preleft + leftSize + 1, inorder_root, +1, inRight);

    return rootNode;
}

struct TreeNode *buildTree(int *preorder, int preorderSize, int *inorder, int inorderSize)
{
    return dfs(preorder, inorder, preorderSize, inorderSize, 0, preorderSize - 1, 0, inorderSize - 1);
}