#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h> 
#include <string.h>

#define MAX 100  // Stack structure for characters
 
typedef struct
{ 
char items[MAX]; 
int top; 
}
Stack;  
void init_stack(Stack *s) // Initialize stack
{ 
s->top = -1; 
}  
int is_empty(Stack *s)  // Check if stack is empty
{ 
return s->top == -1; 
} 

void push(Stack *s, char item)  // Push element onto stack 
{ 
s->items[++(s->top)] = item; 
} 
 
char pop(Stack *s)  // Pop element from stack
{ 
return s->items[(s->top)--]; 
} 
 
char peek(Stack *s)  // Peek top element
{ 
return s->items[s->top]; 
} 
 
int precedence(char op)  // Check precedence of operators
{ 
if (op == '+' || op == '-') return 1; 
if (op == '*' || op == '/') return 2; 
if (op == '^') return 3; 
return 0; 
} 

int is_operator(char c)  // Function to check if character is an operator 
{ 
return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^'); 
} 
 
 
void reverse_string(char* str)  // Function to reverse a string
{ 
    int n = strlen(str); 
    for (int i = 0; i < n / 2; i++)
    { 
        char temp = str[i]; 
        str[i] = str[n - i - 1]; 
        str[n - i - 1] = temp; 
    } 
} 
 

void infix_to_postfix(char* infix, char* postfix) // Infix to Postfix Conversion 
{ 
    Stack s; 
    init_stack(&s); 
    int i = 0, k = 0; 
    char c; 
 
    while ((c = infix[i++]) != '\0') 
    { 
        if (isalnum(c)) // Operand 
        {  
            postfix[k++] = c; 
        } else if (c == '(')
        { 
            push(&s, c); 
        }
        else if (c == ')')
        { 
            while (!is_empty(&s) && peek(&s) != '(')
            { 
                postfix[k++] = pop(&s); 
            } 
            pop(&s);                       // Remove '(' from stack 
        }
        else if (is_operator(c))
        { 
            while (!is_empty(&s) && precedence(c) <= precedence(peek(&s)))
            { 
                postfix[k++] = pop(&s); 
            } 
            push(&s, c); 
        } 
    } 
 
    while (!is_empty(&s))
    { 
        postfix[k++] = pop(&s); 
    } 
 
    postfix[k] = '\0';  // Null-terminate the result 
} 
 
 
void infix_to_prefix(char* infix, char* prefix)  // Infix to Prefix Conversion
{ 
    reverse_string(infix);           // Reverse infix expression 
    for (int i = 0; infix[i]; i++)  // Swap '(' and ')'
    {   
        if (infix[i] == '(') infix[i] = ')'; 
        else if (infix[i] == ')') infix[i] = '('; 
    } 
    infix_to_postfix(infix, prefix);  // Get postfix of reversed infix 
    reverse_string(prefix);          // Reverse postfix to get prefix 
} 
 
 
int evaluate_postfix(char* postfix) // Evaluate Postfix Expression
{ 
    Stack s; 
    init_stack(&s); 
    int i = 0; 
    char c; 
 
    while ((c = postfix[i++]) != '\0')
    { 
        if (isdigit(c)) // Operand
        {   
            push(&s, c - '0');  // Convert character to integer 
        }
        else  // Operator
        {   
            int val1 = pop(&s); 
            int val2 = pop(&s); 
            switch (c)
            { 
                case '+': push(&s, val2 + val1); break; 
                case '-': push(&s, val2 - val1); break; 
                case '*': push(&s, val2 * val1); break; 
                case '/': push(&s, val2 / val1); break; 
            } 
        } 
    } 
 
    return pop(&s);  // Final result 
} 
  
void menu()   // Menu function
{ 
    char infix[MAX], postfix[MAX], prefix[MAX]; 
    int choice; 
 
    while (1)
    { 
        printf("\nMenu:\n"); 
        printf("1. Infix to Postfix\n"); 
        printf("2. Infix to Prefix\n"); 
        printf("3. Evaluate Postfix Expression\n"); 
        printf("4. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice)
        { 
            case 1: 
                printf("Enter an infix expression: "); 
                scanf("%s", infix); 
                infix_to_postfix(infix, postfix); 
                printf("Postfix expression: %s\n", postfix); 
                break; 
 
            case 2: 
                printf("Enter an infix expression: "); 
                scanf("%s", infix); 
                infix_to_prefix(infix, prefix); 
                printf("Prefix expression: %s\n", prefix); 
                break; 
 
            case 3: 
                printf("Enter a postfix expression (digits only): "); 
                scanf("%s", postfix); 
                printf("Result of postfix evaluation: %d\n", evaluate_postfix(postfix)); 
                break; 
 
            case 4: 
                printf("Exiting...\n"); 
                exit(0); 
 
            default: 
                printf("Invalid choice. Please try again.\n"); 
        } 
    } 
} 
 
int main() { 
    menu(); 
    return 0; 
}