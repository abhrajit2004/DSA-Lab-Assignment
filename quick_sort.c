#include<stdio.h>

int partition(int arr[], int start, int end){
    int pos = start;
    for (int i = start; i <= end; i++)
    {
        if(arr[i] <= arr[end]){
            int temp = arr[i];
            arr[i] = arr[pos];
            arr[pos] = temp;
            pos++;
        }
    }
    return pos-1;
}
void quickSort(int arr[], int start, int end){
    if(start >= end)
      return;
    
    int pivot = partition(arr, start, end);
    quickSort(arr, start, pivot - 1);
    quickSort(arr, pivot + 1, end);
}
int main(){
     int arr[10],n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    quickSort(arr, 0, n-1);
    printf("The sorted array is: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}