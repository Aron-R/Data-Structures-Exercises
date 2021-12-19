//
//  main.c
//  FAT-1
//
//  Created by Aaron R on 09/12/21.
//  Given a word, form a Double linked list (DLL) by taking each letter from the word sequentially (from left to right). Now check if this word is palindrome or not using the DLL. If it is a palindrome, push the matching characters together one by one in to a stack. For example, for the word ‘liril’ being a palindrome, the stack will contain ‘lliir.’ Now pop all the elements from the stack and print those elements as a new word. In the given example, the new word from the stack is ‘riill’.

//Input format: In the first line, enter the word.
//
//Output format:
//
//In the first line, print if the word is ‘Palindrome’ or ‘Not a Palindrome’
//
//In the second line, If Palindrome then print the new word from the stack NB: In the output, it is not necessary to print the new word if it is not a palindrome.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
struct node
{
    char data;
    struct node *next;
    struct node *prev;
};

void display(struct node * head)
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
            printf("%c\n",temp->data);
            temp = temp->next;
        }
        // printing the last node's data
        printf("%c\n",temp->data);
    }
}

void push(struct node ** head, struct node ** tail, char data)
{
    // #### To insert a node at the head ####
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
//    printf("Enter data of new node: ");
//    scanf("%d",&new->data);
    new->data = data;
    new->next = NULL;
    new->prev = NULL;
    if (*head==NULL)
    {
        // If there are no nodes in the doubly linked list
        *head = new;
        *tail = new;
    }
    else
    {
        // If there are nodes in the doubly linked list
        // Update the previous pointer of the head node from NULL to the new node
        (*head)->prev = new;
        
        // Update the next pointer of the new node to the previous head node
        new->next = *head;
        
        // Update the head pointer to the new node
        *head = new;
    }
    
}

void peek(struct node * head)
{
    if (head == NULL)
        printf("The stack is empty");
    
    else
        printf("Top element: %d\n",head->data);
    
}

char pop(struct node ** head, struct node ** tail)
{
    // #### To delete a node whose position is the head ####
    
    struct node * temp;
    temp = *head;
    char c;
    c = (*head)->data;
    if (*head == *tail)
    {
        
        *head = *tail = NULL;
    }
    else
    {
        // Updating head to the next element
        *head = (*head)->next;
        
        // Updating the prev pointer of head is NULL
        (*head)->prev = NULL;
        free(temp);
    }
    return c;
    
}

bool empty(struct node * head)
{
    // #### Function to check if queue is empty ####
    
    if (head == NULL)
        return true;
    else
        return false;
    
}


void insert_head(struct node ** head, struct node ** tail, char data)
{
    // #### To insert a node at the head ####
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
//    printf("Enter data of new node: ");
//    scanf("%d",&new->data);
    new->data = data;
    new->next = NULL;
    new->prev = NULL;
    if (head==NULL)
    {
        // If there are no nodes in the doubly linked list
        *head = new;
        *tail = new;
    }
    else
    {
        // If there are nodes in the doubly linked list
        // Update the previous pointer of the head node from NULL to the new node
        (*head)->prev = new;
        
        // Update the next pointer of the new node to the previous head node
        new->next = *head;
        
        // Update the head pointer to the new node
        *head = new;
    }
}

void insert_end(struct node ** head, struct node ** tail, char data)
{
    // #### To insert a node at the tail ####
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
//    printf("Enter data of new node: ");
//    scanf("%d",&new->data);
    new->data = data;
    new->next = NULL;
    new->prev = NULL;
    if (*head==NULL)
    {
        // If there are no nodes in the doubly linked list
        *head = new;
        *tail = new;
    }
    else
    {
        // If there are nodes in the doubly linked list
        // Update the next pointer of the tail node from NULL to the new node
        (*tail)->next = new;
        
        // Update the previous pointer of the new node to the previous tail node
        new->prev = *tail;
        
        // Update the tail pointer to the new node
        *tail = new;
    }
}

void reverse_list(struct node ** head, struct node ** tail)
{
    // #### To reverse a doubly linked list ####
    
    struct node *current_node, *next_node;
    current_node = *head;
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
    current_node = *head;
    *head = *tail;
    *tail = current_node;
}

int main(int argc, const char * argv[])
{
    char str[20];
    printf("Enter string: ");
    scanf("%s",str);
    struct node* head = NULL;
    struct node* tail = NULL;
    struct node* head2 = NULL;
    struct node* tail2 = NULL;
    
    // Copying string into doubly linked list
    for (int i = 0 ; i < strlen(str) ; i++)
    {
        insert_end(&head,&tail,str[i]);
    }
    
    // Copying string into another doubly linked list
    for (int i = 0 ; i < strlen(str) ; i++)
    {
        insert_end(&head2,&tail2,str[i]);
    }
    
    // Reversing one of the doubly linked list
    reverse_list(&head2, &tail2);
    
    struct node * temp1 = head;
    struct node * temp2 = head2;
    
    
    // Checking to see if it's a palindrome by checking to see if the two elements of the list are same
    bool palindrome=true;
    for (int i=0; i<strlen(str); i++)
    {
        if (head->data!=head2->data)
        {
            printf("Not a palindrome\n");
            palindrome=false;
            break;
        }
    }
    
    // If they are, push similar elements into stack
    if(palindrome)
    {
        printf("Palindrome\n");
        struct node * stack_head=NULL;
        struct node * stack_tail=NULL;
        for (int i=0,j=(int)strlen(str)-1; i<(int)strlen(str); i++,j--)
        {
            if (i == j)
            {
                push(&stack_head, &stack_tail, temp1->data);
                break;
            }
            else
            {
                push(&stack_head, &stack_tail, temp1->data);
                push(&stack_head, &stack_tail, temp2->data);
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
        
        // Emptying stack
        while (!(empty(stack_head)))
        {
            printf("%c ",pop(&stack_head, &stack_tail));
        }
        printf("\n");
    }
    
    
    
}

