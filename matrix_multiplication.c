#include<stdio.h>

int main(){
    int arr1[10][10],arr2[10][10],result[10][10],m,n,p,q;
    printf("Enter the row and column size of first array: ");
    scanf("%d %d",&m,&n);
    printf("Enter the row and column size of second array: ");
    scanf("%d %d",&p,&q);
    if(n!=p){
        printf("Please change your inputs! Matrix Multiplication is only valid when column size of first array and row size of second array are same");
    }
    else{
     printf("Enter the elements of first matrix: ");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&arr1[i][j]);
        }
    }
    printf("The first matrix is:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
           printf("%d ",arr1[i][j]);
        }
        printf("\n");
    }

    printf("Enter the elements of second matrix: ");
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {
            scanf("%d",&arr2[i][j]);
        }
    }
    printf("The second matrix is:\n");
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {
           printf("%d ",arr2[i][j]);
        }
        printf("\n");
    }

    printf("Generated Multiplication result will be:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < p; k++)
            {
                result[i][j] += arr1[i][k]*arr2[k][j];
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < q; j++)
        {
            printf("%d ",result[i][j]);
        }
        printf("\n");
     }
    }
    
    return 0;
}