//
//  main.c
//  Lab-4-2
//
//  Created by Aaron R on 03/09/21.
//  Stacks using linked lists

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * link;
};
struct node * top;

void display (void)
{
    // Function to display the data in the linked list
    struct node * temp;
    temp = top;
    // If head is NULL, the linked list is empty
    if (temp==NULL)
        printf("The stack is empty\n");
    else
    // Else, display it's elements
        while ((temp)!=NULL)
        {
            printf("%d\n",(temp)->data);
            temp = (temp)->link;
        }
}

void push(void)
{
    // ##### Function to insert node at the head #####
    struct node * current;
    current = (struct node *) malloc(sizeof(struct node));
    
    // Input the node's data
    printf("Enter the data: ");
    scanf("%d",&current->data);
    
    // The address part of the new node points to the previous head
    current->link = top;
    
    // The head variable is updated to the current one
    top = current;
    
}
void peek(void)
{
    if (top == NULL)
        printf("The stack is empty");
    
    else
        printf("Top element: %d\n",top->data);
    
}
void pop(void)
{
    // #### Function to delete the node at the beginning ####
    struct node * temp;
    if (top==NULL)
    {
        printf("The stack is empty. No elements to pop.\n");
    }
    else
    {
        temp=top;
        printf("Popped element: %d\n",top->data);
        // The address of the head is updated to the next node
        top = top->link;
        
        // free the memory of the previous head
        free(temp);
    }
    
}

int main(int argc, const char * argv[])
{
    push();
    display();
    peek();
    pop();
    display();
    
    return 0;
}
