//
//  main.c
//  linked-list-string
//
//  Created by Aaron R on 03/09/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRLENGTH 100

typedef struct node {
   char data;
   struct node *next;
} node;

void insert_head(struct node ** head,char c)
{
    // ##### Function to insert node at the head #####
    struct node * current;
    current = (struct node *) malloc(sizeof(struct node));
    
    // Input the node's data
    (current)->data = c;
    
    // The address part of the new node points to the previous head
    (current)->next = *head;
    
    // The head variable is updated to the current one
    *head = current;
    }
void insert_end(struct node ** head,char c)
{
    // ##### Function to insert node at the end #####
    
    if (*head==NULL)
    {
        insert_head(head,c);
    }
    
    else
    {
        struct node * current;
        current = (struct node *) malloc(sizeof(struct node));
        // Input the node's data
        printf("Enter the data: ");
        current->data=c;
        
        // The link of the new node is NULL
        (current)->next = NULL;
        
        // A temporary node is created
        struct node * temp;
        temp = *head;
        
        // It is used to traverse to the end of the existing linked list
        while (temp->next!=NULL)
        {
            temp = temp->next;
        }
        
        // The link of the node at the end of the existing linked list is updated to the new node
        temp->next = current;
        }
}
int main(void) {
   char str[STRLENGTH];
   printf("Enter a string: ");
    scanf("%[^\n]",str);

   node *head = NULL;

   int i;
   for(i = 0; str[i] != '\0'; i++)
   {
      if(str[i] == ' ')
          insert_end(&head,0);
      else
          insert_end(&head, str[i]);
   }

   while(head != NULL) {
      printf("%c", head -> data);
      head = head -> next;
   }

   return 0;
}
