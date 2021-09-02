//
//  main.c
//  Lab-2-4
//
//  Created by Aaron R on 19/08/21.
//  Create a circular single linked list
//  and delete a node at the beginning, end and any position in between.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * link;
}*tail;

void display(void)
{
    // #### To display the elements of the circular linked list ####
    struct node * temp;
    
    if (tail==NULL)
    {
        printf("The circular linked list is empty\n");
    }
    else
    {
        temp = tail->link;
        // traversing from the first node
        while (temp->link!=tail->link)
        {
            printf("%d\n",temp->data);
            temp = temp->link;
        }
        // printing the last node's data
        printf("%d\n",temp->data);
    }
}

// ########## Functions to insert nodes ##########
void insert_head(int * count)
{
    // #### Function to insert node at the head ####
    struct node * current;
    current = (struct node *) malloc(sizeof(struct node));
    // Inputting data to the node
    printf("Enter data: ");
    scanf("%d",&current->data);
    current->link=NULL;
    
    // If the circular linked list is empty, assign the new node as the tail
    if (tail == NULL)
    {
        tail = current;
        tail->link = current;
    }
    // If the circular linked list isn't empty
    else
    {
        // The new node is linked to the head
        current->link = tail->link;
        
        // The tail is linked to the new node
        tail->link = current;
    }
    
    *count +=1;
}

void insert_end(int * count)
{
    // #### Function to insert node at the end ####
    struct node * current;
    current = (struct node *) malloc(sizeof(struct node));
    // Inputting data to the node
    printf("Enter the data: ");
    scanf("%d",&current->data);
    current->link = NULL;
    
    // If the circular linked list is empty, assign the new node as the tail
    if (tail==NULL)
    {
        tail = current;
        tail->link = current;
    }
    
    // If the circular linked list isn't empty
    else
    {
        // The new node's link is assigned the address of the head
        current->link = tail->link;
        
        // The previous tail's link is assigned the address of the new node
        tail->link = current;
        
        // The tail variable is updated to the new node
        tail = current;
    }
    *count+=1;

}

void insert_pos(int * count, int p)
{
    // #### Function to insert node in position p ####
    struct node * current;
    struct node * temp;
    current = (struct node *) malloc(sizeof(struct node));
    
    // Inputting data to the node
    printf("Enter data: ");
    scanf("%d",&current->data);
    current->link=NULL;
    
    // The temp variable is assigned the address of the head
    temp = tail->link;
    int i=1;
    
    // The temp variable traverses untill it reaches the p-1th position
    while (i<p-1)
    {
        temp = temp->link;
        i+=1;
    }
    // The new node's link is given the address of the p+1th element
    current->link = temp->link;
    
    // The p-1th element's link is given to be the address of the new node
    temp->link = current;
    
    *count+=1;
}

// ########## Functions to delete nodes ##########
void delete_head(int * count)
{
    // #### Function to delete a node at the beginning ####
    
    struct node * temp;
    // Initialise the temp variable with the head of the circular linked list
    temp = tail->link;
    
    // If the tail is empty, display that the circular linked list is empty
    if (tail==0)
        printf("The circular linked list is empty");
    
    // If the tail has only one node, delete the node
    else if (tail->link==tail)
        tail = NULL;
    
    
    // If the tail has more than one node,
    // update the link of the tail node to the 2nd node of circular linked list
    else
    {
        tail->link = temp->link;
    }
    
    *count-=1;

}

void delete_end(int * count)
{
    // #### Function to delete a node at the end ####
    
    struct node * current;
    struct node * prev;
    prev=NULL;
    // Initialise the current variable with the head of the circular linked list
    current = tail->link;
    
    // If the tail is empty, display that the circular linked list is empty
    if (tail==NULL)
        printf("The circular linked list is empty\n");
    
    // If the tail has only one node, delete the node
    else if (tail->link==tail)
        tail = NULL;
    
    // If the tail has more than one node,
    else
    {
        // Traverse the list using the current variable till the tail is reached
        while (current->link!=tail->link)
        {
            // The element that preceeds the tail is stored in the variable prev
            prev = current;
            current = current->link;
        }
        // The link of the node preceeding the tail is updated to the address of the head
        prev->link = tail->link;
        
        // The tail variable is updated with the element that preceeded the previous tail
        tail = prev;
    }
    *count-=1;
    // free the memory of the node that was deleted
    free(current);
}

void delete_pos(int * count, int p)
{
    // #### Function to delete a node at the pth position ####

    struct node * current;
    current = tail->link;
    struct node * next_current;
    next_current = NULL;
    int i=1;
    
    // Traverse till the p-1th element is reached and stored in the current variable
    while (i<p-1)
    {
        current = current->link;
        i++;
    }
    // The pth element is stored in the next_current variable
    next_current = current->link;
    
    // The link of the p-1th element is updated to the address of the p+1th element
    current->link = next_current->link;
    
    // free the memory of the node that was deleted
    free(current);
    *count-=1;
}

int main(int argc, const char * argv[])
{

    int count=0;
    
    // ########## Menu to insert nodes ##########
    int c=1;
    while (c==1)
    {
        int p;
        printf("\n~##### Insertion of data into linked list #####~\n");
        printf("Enter the position from which to delete the node\n1) 0 to insert a new node at the head\n2) %d or -1 to insert a new node at the end\nThere are currently %d nodes in the linked list\nEnter the position to insert: ",count,count);
        scanf("%d",&p);
        if (p==0)
        {
            insert_head(&count);
        }
        else if (p==count||p==-1)
        {
            insert_end(&count);
        }
        else if((p>0)&&(p<count))
        {
            insert_pos(&count,p);
        }
        
        printf("Elements of the circular linked list:\n");
        display();
        
        printf("To insert another node, press 1: ");
        scanf("%d",&c);
    }
    
    // ########## Menu to delete nodes ##########
    c=1;
    while (c==1)
    {
        if (tail==NULL)
        {
            printf("There are no more nodes left to delete.\n\n");
            break;
        }
        
        else
        {
            int p;
            printf("\n~##### Deletion of data from circular linked list #####~\n");
            printf("Enter the position in which to insert the new node\n1) 0 to delete a new node at the head\n2) %d or -1 to delete a new node at the end\nThere are currently %d nodes in the linked list\nEnter the position to delete: ",count,count);
            scanf("%d",&p);
            if (p==0)
            {
                delete_head(&count);
            }
            else if (p==count||p==-1)
            {
                delete_end(&count);
            }
            else if((p>0)&&(p<count))
            {
                delete_pos(&count, p);
            }
            
            else
                printf("Invalid position\n");
            
            printf("Elements of the circular linked list:\n");
            display();
            
            printf("To delete another node, press 1: ");
            scanf("%d",&c);
        }
    }
    return 0;
}

