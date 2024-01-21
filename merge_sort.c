#include<stdio.h>


void merge(int arr[], int start, int mid, int end){
    int temp[end-start+1];
    int left = start, right = mid + 1, index=0;
    while (left<=mid && right<=end)
    {
        if(arr[left] <= arr[right]){
            temp[index] = arr[left];
            index++;
            left++;
        }
        else{
            temp[index] = arr[right];
            index++;
            right++;
        }
    }
    while(left<=mid){
        temp[index] = arr[left];
        index++;
        left++;
    }
    while(right<=end){
        temp[index] = arr[right];
        index++;
        right++;
    }
    index = 0;
    while(start<=end){
        arr[start] = temp[index];
        index++, start++;
    }
}

void mergeSort(int arr[], int start, int end){
    if(start == end)
     return;
    int mid = start + (end-start)/2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);
    merge(arr, start, mid, end);
}

int main(){
    int arr[20], size;
    printf("Enter the size: ");
    scanf("%d",&size);
    printf("Enter elements: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
    mergeSort(arr, 0, size - 1);
    for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
    
    return 0;
}