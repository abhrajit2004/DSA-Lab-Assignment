#include<stdio.h>

// Function to calculate the sum of digits in a number
int sumOfDigits(int num){
    int sum = 0;
    while (num>0)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

// Function to perform folding hash
int foldingHash(int key, int n){
    int sum = 0;

    sum = sumOfDigits(key);

    // Folding: Add the sum of digits in segments
    while (key > 0)
    {
        sum += key % 100;
        key /= 100;
    }

    return sum % n;
}

void insertKey(int arr[], int n, int key){
    int loc = foldingHash(key, n);

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