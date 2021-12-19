//
//  main.c
//  FAT-3
//
//  Created by Aaron R on 10/12/21.
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
        printf("The linked list is empty\n");
    else
    // Else, display it's elements
        while ((temp)!=NULL)
        {
            printf("%d\n",(temp)->data);
            temp = (temp)->link;
        }
}

void insert_head(struct node ** current, struct node ** head,int data)
{
    // Function to insert node at the head
    *current = (struct node *) malloc(sizeof(struct node));
    
    // Input the node's data
//    printf("Enter the data: ");
//    scanf("%d",&(*current)->data);
    (*current)->data = data;
    
    // The address part of the new node points to the previous head
    (*current)->link = *head;
    
    // The head variable is updated to the current one
    *head = *current;
    
}

void insert_end(struct node ** current, struct node ** head,int data)
{
    // Function to insert node at the end
    *current = (struct node *) malloc(sizeof(struct node));
    // Input the node's data
//    printf("Enter the data: ");
//    scanf("%d",&(*current)->data);
    (*current)->data = data;
    
    // The link of the new node is NULL
    (*current)->link = NULL;
    
    // A temporary node is created
    struct node * temp;
    temp = *head;
    
    // It is used to traverse to the end of the existing linked list
    while (temp->link!=NULL)
    {
        temp = temp->link;
    }
    
    // The link of the node at the end of the existing linked list is updated to the new node
    temp->link = *current;
    
}

void reverse(struct node ** head)
{
    // ## Function to reverse the linked list
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
    printf("Enter n: ");
    int n;
    scanf("%d",&n);
    struct node * head=NULL;
    struct node * current=NULL;
    for (int i=0; i<n; i++)
    {
        int data;
        printf("Enter data: ");
        scanf("%d",&data);
        if(head == NULL)
            insert_head(&current, &head, data);
        
        else
            insert_end(&current, &head, data);
        
        
    }
    
    struct node *temp1=NULL;
    struct node *temp2=NULL;
    
    // Find midpoint of linked list
    int mid;
    
    if(n%2==0)
        mid = n/2;
    else
        mid = (n+1)/2;
    
    struct node * temp3=head;
    
    // Split into two sub linked lists
    for (int i=0; i<mid; i++)
    {
        if(temp1==NULL)
            insert_head(&current, &temp1, temp3->data);
        else
            insert_end(&current, &temp1, temp3->data);
        temp3 = temp3->link;
    }
    
    for (int i=mid; i<n; i++)
    {
        if(temp2==NULL)
            insert_head(&current, &temp2, temp3->data);
        else
            insert_end(&current, &temp2, temp3->data);
        temp3 = temp3->link;
    }

    
    // Reverse the 2nd linked list
    reverse(&temp2);
    
    
    // Make Pointers to the sub linked lists
    temp3 = temp1;
    struct node * temp4 = temp2;
    
    // Inserting first node of the final linked list
    struct node * final=NULL;
    insert_head(&current, &final, temp3->data);
    temp3 = temp3->link;
    
    // Alternatively insert the other nodes into the final linked list
    int i=2;
    while (i<=n)
    {
        if(i%2==0)
        {
            insert_end(&current, &final, temp4->data);
            temp4 = temp4->link;
        }
        else
        {
            insert_end(&current, &final, temp3->data);
            temp3 = temp3->link;
        }
        i++;
    }
    
    // Copy into original linked list
    struct node * temp5 =head;
    struct node *temp6 = final;
    while (temp5!=NULL)
    {
        temp5->data = temp6->data;
        temp5 = temp5->link;
        temp6 = temp6->link;
    }
    
    // Display results
    display(head);
    
    
    return 0;
}
