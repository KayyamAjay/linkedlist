INPUT: 1->2->3->4->5->NULL   k=2
OUTPUT 4->5->1->2->3->NULL
CODE:
#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
}; 
struct node* head=NULL;//pointing head to null
void append(int data)
{
    struct node *temp,*r;
    if(head==NULL) // for 1st element to insert
    {
        temp=(struct node*)malloc(sizeof(struct node));//creating temp node
        temp->data=data;
        temp->next=NULL;
        head=temp; // making head to point 1st node
    }
    else// from 2nd to n elements to append
    {
        r=(struct node*)malloc(sizeof(struct node));//creating r node;
        r->data=data;
        r->next=NULL;
        temp=head;//making temp to point 1st node
        while(temp->next!=NULL)//travesing till last node
        temp=temp->next;
        temp->next=r;//making connection between last node and newly created node
        
    }
}
void rotateclock(int k)
{
    struct node *t,*p;
    t=head;
    p=head;
    for(int i=0;i<k;i++)
    {
        t=head;
    p=head;
        while(t->next!=NULL)// travesing till last node 
        {
            t=t->next;
            
        }
        while(p->next->next!=NULL)//travesing till last before node
        {
            p=p->next;
        }
        p->next=NULL;//making last before node to NULL
        t->next=head;//making last node to point first node
        head=t;//making head to point t
        
    }
}
void display()
{
    struct node *t;
    t=head;
    while(t!=NULL)
    {
        printf("%d ",t->data);
        t=t->next;
    }
}
int main()
{
    
    int n,i,x,k;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        append(x);
    }
    scanf("%d",&k);
    rotateclock(k);
    display();

    return 0;
}
