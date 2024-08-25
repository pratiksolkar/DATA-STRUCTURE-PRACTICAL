//Deletion at Beg 
#include<stdio.h> 
#include<stdlib.h> 
struct node{ 
    int data; 
    struct node * next; 
}; 
 
void main() { 
    struct node *x,*y,*z,*first; 
    char ch; 
    y=(struct node *)malloc(sizeof(struct node)); 
    printf("Enter first node data :\n"); 
    scanf("%d",&y->data); 
    x=y;              // x points to the first node 
    first =x ;       // first keeps track of the start of the list 
    do{ 
        z=(struct node *)malloc(sizeof(struct node)); 
        printf("Enter next node data :\n"); 
        scanf("%d",&z->data); 
        y->next=z; 
        y=z; 
        printf("press y for next node :\n"); 
        ch=getch(); 
    }while(ch=='y'|| ch=='Y'); 
    y->next=NULL; 
 
    if(x==NULL){ 
        printf("UNderflow"); 
        return; 
    } 
     
    x=first; 
    first=first->next; 
    free(x); 
 
    x=first; 
    while(x!=NULL){ 
        printf("Element = %d \n",x->data); 
        x=x->next;} 
} 