#include<stdio.h>

int main(){
    int arr[20],n,pos;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Array before deletion: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    
    printf("\nEnter the position from where you want to delete: ");
    scanf("%d", &pos);
    for (int i = pos; i < n-1; i++)
    {
        arr[i] = arr[i+1];
    }
    printf("Array after deletion: ");
    for (int i = 0; i < n-1; i++)
    {
        printf("%d ",arr[i]);
    }
    
    return 0;
}