//
//  main.c
//  linked-list-reverse
//
//  Created by Aaron R on 03/09/21.
//

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

void insert_head(struct node ** head)
{
    struct node * current;
    // ##### Function to insert node at the head #####
    current = (struct node *) malloc(sizeof(struct node));
    
    // Input the node's data
    printf("Enter the data: ");
    scanf("%d",&(current)->data);
    
    // The address part of the new node points to the previous head
    (current)->link = *head;
    
    // The head variable is updated to the current one
    *head = current;
}

void insert_end(struct node ** head)
{
    // ##### Function to insert node at the end #####
    struct node * current;
    if (*head==NULL)
    {
        insert_head(head);
    }
    
    else
    {
        current = (struct node *) malloc(sizeof(struct node));
        // Input the node's data
        printf("Enter the data: ");
        scanf("%d",&(current)->data);
        
        // The link of the new node is NULL
        (current)->link = NULL;
        
        // A temporary node is created
        struct node * temp;
        temp = *head;
        
        // It is used to traverse to the end of the existing linked list
        while (temp->link!=NULL)
        {
            temp = temp->link;
        }
        
        // The link of the node at the end of the existing linked list is updated to the new node
        temp->link = current;
        
    }
}

void reverse(struct node ** head)
{
    struct node *prev_node, *current_node, *next_node;
    prev_node = NULL;
    current_node = next_node = *head;
    while (next_node!=NULL)
    {
        next_node = next_node->link;
        current_node->link = prev_node;
        prev_node = current_node;
        current_node = next_node;
    }
    
    *head = prev_node;
}


int main(int argc, const char * argv[])
{
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    struct node * head;
    head = NULL;
    
    for (int i=0; i<n; i++)
        insert_end(&head);
    display(head);
    reverse(&head);
    display(head);
    return 0;
}
