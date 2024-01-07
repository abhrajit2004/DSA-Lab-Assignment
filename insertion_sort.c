#include<stdio.h>

int main(){
    int arr[10],n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while ((temp<arr[j])&&(j>=0))
        {
           arr[j+1] = arr[j];
           j--;
        }
        arr[j+1] = temp;
    }
    printf("Array after sorting is: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    
    return 0;
}