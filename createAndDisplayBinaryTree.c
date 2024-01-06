#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *create()
{
    int nodeData;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the node data or -1 to for node\n");
    scanf("%d", &nodeData);
    if (nodeData == -1)
    {
        return 0;
    }
    newNode->data = nodeData;
    printf("Enter the left node:\n");
    newNode->left = create();
    printf("Enter the right node:\n");
    newNode->right = create();
    return newNode;
}

void preOrderBinaryTree(struct node *root)
{
    // root, left, right
    if (root == 0)
    {
        return;
    }
    printf("%d ", root->data);
    preOrderBinaryTree(root->left);
    preOrderBinaryTree(root->right);
}

void inOrderBinaryTree(struct node *root)
{
    if (root == 0)
    {
        return;
    }
    inOrderBinaryTree(root->left);
    printf("%d ", root->data);
    inOrderBinaryTree(root->right);
}

void postOrderBinaryTree(struct node *root)
{
    if (root == 0)
    {
        return;
    }
    postOrderBinaryTree(root->left);
    postOrderBinaryTree(root->right);
    printf("%d ", root->data);
}

int main()
{
    struct node *root = (struct node *)malloc(sizeof(struct node));
    root = create();
    preOrderBinaryTree(root);
    printf("\n");
    inOrderBinaryTree(root);
    printf("\n");
    postOrderBinaryTree(root);
}