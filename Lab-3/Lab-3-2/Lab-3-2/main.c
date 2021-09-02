//
//  main.c
//  Lab-3-2
//
//  Created by Aaron R on 27/08/21.

//  Create a doubly linked list and
//  delete a node at the beginning, end and any position in between.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head, *tail;
int length=0;

void display(void)
{
    // #### To display the elements of the doubly linked list ####
    struct node * temp;
    temp = head;
    if (head==NULL)
    {
        printf("The doubly linked list is empty\n");
    }
    
    else
    {
        // traversing from the first node
        while (temp->next!=NULL)
        {
            printf("%d\n",temp->data);
            temp = temp->next;
        }
        // printing the last node's data
        printf("%d\n",temp->data);
    }
}
void initList(void)
{
    // #### To initialise a doubly linked list with n number of elements ####
    struct node *new;
    printf("Enter the number of nodes with which to initialise the doubly linked list: ");
    int n;
    scanf("%d",&n);
    length = n;
    for (int i=0; i<n; i++)
    {
        new = (struct node *)malloc(sizeof(struct node));
        printf("Enter data of node %d: ",i+1);
        scanf("%d",&new->data);
        new->next = NULL;
        new->prev = NULL;
        if (head == NULL)
        {
            // If there are no elements in the doubly linked list
            tail = new;
            head = tail;
        }
        else
        {
            // If there are nodes in the doubly linked list
            tail->next = new;
            new->prev = tail;
            tail = new;
        }
    }
}

void delete_head(void)
{
    // #### To delete a node whose position is the head ####
    
    struct node * temp;
    temp = head;
    if (head == tail)
    {
        head = tail = NULL;
        length-=1;
    }
    else
    {
        // Updating head to the next element
        head = head->next;
        
        // Updating the prev pointer of head is NULL
        head->prev = NULL;
        free(temp);
        length-=1;
    }
    
}

void delete_end(void)
{
    // #### To delete a node whose position is the tail ####
    struct node * temp;
    temp = tail;
    if (head == tail)
    {
        head = tail = NULL;
        length-=1;
    }

    else
    {
        // Updating the tail pointer to the previous element
        tail = tail->prev;
        
        // The new tail pointer's next pointer is updated to NULL
        tail->next = NULL;
        free(temp);
        length-=1;
    }
    
}

void delete_pos(int p)
{
    // #### To delete a node whose position is p ####
    
    struct node * temp;
    temp = head;
    int i=1;
    
    // Traversing to get to the pth node
    while (i<p)
    {
        temp = temp->next;
        i++;
    }
    // Updating the p-1th node's next poitner to p+1th node
    temp->prev->next = temp->next;
    
    // Updating the p+1th node's prev pointer to p-1th node
    temp->next->prev = temp->prev;
    free(temp);
    length-=1;
}

int main(int argc, const char * argv[])
{
    head = NULL;
    tail = NULL;
    // Initialising doubly linked list
    initList();
    display();
    
    int cond;
    printf("Would you like to delete nodes?\n1 - Yes\n");
    scanf("%d",&cond);
    while (cond==1)
    {
        if (length==0)
        {
            printf("There are no more nodes left to delete\n");
            break;
        }
        else
        {
            printf("#### Positions to delete ####\n1 - head\n-1 or %d - tail\nBetween 1 and %d - pth element\nEnter the position to delete: ",length,length);
            int p;
            scanf("%d",&p);
            if (p==1)
                delete_head();
            else if(p==-1 || p==length)
                delete_end();
            else if(p>1 && p<length)
                delete_pos(p);
            else
                printf("Invalid position\n");
            printf("Current elements in doubly linked list: \n");
            display();
            printf("Enter 1 to delete more nodes: ");
            scanf("%d",&cond);
        }
        
    }
    
    return 0;
}
