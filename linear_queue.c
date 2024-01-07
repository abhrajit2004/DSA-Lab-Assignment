#include<stdio.h>
#define MAXSIZE 10

int arr[MAXSIZE],front=-1,rear = -1,element;

void insert(){
   if(rear == MAXSIZE - 1){
    printf("\nQueue is full\n");
   }
   else{
     if(rear == -1){
        front = rear = 0;
     }
     else{
        rear = rear + 1;
     }
    printf("\nEnter the element you want to insert: ");
    scanf("%d",&element);
    arr[rear] = element;
    printf("\n%d is inserted in the queue\n",element);
   }
}

void delete(){
   if(front == -1){
    printf("\nQueue is empty\n");
   }
   else{
    printf("\n%d is deleted from the queue\n",arr[front]);
    if(front == rear){
        front = rear = -1;
    }
    else{
     front = front + 1;
    }
   }
}

void display(){
    for (int i = front; i <= rear; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    int choice;
    printf("\n---------LINEAR QUEUE OPERATIONS---------\n");
    printf("\na. Enter 1 for insert\nb. Enter 2 for delete\nc. Enter 3 for display\nd. Enter 4 for exit\n");
    while(choice!=4){
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
          case 1:
            insert();
            break;
          case 2:
            delete();
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