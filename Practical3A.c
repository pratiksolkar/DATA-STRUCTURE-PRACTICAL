#include<stdio.h>
int main() {
    int a[100],i,n,j;

    printf("Enter the size of an array: ");
    scanf("%d",&n);

    printf("Enter the array elements:\n");

    for ( i = 0; i < n; i++){
        scanf("%d",&a[i]);}

    for(int i=0;i<n-1;i++){
            int smallest=i;
            for(int j=i+1;j<n;j++){
                if (a[smallest]>a[j]) {
                    smallest=j;
                }
            }
            int temp=a[smallest];
            a[smallest]=a[i];
            a[i]=temp;
        }

         printf("The new array is:\n");
    for ( j = 0; j < n; j++)
    {
        printf("%d\t",a[j]);
    }
}