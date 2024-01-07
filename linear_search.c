#include<stdio.h>


int linearSearch(int arr[], int n, int element){
    for (int i = 0; i < n; i++)
    {
        if(element == arr[i]){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[10],n,element;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("The array is: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    printf("Enter the element you want to find: ");
    scanf("%d",&element);
    printf("%d is found at index %d",element,linearSearch(arr,n,element));
    
    return 0;
}