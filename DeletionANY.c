//ddeletion at any position 
 
#include<stdio.h> 
#include<stdlib.h> 
struct node{ 
    int data; 
    struct node * next; 
}; 
 
void main() { 
    struct node *x,*y,*z,*first; 
    char ch; 
    int key; 
    y=(struct node *)malloc(sizeof(struct node)); 
    printf("Enter first node data :\n"); 
    scanf("%d",&y->data); 
    x=y;              // x yoints to the first node 
    first =x ;       // first keeys track of the start of the list 
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
 
    printf("Enter data of node to delete :\n"); 
    scanf("%d",&key); 
 
    while(x->data!=key){ 
        y=x; 
        x=x->next; 
    } 
    y->next=x->next; 
    free(x); 
 
    x=first; 
    while(x!=NULL){ 
        printf("Element = %d \n",x->data); 
        x=x->next; 
} 
} 