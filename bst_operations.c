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
    int choice, data, element;
    struct node *root = NULL;
    printf("\n1. Insert Node\n2. Inorder Traversal\n3. Preorder Traversal\n4. Postorder Traversal\n5. Search Element\n6. Delete Node\n7. Exit\n");
    while(choice!=7){
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
          case 1:
            printf("Enter the value of new node: ");
            scanf("%d",&data);
            root = insertNode(root, data);
            printf("New node inserted\n");
            break;
          case 2:
            inorder(root);
            break;
          case 3:
            preorder(root);
            break;
          case 4:
            postorder(root);
            break;
          case 5:
             printf("\nEnter the element you want to search: ");
             scanf("%d",&element);
             if(searchElement(root,element) == NULL)
                printf("\n%d not found",element);
            else
               printf("\n%d found",element);
            break;
          case 6:
            printf("\nEnter the element you want to delete: ");
            scanf("%d",&element);
            root = deleteNode(root, element);
            printf("Node deleted\n");
            break;
          case 7:
            printf("Program exited");
        }
    }

    return 0;
}