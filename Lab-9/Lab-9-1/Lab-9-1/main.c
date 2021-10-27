//
//  main.c
//  Lab-9-1
//
//  Created by Aaron R on 22/10/21.
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
    if (tail==NULL)
        return NULL;
    else
        return tail->link->data;
}


void preOrder(struct node * root)
{
    // #### Function to traverse tree in preorder ####
    if(root==NULL)
        return;
    printf("%d ",root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(struct node * root)
{
    // #### Function to traverse tree in inorder ####
    if(root==NULL)
        return;
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}

void postOrder(struct node * root)
{
    // #### Function to traverse tree in postorder ####
    if(root==NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ",root->data);
    
}

void breadthOrder(struct node * root)
{
    // #### Function to traverse tree in breadth order ####
    if (root==NULL)
    {
        return;
    }
    struct QueueNode * tail;
    tail = NULL;
    enqueue(root, &tail);
    while (!(empty(tail)))
    {
        struct node * current = peek(tail);
        printf("%d ",current->data);
        if (current->left!=NULL)
            enqueue(current->left, &tail);
        if (current->right!=NULL)
            enqueue(current->right, &tail);
        dequeue(&tail);
    }
    
}


//struct node * initialise(void)
//{
//    int input;
//    struct node* node;
//    node = (struct node *) malloc(sizeof(struct node));
//
//    // Input the data
//    printf("Enter data: ");
//    scanf("%d",&input);
//    if (input==-1)
//    {
//        return NULL;
//    }
//    node->data = input;
//
//    // Making left node
//    printf("Enter left child of %d\n",input);
//    node->left = initialise();
//
//    // Making right node
//    printf("Enter right child of %d\n",input);
//    node->right = initialise();
//    return  node;
//}

void initialise(struct node ** root)
{
    if (*root==NULL)
    {
        *root=(struct node *)malloc(sizeof(struct node));
        int input;
        // Input the data
//        printf("Enter data of root: ");
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
//            printf("Enter data to the left of %d: ",current->data);
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
//            printf("Enter data to the right of %d: ",current->data);
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

int main(int argc, const char * argv[])
{
    struct node * root;
    root = NULL;
    
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    for (int i=0; i<n; i++)
    {
        initialise(&root);
    }
    inOrder(root);
    printf("\n");
    preOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");
    breadthOrder(root);
    printf("\n");

    
    return 0;
}
