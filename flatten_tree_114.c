
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "utils.h"

void dfs(struct TreeNode *root, struct TreeNode *head)
{
    if (root == NULL)
    {
        return;
    }
    struct TreeNode *temp = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    temp->val = root->val;
    temp->right = NULL;
    temp->left = NULL;
    head->right = temp;
    head = temp;
    dfs(root->left, head);
    dfs(root->right, head);
}

void flatten(struct TreeNode *root)
{
    struct TreeNode *head = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    head->left = NULL;
    head->right = NULL;
    head->val = 110;
    struct TreeNode *temp1 = head;
    dfs(root, head);
    struct TreeNode *temp2 = temp1->right;
    root = temp2;
    printf("%d", head->right->val);
}

int main()
{
    struct TreeNode *root = createTreeNode(1);
    root->left = createTreeNode(2);
    root->right = createTreeNode(3);

    flatten(root);
    return 0;
}
