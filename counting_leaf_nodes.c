#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int getLeafCount(struct node *node){
    if(node == NULL)
      return 0;

    if(node->left == NULL && node->right == NULL){
        return 1;
    }
    else{
        return getLeafCount(node->left) + getLeafCount(node->right);
    }

}

int main(){
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    printf("Leaf count of the tree is %d", getLeafCount(root));
    return 0;
}