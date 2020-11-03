#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void insbeg();
void insend();
void insmid();
void delbeg();
void delend();
void delmid();
void disp();

struct node
{
    int data;
    struct node *link;
};
struct node *header;

void main()
{
    header=(struct node*)malloc(sizeof(struct node));
    header->link = NULL;
    int c;
    char ch;
    do
    {
        printf("\nSINGLY LINKED LIST\n1. Insert from begining\n2. Insert in between\n3. Insert from end\n4. Delete from begining\n5. Delete in between\n6. Delete from end\n7. Display\n8. Exit");    
        printf("\nEnter your choice : ");
        scanf("%d",&c);
        if(c==1)
           insbeg();

        else if(c==2)
           insmid();
           
        else if(c==3)
           insend();
           
        else if(c==4)
           delbeg();
           
        else if(c==5)
           delmid();
           
        else if(c==6)
           delend();
           
        else if(c==7)
           disp();
           
        else if(c==8)
           break;
           
        else
           printf("Invalid input");
           
        printf("\nDo you want to continue (y/n) : ");
        scanf("%s",&ch);
    }
    while(ch=='Y'||ch=='y');
}

void insbeg()
{
    int x;
    struct node *new;
    new=(struct node*)malloc(sizeof(struct node));
    if (new == NULL)
        printf("Memory not available");
    
    else
    {
        printf("Enter data : ");
        scanf("%d",&x);
        new->link=header->link;
        new->data=x;
        header->link=new;
    }
}

void insend()
{
    int x;
    struct node *new,*ptr;
    new=(struct node*)malloc(sizeof(struct node));
    if (new==NULL)
        printf("Memory not available");
        
    else
    {
        printf("Enter data : ");
        scanf("%d",&x);
        ptr=header;
        while(ptr->link!=NULL)
        {
            ptr=ptr->link;
        }
        ptr->link=new;
        new->data=x;
    }
}

void insmid()
{
    int x,pos;
    struct node *new,*ptr;
     new=(struct node*)malloc(sizeof(struct node));
     if (new==NULL)
        printf("Memory not available");
        
    else
    {
        printf("Enter the position to be inserted : ");
        scanf("%d",&pos);
        printf("Enter data : ");
        scanf("%d",&x);
        ptr=header;
        while((ptr->data!=pos) && (ptr->link!=NULL))
        {
            ptr=ptr->link;
        }
        
        if(ptr->link==NULL)
           printf("Position not found");
           
        else
        {
            new->link=ptr->link;
            new->data=x;
            ptr->link=new;
        }
    }
}

void delbeg()
{
    struct node *new,*ptr,*ptr1;
    ptr=header->link;
    if (ptr==NULL)
       printf("List is empty");
       
    else
    {
        ptr1=ptr->link;
        header->link=ptr1;
        printf("Deleted element : %d",ptr->data);
    }
}

void delend()
{
    struct node *new,*ptr,*ptr1;
    ptr=header;
    if (ptr->link==NULL)
        printf("List is empty");
        
    else
    {
        while(ptr->link!=NULL)
        {
            ptr1=ptr;
            ptr=ptr->link;
        }
        ptr1->link=NULL;
        printf("Deleted element : %d",ptr->data);
    }
}

void delmid()
{
    int x,pos;
    struct node *new,*ptr,*ptr1;
    if (new==NULL)
        printf("List is empty");
        
    else
    {
        printf("Enter the position to be deleted : ");
        scanf("%d",&pos);
        ptr=header;
        ptr=ptr1->link;
        while(ptr!=NULL)
        {
            if(ptr->data!=pos)
            {
                ptr1=ptr;
                ptr=ptr->link;
            }
            
            else
            {
                ptr1->link=ptr->link;
                printf("Deleted element : %d",ptr->data);
            }
        }
        if(ptr==NULL)
           printf("Position not found");
    }
}

void disp()
{
    struct node *ptr;
    if(header->link==NULL)
    {
        printf("List is empty");
    }
    else
    {
        ptr=header->link;
        printf("Elements in Linked list :\n");
        while(ptr!=NULL)
        {
            printf("%d->",ptr->data);
            ptr=ptr->link;
        }
    }
}