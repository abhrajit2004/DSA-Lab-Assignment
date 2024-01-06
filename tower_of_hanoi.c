#include<stdio.h>

void towerOfHanoi(int n, char src, char aux, char dest){
    if(n==1){
        printf("Disk %d is shifted from rod %c to rod %c\n",n, src, dest);
        return;
    }
    towerOfHanoi(n-1, src, dest, aux);
    printf("Disk %d is shifted from rod %c to rod %c\n",n, src, dest);
    towerOfHanoi(n-1, aux, src, dest);
}
int main(){
    int n;
    printf("Enter the number of disks: ");
    scanf("%d",&n);
    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}