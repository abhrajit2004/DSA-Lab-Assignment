#include<stdio.h>

int binarySearch(int arr[], int start, int end, int element){
    int mid = start + (end - start)/2;
    while (start <= end)
    {
        if(arr[mid] == element){
            return mid;
        }
        else if (element > arr[mid])
        {
            return binarySearch(arr, mid + 1, end, element);
        }
        else{
            return binarySearch(arr, start, mid - 1, element);
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
    printf("%d is found at index %d",element,binarySearch(arr, 0, n-1, element));
    
    return 0;
}