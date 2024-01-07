#include<stdio.h>
#include<ctype.h>
char stck[20];
int top = -1;

void push(char x){
    top = top + 1;
    stck[top] = x;
}

char pop(){
    if(top==-1){
        return -1;
    }
    else{
        return stck[top--];
    }
}

int precedence(char x){
    if(x == '('){
        return 100;
    }
    else if(x == '^'){
        return 500;
    }
    else if(x == '*' || x == '/' || x == '%'){
        return 400;
    }
    else if(x == '+' || x == '-'){
        return 300;
    }
}

int main(){
    char infix[20], x;
    int i = 0;
    printf("Enter an infix expression: ");
    gets(infix);
    while (infix[i]!='\0')
    {
        if(infix[i] == '('){
            push(infix[i]);
        }
        else if(isalnum(infix[i])){
            printf("%c ",infix[i]);
        }
        else if (infix[i] == ')')
        {
            while ((x = pop())!='(')
            {
                printf("%c ", x);
            }
        }
        else{
            while (precedence(stck[top])>=precedence(infix[i]))
            {
                printf("%c ",pop());
            }
            push(infix[i]);
        }
        i++;
    }
    while (top!=-1)
    {
        printf("%c ",pop());
    }
    
    return 0;
}