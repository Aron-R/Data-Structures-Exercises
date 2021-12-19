//
//  main.c
//  pat-1-1
//
//  Created by Aaron R on 3/9/21.
//  You are asked to collect attendance (create and maintain a linked list) during an online class. Students are expected to respond with their roll numbers. However, to make sure, students may record their response multiple times and you may have duplicate entries. Write a program to find and remove duplicate values from the student’s attendance list.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * link;
};
int n;
void display (struct node * temp)
{
    // Function to display the data in the linked list
    
    // If head is NULL, the linked list is empty
    if (temp==NULL)
        printf("The single linked list is empty\n");
    else
    // Else, display it's elements
        while ((temp)!=NULL)
        {
            printf("%d ",(temp)->data);
            temp = (temp)->link;
        }
}

// #### Functions to insert nodes ####

void insert_head(struct node ** head)
{
    struct node * current;
    // ##### Function to insert node at the head #####
    current = (struct node *) malloc(sizeof(struct node));
    
    // Input the node's data
    scanf("%d",&(current)->data);
    
    // The address part of the new node points to the previous head
    (current)->link = *head;
    
    // The head variable is updated to the current one
    *head = current;
    
}

void insert_end(struct node ** head)
{
    struct node * current;
    // ##### Function to insert node at the end #####
    
    if (*head==NULL)
    {
        insert_head(head);
    }
    
    else
    {
        current = (struct node *) malloc(sizeof(struct node));
        // Input the node's data
        scanf("%d",&(current)->data);
        if (current->data==NULL)
            return;
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

// #### Functions to delete Nodes ####
void delete_head(struct node **head)
{
    // #### Function to delete the node at the beginning ####
    struct node * temp;
    temp=*head;
    // The address of the head is updated to the next node
    *head = (*head)->link;
    
    // free the memory of the previous head
    free(temp);
    n--;
}

void delete_end(struct node **head)
{
    // #####  If there is only one node, delete head #####
    if ((*head)->link==NULL)
        delete_head(head);
    
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
    }
    n--;
}


void delete_pos(struct node **head, int p)
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
    n--;
}
void sortList(struct node ** head)
{
    struct node *current;
    current=*head;
    struct node *next;
    next=NULL;
    int temp;

    if(*head==NULL)
        return;
    
    else
    {
        while(current!=NULL)
        {
            next=current->link;
            while(next!=NULL)
            {
                if(current->data>next->data)
                {
                    temp=current->data;
                    current->data=next->data;
                    next->data=temp;
                }

                next=next->link;
            }

            current=current->link;
        }
    }
}

void remove_duplicates(struct node **head)
{
    struct node *temp, *next, *current;
    current = *head;
    if (current == NULL)
        return;
    else
    {
        while(current!=NULL)
        {
            next = current->link;
            temp = current;
            while(next!=NULL)
            {
                if(current->data==next->data)
                {
                    temp->link = next->link;
                }
                else
                {
                    temp = next;
                }
                next = next->link;
            }
            current=current->link;
        }
    }
}

int main()
{
    
    scanf("%d",&n);
    struct node * head;
    head = NULL;

    // Insert nodes
    for(int i=0;i<n;i++)
        insert_end(&head);

    // Sort
    sortList(&head);

    // Remove duplicates
    remove_duplicates(&head);

    // Display linked list
    display(head);
    
    return 0;
}
