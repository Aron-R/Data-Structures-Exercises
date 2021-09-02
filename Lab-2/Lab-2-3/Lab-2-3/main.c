//
//  main.c
//  Lab-2-3
//
//  Created by Aaron R on 18/08/21.
//  Create a circular single linked list and insert a node at the beginning, end and any position in between

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
    temp = tail->link;
    if (tail==NULL)
    {
        printf("The circular linked list is empty");
    }
    else
    {
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
    int i=0;
    
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
int main(int argc, const char * argv[])
{

    int count=0;
    int c=1;
    while (c==1)
    {
        int p;
        printf("\n~##### Insertion of data into circular linked list #####~\n");
        printf("\n1) 0 to insert a new node at the head\n2) %d or -1 to insert a new node at the end\nThere are currently %d nodes in the linked list\nEnter the position in which to insert the new node: ",count,count);
        scanf("%d",&p);
        if (p==0)
        {
            insert_head(&count);
        }
        else if (p==count||p==-1)
        {
            insert_end(&count);
        }
        else if((p>=0)&&(p<=count))
        {
            insert_pos(&count,p);
        }
        else
            printf("Invalid position\n");
        
        printf("Elements of the circular linked list:\n");
        display();
        
        printf("To insert another node, press 1: ");
        scanf("%d",&c);
    }
    printf("\n---##############################---\n            ~End.\n\n");
    return 0;
}
