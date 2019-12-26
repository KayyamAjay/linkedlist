INPUT 1 2 3 4 5
      k=12345
OUTPUT 24690
INPUT 9 8 1
      k=9
OUTPUT 990
CODE:
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
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
void add(int n,int k)//add function 
{
    struct node *temp;
    int sum=0,p=n-1;
    temp=head;
    while(temp!=NULL)
    {
        sum=temp->data*(pow(10,p))+sum;//adding likned list elements like 1*100+2*10+1*1=121
        p--;
        temp=temp->next;
    }
    sum=sum+k;
    printf("%d",sum);
    
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
    
    add(n,k);

    return 0;
}
