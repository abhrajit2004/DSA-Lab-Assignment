#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *new_node, *temp;

void enqueue(){
    new_node = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the value of new node: ");
    scanf("%d",&new_node->data);
    new_node->next = NULL;
    if(head == NULL){
        head = new_node;
    }
    else{
        temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void create_list(){
    char ch = 'y';
    while (ch=='Y' || ch=='y'){
        enqueue();
        printf("Want to create another node?");
        scanf(" %c",&ch);
    }
}

void display(){
    temp = head;
    while (temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

void dequeue(){
    printf("\nDequeue Operation");
    temp = head;
    head = head -> next;
    free(temp);
}

int main(){
    int ch;
	printf("1.Create Node\n2.Display\n3.Enqueue\n4.Dequeue\n5.Exit");
    while(ch!=5)
	{
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				create_list();
				break;
			case 2:
				display();
				break;
			case 3:
				enqueue();
				break;
			case 4:
				dequeue();
				break;
           	case 5:
               	printf("\nProgram exited\n");
		}
	}

    return 0;
}
