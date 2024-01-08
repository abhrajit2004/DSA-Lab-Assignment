#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(struct node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ->",root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root){
    if(root!=NULL){
        printf("%d ->",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ->",root->data);
    }
}

struct node *insertNode(struct node *node, int data){
    if(node == NULL)
        return newNode(data);

    if(data < node->data)
        node->left = insertNode(node->left, data);
    
    else
        node->right = insertNode(node->right, data);

    return node;
}

struct node *minValueNode(struct node *node){
    struct node *current = node;
    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

struct node *deleteNode(struct node *root, int data){
    if(root == NULL)
      return root;
    
    if(data < root->data)
      root->left = deleteNode(root->left, data);
    else if(data > root->data)
      root->right = deleteNode(root->right, data);
    
    else{
        if(root->left == NULL){
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
           struct node *temp = root->left;
           free(root);
           return temp;
        }

        struct node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

struct node *searchElement(struct node* root, int element){
    if(root == NULL || root->data == element){
        return root;
    }
    if(element > root->data){
        return searchElement(root->right, element);
    }

    return searchElement(root->left, element);
}

int main(){
    struct node *root = NULL;
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    printf("Original BST: ");
    inorder(root);
    int element = 60;
    if(searchElement(root,element) == NULL)
       printf("\n%d not found",element);
    
    else
       printf("\n%d found",element);

    root = deleteNode(root, 50);
    printf("\nBST after deletion: ");
    inorder(root);
    return 0;
}