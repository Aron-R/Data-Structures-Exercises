//
//  main.c
//  Lab-3-1
//
//  Created by Aaron R on 27/08/21.
//  Reverse a doubly linked list and print the elements

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

void insert_head(void)
{
    // #### To insert a node at the head ####
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    printf("Enter data of new node: ");
    scanf("%d",&new->data);
    new->next = NULL;
    new->prev = NULL;
    if (head==NULL)
    {
        // If there are no nodes in the doubly linked list
        head = new;
        tail = new;
    }
    else
    {
        // If there are nodes in the doubly linked list
        // Update the previous pointer of the head node from NULL to the new node
        head->prev = new;
        
        // Update the next pointer of the new node to the previous head node
        new->next = head;
        
        // Update the head pointer to the new node
        head = new;
    }
    length+=1;
}

void insert_end(void)
{
    // #### To insert a node at the tail ####
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    printf("Enter data of new node: ");
    scanf("%d",&new->data);
    new->next = NULL;
    new->prev = NULL;
    if (head==NULL)
    {
        // If there are no nodes in the doubly linked list
        head = new;
        tail = new;
    }
    else
    {
        // If there are nodes in the doubly linked list
        // Update the next pointer of the tail node from NULL to the new node
        tail->next = new;
        
        // Update the previous pointer of the new node to the previous tail node
        new->prev = tail;
        
        // Update the tail pointer to the new node
        tail = new;
    }
    length+=1;
}

void insert_pos(int p)
{
    // #### To insert a node at the pth position ####
    struct node *new,*temp;
    new = (struct node *)malloc(sizeof(struct node));
    temp = head;
    printf("Enter data of new node: ");
    scanf("%d",&new->data);
    new->next = NULL;
    new->prev = NULL;
    int i=1;
    while (i<p-1)
    {
        temp = temp->next;
        i++;
    }
    // Updating the prev pointer to p-1th node
    new->prev = temp;
    
    // updating the next node to p1th node
    new->next = temp->next;
    
    // Updating the next pointer of p-1th node to the new node
    temp->next = new;
    
    // Updating the previous pointer of the pth node to the new node
    new->next->prev = new;

    length+=1;
}

void reverse_list(void)
{
    // #### To reverse a doubly linked list ####
    
    struct node *current_node, *next_node;
    current_node = head;
    while (current_node!=NULL)
    {
        // Storing the next node in next_node
        next_node = current_node->next;
        
        // Swapping the prev and next pointers of the current_node
        current_node->next = current_node->prev;
        current_node->prev = next_node;
        
        // Updating current_node to the next node
        current_node = next_node;
    }
    
    // Swapping head and tail pointers;
    current_node = head;
    head = tail;
    tail = current_node;
}

int main(int argc, const char * argv[])
{
    head = NULL;
    // Initialising doubly linked list
    initList();
    display();
    
    int more_nodes = 0;
    printf("Would you like to insert more nodes?\n1 - Yes\n");
    scanf("%d",&more_nodes);
    if (more_nodes==1)
    {
        while (more_nodes==1)
        {
            printf("####Positions####\n0 : beginning\n%d or -1 : end\nBetween 0 and %d : position p\nEnter the position to insert the new node: ",length,length);
            int p;
            scanf("%d",&p);
            if (p==0)
                insert_head();
            else if (p==-1 || p==length)
                insert_end();
            else if (p>1 && p<length)
                insert_pos(p);
            else
                printf("Invalid position");
            
            printf("Current elements of doubly linked lists: \n");
            display();
            
            printf("Would you like to insert another node?\n1 - Yes\n");
            scanf("%d",&more_nodes);
        }
    }
    
    printf("Reversed doubly linked list:\n");
    // Reversing the doubly linked list
    reverse_list();
    display();
    
    return 0;
}

