//Insertion at any Position
 
#include<stdio.h> 
#include<stdlib.h> 
struct node{ 
    int data; 
    struct node * next; 
}; 
 
void main() { 
    struct node *s,*p,*q,*first; 
    char ch; 
    int key; 
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
 
    // Insert a node after key 
    printf("Enter key to insert after it :\n"); 
    scanf("%d",&key); 
    
    while(s->data!=key){ 
        s=s->next; 
    } 
 
    if(s->data ==key){ 
        struct node * a,*b; 
        a=(struct node *)malloc(sizeof(struct node)); 
        printf("Enter node data to insert after %d :\n",key); 
        scanf("%d",&a->data); 
        b=s->next; 
        s->next=a; 
        a->next=b; 
        s=first; 
    }else{ 
        printf("data not found"); 
    } 
 
    while(s!=NULL){ 
        printf("Element = %d \n",s->data); 
        s=s->next;} 
} 