//
//  main.c
//  Lab-3-3
//
//  Created by Aaron R on 27/08/21.
//  Devise a program to create a list of integers dynamically .Write functions (i) Find
//  he maximum and minimum from the list. (iii) Display the contents of the list.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * link;
};

void display (struct node *temp)
{
    // Function to display the data in the linked list
    
    // If head is NULL, the linked list is empty
    if (temp==NULL)
        printf("The linked list is empty\n");
    else
    // Else, display it's elements
        while ((temp)!=NULL)
        {
            printf("%d\n",(temp)->data);
            temp = (temp)->link;
        }
}

void insert_head(struct node ** current, struct node ** head,int * count)
{
    // Function to insert node at the head
    *current = (struct node *) malloc(sizeof(struct node));
    
    // Input the node's data
    printf("Enter the data: ");
    scanf("%d",&(*current)->data);
    
    // The address part of the new node points to the previous head
    (*current)->link = *head;
    
    // The head variable is updated to the current one
    *head = *current;
    
    *count+=1;
}

void insert_end(struct node ** current, struct node ** head,int * count)
{
    // Function to insert node at the end
    *current = (struct node *) malloc(sizeof(struct node));
    // Input the node's data
    printf("Enter the data: ");
    scanf("%d",&(*current)->data);
    
    // The link of the new node is NULL
    (*current)->link = NULL;
    
    // A temporary node is created
    struct node * temp;
    temp = *head;
    
    // It is used to traverse to the end of the existing linked list
    while (temp->link!=NULL)
    {
        temp = temp->link;
    }
    
    // The link of the node at the end of the existing linked list is updated to the new node
    temp->link = *current;
    
    *count+=1;
}

void insert_position(struct node ** current, struct node ** head,int * count,int p)
{
    // Function to insert node at the head
    *current = (struct node *) malloc(sizeof(struct node));
    
    // Input the node's data
    printf("Enter the data: ");
    scanf("%d",&(*current)->data);
    
    // A temporary node is created
    struct node * temp;
    
    // The temporary node is used to traverse and get to the pth position
    temp = *head;
    int i=1;
    while (i<p)
    {
        temp = temp->link;
        i+=1;
    }
    
    // The link of the new node is updated to the link of the node at (p+1)th position
    (*current)->link = temp->link;
    
    // The link of the node at the pth position is updated to the new node
    temp->link = (*current);
    
    *count+=1;
}

void MinMax (struct node *temp)
{
    // Function to display the min and max in the linked list
    
    int min = temp->data;
    int max = temp->data;
    
    // If head is NULL, the linked list is empty
    if (temp==NULL)
        printf("The linked list is empty\n");
    else
    // Else, compute and display it's min and max
    {
        while ((temp)!=NULL)
        {
            if (temp->data>max)
                max = temp->data;
            if (temp->data<min)
                min = temp->data;
            
            temp = (temp)->link;
        }
        printf("\nMin element: %d\nMax element: %d\n",min,max);
    }
}


int main(int argc, const char * argv[])
{
    // Initialising the linked list
    printf("Initialising a linked list...\n");
    struct node *head, *current;
    int count=0;
    head = NULL;
    current = NULL;
    
    // Displaying the initial elements of the linked list
    printf("Elements of the linked list:\n");
    display(head);
    
    int c=1;
    while (c==1)
    {
        int p;
        printf("\n~##### Insertion of data into linked list #####~\n");
        printf("1) 0 to insert a new node at the head\n2) %d or -1 to insert a new node at the end\nThere are currently %d nodes in the linked list\nEnter the position: ",count,count);
        scanf("%d",&p);
        
        if (p==0)
            insert_head(&current,&head,&count);
        
        else if (p==count||p==-1)
            insert_end(&current,&head,&count);
        
        else if((p>=0)&&(p<=count))
            insert_position(&current, &head, &count,p);
        
        else
            printf("Invalid position\n");
        
        printf("Elements of the linked list:\n");
        display(head);
        
        printf("To insert another node, press 1: ");
        scanf("%d",&c);

    }
    printf("\n---##############################---\n            ~End.\n\n");
    printf("Final linked list:\n");
    display(head);
    MinMax(head);
    return 0;
}

