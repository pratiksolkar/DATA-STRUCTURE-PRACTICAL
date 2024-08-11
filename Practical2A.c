  #include<stdio.h>
  int main(){ 
    
    int a[100],n,i;
    printf("Enter the size of array: ");
    scanf("%d",&n);
 
    for(i=0;i<n;i++){
        printf("Enter the element at position %d = ",i+1);
        scanf("%d",&a[i]);
    }

    int pos;
    printf("Enter the position of element, where you want to insert: ");
    scanf("%d",&pos);

    int num;
    printf("Enter the number to insert: ");
    scanf("%d",&num);
    
    int temp=a[pos-1];
    
    for (int j=n;j>=pos-1;j--)
    {
        a[j]=a[j-1];

    }
    a[pos-1]=num;
    for (int i=0;i<=n;i++){
        printf("%d\t",a[i]);
  }
  }