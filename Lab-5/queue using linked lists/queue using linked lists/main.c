//
//  main.c
//  queue using linked lists
//
//  Created by Aaron R on 22/10/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node
{
    int data;
    struct node * link;
};
void enqueue(int x,struct node ** tail)
{
    // #### Function to insert node at the end ####
    struct node * current;
    current = (struct node *) malloc(sizeof(struct node));
    // Inputting data to the node
//    printf("Enter the data: ");
//    scanf("%d",&current->data);
    current->data = x;
    current->link = NULL;
    
    // If the circular linked list is empty, assign the new node as the tail
    if (*tail==NULL)
    {
        *tail = current;
        (*tail)->link = current;
    }
    
    // If the circular linked list isn't empty
    else
    {
        // The new node's link is assigned the address of the head
        current->link = (*tail)->link;
        
        // The previous tail's link is assigned the address of the new node
        (*tail)->link = current;
        
        // The tail variable is updated to the new node
        *tail = current;
    }
}

void display(struct node * tail)
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

void dequeue(struct node * tail)
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
    
}

bool empty(struct node * tail)
{
    // #### Function that returns if the queue is empty or not ####
    if (tail==NULL)
        return true;
    else
        return false;
}

void peek(struct node * tail)
{
    if ((tail==NULL)&&(tail->link==NULL))
        printf("Queue is empty");
    else
        printf("%d\n",tail->link->data);
}



int main(int argc, const char * argv[])
{
    struct node * tail;
    tail = NULL;
    for (int i=0; i<5; i++)
    {
        int temp;
        printf("Enter data of node %d: ",i+1);
        scanf("%d",&temp);
        enqueue(temp, &tail);
    }
    display(tail);
    
    printf("Dequeing..\n");
    dequeue(tail);
    display(tail);
    
    printf("Peek: ");
    peek(tail);
    return 0;
}
