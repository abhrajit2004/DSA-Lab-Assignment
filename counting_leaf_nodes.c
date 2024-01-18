#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int getLeafCount(struct node *node)
{
    if (node == NULL)
        return 0;

    if (node->left == NULL && node->right == NULL)
    {
        return 1;
    }
    else
    {
        return getLeafCount(node->left) + getLeafCount(node->right);
    }
}

int main()
{
    struct node *root = createNode(4);
    struct node *n1 = createNode(1);
    struct node *n2 = createNode(6);
    struct node *n3 = createNode(5);
    struct node *n4 = createNode(2);
    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;

    printf("Leaf count of the tree is %d", getLeafCount(root));
    return 0;
}