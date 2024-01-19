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

struct node *inOrderPredecessor(struct node *root){
  root = root->left;
  while (root->right != NULL)
  {
    root = root->right;
  }
  return root;
}

struct node* deleteNode(struct node *root, int key){
  struct node* iPre;
  if(root == NULL){
    return NULL;
  }
  if(root->left == NULL && root->right == NULL){
    free(root);
    return NULL;
  }
  if(key < root->data){
    root->left = deleteNode(root->left, key);
  }
  else if(key > root->data){
    root->right = deleteNode(root->right, key);
  }
  else{
    iPre = inOrderPredecessor(root);
    root->data = iPre->data;
    root->left = deleteNode(root->left, iPre->data);
  }
  return root;
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
  inorder(root);
  deleteNode(root, 6);
  printf("\n");
  // printf("|Data is %d|",root->data);
  inorder(root);
  // postorder(root);
  return 0;
}