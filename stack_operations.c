#include<stdio.h>
#define MAXSIZE 10

int arr[20],tos = -1, element;

void push(int element){
    if(tos == MAXSIZE - 1){
        printf("\nStack Overflow\n");
    }
    else{
        tos = tos + 1;
        arr[tos] = element;
        printf("\n%d is pushed to the stack\n",element);
    }
}

void pop(){
    if(tos == -1){
        printf("\nStack Underflow\n");
    }
    else{
        printf("\n%d is popped from the stack\n",arr[tos]);
        tos = tos - 1;
    }
}

void display(){
    for (int i = tos; i >= 0; i--)
    {
        printf("\n%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    int choice;
    printf("\n---------STACK OPERATIONS---------\n");
    printf("\na. Enter 1 for push\nb. Enter 2 for pop\nc. Enter 3 for display\nd. Enter 4 for exit\n");
    while(choice!=4){
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
          case 1:
            printf("\nEnter the element you want to push: ");
            scanf("%d",&element);
            push(element);
            break;
          case 2:
              pop();
              break;
          case 3:
             display();
             break;
          case 4:
            printf("\nProgram exited\n");
        }
    }
    return 0;
}