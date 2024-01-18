#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *left;
  struct node *right;
};

struct node *createNode(int data){
  struct node *n = (struct node *)malloc(sizeof(struct node));
  n->data = data;
  n->left = NULL;
  n->right = NULL;
  return n;
}

void insert(struct node *root, int key){
    struct node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if(key == root->data){
            printf("Cannot insert %d, already in BST\n",key);
            return;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else{
            root = root->right;
        }
    }

    struct node* newnode = createNode(key);
    if(key < prev->data){
        prev->left = newnode;
    }
    else{
        prev->right = newnode;
    }
}


void inorder(struct node *root){
  if(root != NULL){
    inorder(root->left);
    printf("%d->", root->data);
    inorder(root->right);
  }
}

void preorder(struct node *root){
  if(root != NULL){
    printf("%d->", root->data);
    preorder(root->left);
    preorder(root->right);
  }
}

void postorder(struct node *root){
  if(root != NULL){
    postorder(root->left);
    postorder(root->right);
    printf("%d->", root->data);
  }
}

int main(){
  struct node *root = createNode(5);
  struct node *n1 = createNode(3);
  struct node *n2 = createNode(1);
  struct node *n3 = createNode(4);
  struct node *n4 = createNode(6);
  root->left = n1;
  root->right = n4;
  n1->left = n2;
  n1->right = n3;

  // preorder(root);
  insert(root, 7);
  inorder(root);
 
  // postorder(root);
  return 0;
}