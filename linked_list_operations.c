#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *new_node, *temp;

void insert_end(){
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
        insert_end();
        printf("Want to create another node?");
        scanf(" %c",&ch);
    }
}

void insert_begin(){
    printf("\nInserting a node at begining of the list");
	new_node=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the value of new node: ");
	scanf("%d",&new_node->data);
	new_node->next=head;
	head=new_node;
}

void display(){
    temp = head;
    while (temp!=NULL)
    {
        printf("%d---->",temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

int count(){
    int c=0;
    temp = head;
    while (temp!=NULL)
    {
        c++;
        temp = temp->next;
    }
    return c;
}

void insert_pos(){
    int pos,n,c=1;
    n = count();
    printf("\nEnter postion where you want to insert: ");
	scanf("%d",&pos);
    if(pos==1){
        insert_begin();
    }
    else if(pos == n+1){
        insert_end();
    }
    else if(pos>n+1){
        printf("\nInvalid Position");
    }
    else{
        temp = head;
        while (c<pos-1)
        {
            temp = temp->next;
            c++;
        }
        new_node = (struct node*)malloc(sizeof(struct node));
        printf("\nEnter the value of new node: ");
        scanf("%d",&new_node->data);
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

void delete_begin(){
    printf("\nDeleting a node from begining of the list");
    temp = head;
    head = head -> next;
    free(temp);
}

void delete_end(){
    printf("\nDeleting a node from end of the list");
    struct node *p;
    temp = head;
    while (temp->next!=NULL)
    {
        p = temp;
        temp = temp->next;
    }
    p->next = NULL;
    free(temp);
}

void delete_pos(){
    int pos,n,c=1;
    n = count();
    temp = head;
    printf("\nEnter postion from where you want to delete: ");
	scanf("%d",&pos);
    if(pos==1){
        delete_begin();
    }
    else if(pos == n){
        delete_end();
    }
    else if(pos>n){
        printf("\nInvalid Position");
    }
    else{
        temp = head;
        struct node *p;
        while (c<pos-1)
        {
            temp = temp->next;
            c++;
        }
        p = temp->next;
        temp->next = p->next;
        free(p);
    }
}

int main(){
    int ch;
	printf("1.Create List\n2.Display List\n3.Insert Begin\n4.Insert End\n5.Insert Position\n6.Delete from begin\n7.Delete from end\n8.Delete from any position\n9.Exit");
    while(ch!=9)
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
				insert_begin();
				break;
			case 4:
				insert_end();
				break;
			case 5:
				insert_pos();
				break;
            case 6:
               delete_begin();
               break;
            case 7:
               delete_end();
               break;
			case 8:
				delete_pos();
                break;
            case 9:
                printf("\nProgram exited\n");
		}
	}

    return 0;
}