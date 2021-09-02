//
//  main.c
//  Lab-2-2
//
//  Created by Aaron R on 18/08/21.
//  Create a single linked list and delete a node at the beginning, end and any position in between.

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
        printf("The single linked list is empty\n");
    else
    // Else, display it's elements
        while ((temp)!=NULL)
        {
            printf("%d\n",(temp)->data);
            temp = (temp)->link;
        }
}

// ######## Functions to insert nodes ##########

void insert_head(struct node ** current, struct node ** head,int * count)
{
    // ##### Function to insert node at the head #####
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
    // ##### Function to insert node at the end #####
    
    if (*head==NULL)
    {
        insert_head(current,head,count);
    }
    
    else
    {
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
}

void insert_position(struct node ** current, struct node ** head,int * count,int p)
{
    // ##### Function to insert node at the head #####
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

// ######## Functions to delete nodes ##########
void delete_head(struct node **head, int * count)
{
    // #### Function to delete the node at the beginning ####
    struct node * temp;
    temp=*head;
    // The address of the head is updated to the next node
    *head = (*head)->link;
    
    // free the memory of the previous tail
    free(temp);
    *count-=1;
}

void delete_end(struct node **head,int * count)
{
    // #####  If there is only one node, delete head #####
    if ((*head)->link==NULL)
        delete_head(head, count);
    
    // if there is more than one node
    else
    {
    struct node * temp;
    struct node * prev_temp;
    temp = *head;
    prev_temp=NULL;
    // Traverse through the single linked list and store the last node in temp
    // and the node preceeding it in prev_temp
    while (temp->link!=NULL)
    {
        prev_temp = temp;
        temp = temp->link;
    }
        
    // Update the link of the node preceeding the previous tail to NULL
    prev_temp->link = NULL;
    
    // Free the memory of the previous tail
    free(temp);
    *count-=1;
    }
}
void delete_pos(struct node **head, int p,int * count)
{
    // ##### Function to delete node at pth position #####
    
    struct node * temp;
    struct node * next_temp;
    temp = *head;
    
    // Traverse till the p-1th element and store it in temp
    int i=1;
    while (i<p-1)
    {
        temp = temp->link;
        i+=1;
    }
    // The pth node is stored in next_temp
    next_temp = temp->link;
    
    // The link of the p-1th node is updated to the p+1th node
    temp->link = next_temp->link;
    
    // free the memory of the previous tail
    free(next_temp);
    *count-=1;
    
}

int main(int argc, const char * argv[])
{
    // Initialising the linked list
    printf("Initialising a single linked list...\n");
    struct node *head, *current;
    int count=0;
    head = NULL;
    current = NULL;
    
    // Displaying the initial elements of the linked list
    printf("Elements of the single linked list:\n");
    display(head);
    
    int c=1;
    while (c==1)
    {
        int p;
        printf("\n~##### Insertion of data into single linked list #####~\n");
        printf("\n1) 0 to insert a new node at the head\n2) %d or -1 to insert a new node at the end\nThere are currently %d nodes in the linked list\nEnter the position: ",count,count);
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
    
    c=1;
    while (c==1)
    {
        if (head==NULL)
        {
            printf("The linked list is empty. There are no more nodes to delete.\n");
            break;
        }
        else
        {
            int p;
            printf("\n~##### Deletion of data in linked list #####~\n");
            printf("\n1) 0 to delete a new node at the head\n2) %d or -1 to delete a new node at the end\nThere are currently %d nodes in the linked list\nEnter the position in which to delete the new node: ",count,count);
            scanf("%d",&p);
            if (p==0)
                delete_head(&head,&count);
            
            else if ((p==count)||(p==-1))
                delete_end(&head,&count);
            
            else if((p>=0)&&(p<=count))
                delete_pos(&head, p,&count);
            
            else
                printf("Invalid position\n");
            
            printf("Elements of the circular linked list:\n");
            display(head);
            printf("To delete another node, press 1: ");
            scanf("%d",&c);
            
        }

    }
    
    printf("\n---##############################---\n            ~End.\n\n");
    return 0;
}
