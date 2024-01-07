#include<stdio.h>

int interpolationSearch(int arr[], int start, int end, int element){
    int pos;
    if(start<=end && element >= arr[start] && element <= arr[end]){
        pos = start + (element - arr[start])*((double)(end-start)/(arr[end]-arr[start]));
        if(arr[pos] == element){
            return pos;
        }
        else if(arr[pos] < element){
            return interpolationSearch(arr, pos + 1, end, element);
        }
        else{
            return interpolationSearch(arr, start, pos - 1, element);
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
    printf("Enter the element you want to find: ");
    scanf("%d",&element);
    printf("%d is found at index %d",element,interpolationSearch(arr,0,n-1,element));
    return 0;
}