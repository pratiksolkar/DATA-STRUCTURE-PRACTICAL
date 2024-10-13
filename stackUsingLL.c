 #include <stdio.h> 
#include <stdlib.h> 
 
struct node 
{ 
    int data; 
    struct node *next; 
};

struct node *Top = NULL;   
 
void push(int x) 
{ 
    struct node *new; 
    new = (struct node *)malloc(sizeof(struct node)); 
 
    if (new == NULL) { 
        printf("Stack Overflow\n"); 
        return; 
    } 
    new->data = x; 
    new->next = Top; 
    Top = new;      // Now the new node is at the top of the stack 
} 
 
void pop() 
{ 
    struct node *t; 
    if (Top == NULL)
    {
        printf("Stack is Underflow\n");
    }
    else
    { 
        t = Top; 
        Top = Top->next;  // Move Top to next node 
        free(t); 
        t = NULL; 
    } 
} 
 
void display()
{ 
    struct node *temp = Top; 
    if (Top == NULL) 
    { 
        printf("Stack is empty\n"); 
        return; 
    } 
    printf("Stack elements are:\n"); 
    while (temp != NULL)
    { 
        printf("%d\n", temp->data); 
        temp = temp->next; 
    } 
} 
 
int main() 
{ 
    int choose; 
    int value; 
 
    do { 
        printf("Choose the operation:- \n 1) Push \t 2) Pop \t 3) Print \t 4) Exit \n"); 
        scanf("%d", &choose);  // scan input 
 
        switch (choose)
        { 
        case 1: 
            printf("Enter value to push:- "); 
            scanf("%d", &value); 
            push(value); 
            break; 
        case 2: 
            pop(); 
            break; 
        case 3: 
            display(); 
            break; 
        case 4: 
            printf("Exit Successfully\n"); 
            break; 
        default: 
            printf("Please enter valid choice\n"); 
        } 
    } while (choose !=4); 
 
    return 0; 
}