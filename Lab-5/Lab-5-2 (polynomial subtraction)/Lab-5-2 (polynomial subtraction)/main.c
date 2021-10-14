//
//  main.c
//  Lab-5-2 (polynomial subtraction)
//
//  Created by Aaron R on 24/09/21.
//

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coef,exp;
    struct node * link;
};

struct node *result;

void display (struct node *temp)
{
    // Function to display the data in the linked list

    // If head is NULL, the linked list is empty
    if (temp==NULL)
        printf("The single linked list is empty\n");
    else
    // Else, display it's elements
        while ((temp)!=NULL)
        {
            printf("%d ",(temp)->coef);
            printf("%d ",(temp)->exp);
            temp = (temp)->link;
        }
}


void insert_head(struct node ** head,int c, int e)
{
    // ##### Function to insert node at the head #####
    struct node * current;
    current = (struct node *) malloc(sizeof(struct node));

    current->coef = c;
    current->exp = e;
    
    // The address part of the new node points to the previous head
    current->link = *head;
    
    // The head variable is updated to the current one
    *head = current;
    
}

void insert_end(struct node ** head,int c, int e)
{
    // ##### Function to insert node at the end #####
    
    if (*head==NULL)
    {
        insert_head(head,c,e);
    }
    
    else
    {
        struct node * current;
        current = (struct node *) malloc(sizeof(struct node));
        // Input the node's data
        current->coef = c;
        current->exp = e;
        
        // The link of the new node is NULL
        current->link = NULL;
        
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

void SortLinkedList(struct node **head)
    {
    struct node *temp = NULL;
    struct node *temp2 = NULL;
    temp2 = *head;
    //temp variable to store node data
    int tempvar1,tempvar2;

    while(temp2 != NULL)
    {
        temp=temp2;
        //traverse till the second last element
        while (temp->link !=NULL)
        {
            // comparing the data of the nodes
           if(temp->exp < temp->link->exp)
            {
                // swap
                tempvar1 = temp->exp;
                temp->exp = temp->link->exp;
                temp->link->exp = tempvar1;
                
                tempvar2 = temp->coef;
                temp->coef = temp->link->coef;
                temp->link->coef = tempvar2;
              
            }
         temp = temp->link;
        }

        temp2 = temp2->link;
    }
}

void subtract(struct node *temp, struct node *temp2)
{
   
    while ((temp != NULL) && (temp2 != NULL))
    {
        // If the exponents are the same, subtract the coefficients
        if (temp->exp== temp2->exp)
        {
            insert_end(&result, ((temp->coef) - (temp2->coef)), temp->exp);
            temp = temp->link;
            temp2 = temp2->link;
        }
        // If the exponent of polynomial 1 is greater, add it to the result
        else if (temp->exp > temp2->exp)
        {
            insert_end(&result, temp->coef, temp->exp);
            temp = temp->link;
        }

        // if the exponent of polynomial 2 is greater, add it to the result
        else if (temp2->exp> temp->exp)
        {
            insert_end(&result, temp2->coef, temp2->exp);
            temp2 = temp2->link;
        }
    }

    // Add the remaining terms from polynomial 1 to the result
    while (temp != NULL)
    {
        insert_end(&result, temp->coef, temp->exp);
        temp = temp->link;
    }

    // Add the remaining terms from polynomial 2 to the result
    while (temp2 != NULL)
    {
        insert_end(&result, temp2->coef, temp2->exp);
        temp2 = temp2->link;
    }
}


int main(int argc, const char * argv[])
{
    // Inputting the data of the first polynomial

    int n;
    // printf("Enter no. of terms of first polynomial: ");
    scanf("%d",&n);
    struct node *head1, *current1;
    head1 = NULL;
    current1 = NULL;
    for (int i=0; i<n; i++)
    {
        int c,e;
        // printf("Enter coefficient: ");
        scanf("%d",&c);
        // printf("Enter exponent: ");
        scanf("%d",&e);
        insert_end(&head1,c,e);
    }
    
    // Inputting the data of the second polynomial
    struct node *head2, *current2;
    head2 = NULL;
    current2 = NULL;
    // printf("Enter no. of terms of second polynomial: ");
    scanf("%d",&n);
    for (int i=0; i<n; i++)
    {
        int c,e;
        // printf("Enter coefficient: ");
        scanf("%d",&c);
        // printf("Enter exponent: ");
        scanf("%d",&e);
        insert_end(&head2,c,e);
    }
    
    // Sorting the two polinomials in descending order
    SortLinkedList(&head1);
    SortLinkedList(&head2);
    
    // Subtracting the polynomials
    subtract(head1, head2);
    
    // Displaying the result
    display(result);
    
    return 0;
}
