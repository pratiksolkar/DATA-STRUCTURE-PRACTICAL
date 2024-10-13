#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int value)  // Function to push an element onto the stack
{
    if (top == MAX - 1) 
    {
        printf("Stack Overflow\n");
    }
    else 
    {
        top++;
        stack[top] = value;
        printf("%d pushed onto stack\n", value);
    }
}

int pop() // Function to pop an element from the stack
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    } 
    else 
    {
        int value = stack[top];
        top--;
        return value;
    }
}

void display()  // Function to display the stack elements
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    } 
    
    else 
    {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--) 
        {
            printf("%d\n", stack[i]);
        }
    }
}

int main() 
{
    push(10);
    push(20);
    push(30);
    display();
    printf("Popped element: %d\n", pop());
    display();
    return 0;
}