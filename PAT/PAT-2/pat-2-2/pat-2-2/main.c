//
//  main.c
//  pat-2-2
//
//  Created by Aaron R on 19/11/21.
//


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node * left;
    struct node * right;
};
struct node * root;

struct QueueNode
{
    struct node * data;
    struct QueueNode * link;
};

void enqueue(struct node * x,struct QueueNode ** tail)
{
    // #### Function to insert node at the end ####
    struct QueueNode * current;
    current = (struct QueueNode *) malloc(sizeof(struct QueueNode));
    
    // Inputting data to the node
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

void dequeue(struct QueueNode ** tail)
{
    // #### Function to delete a node at the beginning ####
    
    struct QueueNode * temp;
    // Initialise the temp variable with the head of the circular linked list
    temp = (*tail)->link;
    
    // If the tail is empty, display that the circular linked list is empty
    if ((*tail)==0)
        printf("The circular linked list is empty");
    
    // If the tail has only one node, delete the node
    else if ((*tail)->link==(*tail))
        *tail = NULL;
    
    
    // If the tail has more than one node,
    // update the link of the tail node to the 2nd node of circular linked list
    else
    {
        (*tail)->link = temp->link;
    }
    
}

bool empty(struct QueueNode * tail)
{
    // #### Function that returns if the queue is empty or not ####
    if (tail==NULL)
        return true;
    else
        return false;
}

struct node * peek(struct QueueNode * tail)
{
    // #### Function that returns the first element in queue
    if (tail==NULL)
        return NULL;
    else
        return tail->link->data;
}



void initialise(struct node ** root)
{
    // #### Function to add node to BST while traversing in BFS ####
    if (*root==NULL)
    {
        *root=(struct node *)malloc(sizeof(struct node));
        int input;
        // Input the data
        printf("Enter data of root: ");
        scanf("%d",&input);
        (*root)->data = input;
        (*root)->left=NULL;
        (*root)->right=NULL;
        return;
    }
    
    struct QueueNode * tail;
    tail = NULL;
    enqueue(*root, &tail);
    while (!(empty(tail)))
    {
        struct node * current = peek(tail);
        struct node * temp;
        temp = (struct node *) malloc(sizeof(struct node));
        dequeue(&tail);
        
        // If left node of current node is empty
        if (current->left==NULL)
        {
            int input;
            // Make left node
            printf("Enter data to the left of %d: ",current->data);
            scanf("%d",&input);
            temp->data = input;
            temp->left = NULL;
            temp->right=NULL;
            
            // Link left node
            current->left = temp;
            return;
        }
        // If right node of current node is empty
        else if (current->right==NULL)
        {
            int input;
            // Make right node
            printf("Enter data to the right of %d: ",current->data);
            scanf("%d",&input);
            temp->data = input;
            temp->left = NULL;
            temp->right=NULL;
            
            // Link right nodes
            current->right = temp;
            return;
        }
        
        else
        {
            // If both left or right nodes of current node is not empty, move to child nodes
            enqueue(current->left, &tail);
            enqueue(current->right, &tail);
        }
        
    }
    
}

int evenSum=0;
int oddSum=0;
void oddEven(struct node * r)
{
    // #### Function to traverse tree in inorder and find sum of odd and even elements ####
    
    if(r==NULL)
        return;
    oddEven(r->left);
    if(r->data%2==0)
        evenSum+=r->data;
    else
        oddSum+=r->data;
    
    oddEven(r->right);
}

int total=0;
void internal_nodes(struct node ** r)
{
    // #### Function to find internal nodes of the tree and their sum ####
    struct QueueNode * q;
    q = NULL;
    enqueue(root, &q);
    while (!empty(q))
    {
        struct node * current = peek(q);
        dequeue(&q);
        
        int condition=0;
        if(current->left)
        {
            condition=1;
            
            enqueue(current->left, &q);
        }
        if(current->right )
        {
            condition=1;
            
            enqueue(current->right, &q);
        }
        if(condition==1 && (current)!=root)
        {
            total+=current->data;
            printf("total: %d\ndata: %d",total,(*r)->data);
        }
        
    }
}


int main(int argc, const char * argv[])
{
    
    root = NULL;
    
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    for (int i=0; i<n; i++)
    {
        initialise(&root);
    }
    
    oddEven(root);
    internal_nodes(&root);
    printf("%d\n",oddSum);
    printf("%d\n",evenSum);
    printf("%d\n",total);
    
    return 0;
}

