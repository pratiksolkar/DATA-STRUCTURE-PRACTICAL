 #include<stdio.h>
 int main (){ 
    
    int a[100],n,i, position,j;
    printf("Enter the size of array: ");
    scanf("%d",&n);
 
    for(i=0;i<n;i++){
        printf("Enter the array element at position %d = ",i+1);
        scanf("%d",&a[i]);
    }
    printf("Enter the element position which you want to delete: ");
    scanf("%d",&position);
    for(j=position-1;j<n-1;j++)
    {
        a[j]=a[j+1];
        printf("Resultant array is:\n");
            }
            
            for(j=0;j<n-1;j++)
            {
                printf("%d\n",a[j]);
            }

 return 0;
}