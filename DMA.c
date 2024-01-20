#include<stdio.h>
#include<stdlib.h>

int main(){
    int *ptr;
    int size;
    printf("Enter the size: ");
    scanf("%d",&size);
    ptr = (int *)malloc(size * sizeof(int));
    printf("Enter elements: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&(*(ptr+i)));
    }
    

    for (int i = 0; i < size; i++)
    {
        printf("%d ",*(ptr+i));
    }
    
    return 0;
}