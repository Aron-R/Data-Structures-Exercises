//
//  main.c
//  pat-1-2
//
//  Created by Aaron R on 3/9/21.
//  Write a program to verify balancing parentheses in an expression. Print ‘1’ if the expression is balanced and ‘-1’ if the expression is unbalanced.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialising stack
int top = -1;
char stack[100];

// #### STACK OPERATIONS ####
void push(char c)
{
    // Function to push an element into the stack
    stack[top] = c;
    top++;
}

int pop(void)
{
    // Function to pop an element from the stack
    int item;
    if (top==-1) {
        printf("Underflow\n");
        exit(0);
    }
    else
    {
        item = stack[top];
        top--;
        return item;
    }
    
}
// #######


void balance(char input[])
{
    // Function to verify balancing the paranthesis in an expression

    for(int i=0;i<strlen(input);i++)
    {
        // Push the opening paranthesis into the stack
        if(input[i] == '(' || input[i] == '[' || input[i] == '{')
            push(input[i]);
        else
        {
            // If it's a closing paranthesis, check if it has a matching opening paranthesis
            // Do this for 3 kinds of paranthesis
            if(input[i]==')')
            {
                // If it does match with an open parantheis, pop it from the stack
                if(stack[top]=='(')
                    pop();
            }
            else
            {
                // Else, it isn't balanced
                printf("-1");
                break;
            }
            

            if(input[i]==']')
            {
                // If it does match with an open parantheis, pop it from the stack
                if(stack[top]=='[')
                    pop();
            }
            else
            {
                // Else, it isn't balanced
                printf("-1");
                break;
            }

            if(input[i]=='}')
            {
                // If it does match with an open parantheis, pop it from the stack
                if(stack[top]=='{')
                    pop();
            }
            else
            {
                // Else, it isn't balanced
                printf("-1");
                break;
            }

        }
    }

    // If the stack is empty, it is balanced
    if(top==-1)
        printf("1");
}
        
int main()
{
    // Input
    char input[100];
    scanf("%[^\n]",input);

    // Balance the expression
    balance(input);
    
    return 0;
}
