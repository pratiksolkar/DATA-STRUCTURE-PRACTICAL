#include<stdio.h>
int main(){

    int a[100], i, n, n1, n2;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter element: ", i + 1);
        scanf("%d", &a[i]);
    }

    printf("Which element you want to update: ");
    scanf("%d", &n1);

    printf("Enter the updated element: ");
    scanf("%d", &n2);

    for (i = 0; i < n; i++) {
        if (a[i] == n1) {
            a[i] = n2;
        }
    }

    printf("Updated array: \n");
    for (i = 0; i < n; i++) {
        printf("%d\n", a[i]);
    }
}