#include<stdio.h>

void insertKey(int arr[], int n, int key){
    int loc = key % n;
    // Linear probing to handle collisions
    while (arr[loc] != 0)
    {
        loc = (loc+1) % n;
    }
    arr[loc] = key;
}

void displayArray(int arr[], int n){
    printf("Array elements: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    int n,k;
    int key;
    int hashArray[20];
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the number of keys to insert: ");
    scanf("%d", &k);

    if (k > n) {
        printf("Error: k should be less than or equal to n.\n");
    }

    for (int i = 0; i < n; i++)
    {
        hashArray[i] = 0;
    }

    printf("Enter %d keys: ",k);
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &key);
        insertKey(hashArray, n, key);
    }
    
    displayArray(hashArray, n);
    
    return 0;
}