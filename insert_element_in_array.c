#include<stdio.h>

int main(){
    int arr[20],n,element,pos;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Array before insertion: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    
    printf("\nEnter the element and the position where you want to insert: ");
    scanf("%d %d",&element, &pos);
    for (int i = n; i > pos; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[pos] = element;
    printf("Array after insertion: ");
    for (int i = 0; i < n+1; i++)
    {
        printf("%d ",arr[i]);
    }
    
    return 0;
}