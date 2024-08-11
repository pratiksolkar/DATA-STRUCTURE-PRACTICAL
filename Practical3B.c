#include<stdio.h>
int main() {
    int a[100],i,j,num;

    printf("Enter the size of an array: ");
    scanf("%d",&num);

    printf("Enter the array element:\n");
    for ( i = 0; i < num; i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<num-1;i++)
    {
            for(int j=0;j<num-i-1;j++)
            {
                if (a[j]>a[j+1]) {
                    int temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                    
                }
            }
        }
    printf("The sorted elements are :\n");
    for ( j = 0; j < num; j++)
    {
        printf("%d\t",a[j]);
    }
}