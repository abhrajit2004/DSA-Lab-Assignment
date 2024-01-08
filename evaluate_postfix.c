#include<stdio.h>
#include<ctype.h>

char stck[20];
int top = -1;

void push(char x){
    top = top + 1;
    stck[top] = x;
}

char pop(){
    return stck[top--];
}

int main(){
    char postfix[20];
    int i = 0;
    printf("Enter a posftix expression: ");
    gets(postfix);
    while (postfix[i] != '\0')
    {
        if(isdigit(postfix[i])){
            push(postfix[i] - '0');
        }
        else{
            int val1 = pop();
            int val2 = pop();
            switch (postfix[i])
            {
             case '+':
                push(val2 + val1);
                break;
             case '-':
                push(val2 - val1);
                break;
             case '*':
                push(val2 * val1);
                break;
             case '/':
                push(val2 / val1);
                break;
            }
        }
        i++;
    }
    
    printf("Postfix evaluation: %d",stck[top]);
    return 0;
}