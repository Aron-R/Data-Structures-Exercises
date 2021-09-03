//
//  main.c
//  Lab-3-4 (infix to postfix)
//
//  Created by Aaron R on 03/09/21.
//

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * link;
};

struct node * stack;

void push(char c)
{
    // ##### Function to insert node at the head #####
    struct node * current;
    current = (struct node *) malloc(sizeof(struct node));
    
    // Input the node's data
    current->data = c;
    
    // The address part of the new node points to the previous head
    current->link = stack;
    
    // The head variable is updated to the current one
    stack = current;
}

char pop(void)
{
    // #### Function to delete the node at the beginning ####
    struct node * temp;
    if (stack==NULL)
    {
        printf("The stack is empty. No elements to pop.\n");
        exit(0);
    }
    else
    {
        temp=stack;
        char item = stack->data;
        // The address of the head is updated to the next node
        stack = stack->link;
        
        // free the memory of the previous head
        free(temp);
        
        return item;
    }
    
}
char peek(void)
{
    // Function to return the top value of the stack
    if (stack == NULL)
        return 0;
    
    else
        return stack->data;
    
}

int check(char x)
{
    // To check precedence
    if (x == '(')
        return 0;
    else if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    return 0;
}

int main()
{
    char exp[100];
    char *temp, x;
    printf("Enter infix expression : ");
    scanf("%[^\n]", exp);
    printf("\n");
    
    temp = exp;
    printf("Postfix expression:\n");
    while (*temp != '\0')
    {
        if (isalnum(*temp))
            printf("%c", *temp);
        else if (*temp == '(')
            push(*temp);
        else if (*temp == ')')
        {
            while ((x = pop()) != '(')
                printf("%c", x);
        }
        else
        {
            while (check(peek()) >= check(*temp))
                printf("%c", pop());
            push(*temp);
        }
        temp+=1;
    }
    
    while (stack != NULL)
    {
        printf("%c", pop());
    }
    printf("\n###########\n");
    return 0;
}

