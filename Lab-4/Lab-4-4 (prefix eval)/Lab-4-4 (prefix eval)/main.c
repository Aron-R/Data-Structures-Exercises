//
//  main.c
//  Lab-3-7 (prefix eval)
//
//  Created by Aaron R on 03/09/21.

//  Evaluate the given prefix expression **A+BCD using stacks. Assume your values
//  for A, B, C, and D. Implement the same using C.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char variables[100];
int values[100];
int variable_count=0;

struct node
{
    int data;
    struct node * link;
};

struct node * top;


void strrev(char *str)
{
    // Function to reverse string
    
    /* skip null */
    if (str == 0)
    {
        return;
    }

    /* skip empty string */
    if (*str == 0)
    {
        return;
    }

    /* get range */
    char *start = str;
    char *end = start + strlen(str) - 1; /* -1 for \0 */
    char temp;

    /* reverse */
    while (end > start)
    {
        /* swap */
        temp = *start;
        *start = *end;
        *end = temp;

        /* move */
        ++start;
        --end;
    }
}


void push(char c)
{
    // ##### Function to insert node at the head #####
    struct node * current;
    current = (struct node *) malloc(sizeof(struct node));
    
    // Input the node's data
    current->data = c;
    
    // The address part of the new node points to the previous head
    current->link = top;
    
    // The head variable is updated to the current one
    top = current;
}

int pop(void)
{
    // #### Function to delete the node at the beginning ####
    struct node * temp;
    if (top==NULL)
    {
        printf("The stack is empty. No elements to pop.\n");
        exit(0);
    }
    else
    {
        temp=top;
        int item = top->data;
        // The address of the head is updated to the next node
        top = top->link;
        
        // free the memory of the previous head
        free(temp);
        
        return item;
    }
    
}


int eval(char input[])
{
    int result=0;
    for (int i=0; i<strlen(input); i++)
    {
        if (isalpha(input[i]))
        {
            // If operand is encountered, push it into stack
            for (int j=0; j<variable_count; j++)
            {
                if (input[i]==variables[j])
                {
                    push(values[j]);
                    break;
                }
            }
        }
        else
        {
            // If operator is encountered
            // Pop 2 operands from stack
            
            int a = pop();
            int b = pop();
            
            // Result = temp2 <operator> temp1
            if (input[i]=='+')
                result = b + a;
            else if (input[i]=='-')
                result = b - a;
            else if (input[i]=='*')
                result = b * a;
            else
                result = b/a;
            
            push(result);
        }
    }
    return result;
}

void rmdup(char *array, int length)
{
    char *current , *end = array + length - 1;

    for ( current = array + 1; array < end; array++, current = array + 1 )
    {
        while ( current <= end )
        {
            if ( *current == *array )
            {
                *current = *end--;
                variable_count-=1;
            }
            else
            {
                current++;
            }
        }
    }
}
int main(int argc, const char * argv[])
{
    char input[100];
    printf("Enter prefix expression to be evaluated: ");
    scanf("%[^\n]",input);
    
    strrev(input);
    
    // Make a list of variables used
    for (int i=0; i<strlen(input); i++)
    {
        if (isalpha(input[i]))
        {
            variables[variable_count]=input[i];
            variable_count++;
        }
    }
    
    // Remove duplicates in variable set, if any
    rmdup(variables,variable_count);
    
    // Get the values of the variables
    for (int i=0; i<variable_count; i++)
    {
        printf("Enter the value of %c: ",variables[i]);
        scanf("%d",&values[i]);
    }
    
    // Evaluate expression
    printf("Answer: %d\n",eval(input));
    return 0;
}

