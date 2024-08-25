 //deletion at End 
 
 
#include<stdio.h> 
#include<stdlib.h> 
struct node{ 
    int data; 
    struct node * next; 
}; 
 
void main() { 
    struct node *s,*p,*q,*first; 
    char ch; 
    p=(struct node *)malloc(sizeof(struct node)); 
    printf("Enter first node data :\n"); 
    scanf("%d",&p->data); 
    s=p;              // s points to the first node 
    first =s ;       // first keeps track of the start of the list 
    do{ 
        q=(struct node *)malloc(sizeof(struct node)); 
        printf("Enter next node data :\n"); 
        scanf("%d",&q->data); 
        p->next=q; 
        p=q; 
        printf("press y for next node :\n"); 
        ch=getch(); 
    }while(ch=='y'|| ch=='Y'); 
    p->next=NULL; 
 
    while(s->next!=NULL){ 
        p=s; 
        s=s->next; 
    } 
    p->next=NULL; 
    free(s); 
 
    s=first; 
    while(s!=NULL){ 
        printf("Element = %d \n",s->data); 
        s=s->next;} 
} 