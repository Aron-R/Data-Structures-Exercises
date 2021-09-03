//
//  main.c
//  Lab-4-1
//
//  Created by Aaron R on 03/09/21.
//  Stacks using arrays


#include <stdio.h>
#include <stdlib.h>
#define n 5
int stack[n];
int top = -1;

void push(void)
{
    int x;
    printf("Enter element: ");
    scanf("%d",&x);
    if (top==n-1)
        printf("Overflow\n");
    else
    {
        top++;
        stack[top] = x;
    }
}

int pop(void)
{
    int item;
    if (top==-1) {
        printf("Underflow\n");
        exit(0);
    }
    else
    {
        item = stack[top];
        top--;
        printf("popped: %d\n",item);
        return item;
    }
    
}

void peek(void)
{
    if (top==-1)
    {
        printf("Stack is empty");
    }
    else
        printf("top element: %d\n",stack[top]);
}

void display(void)
{
    if (top==-1)
    {
        printf("Stack is empty");
    }
    else
    {
        printf("Elements of stack: ");
        for (int i=top; i>=0; i++)
        {
            printf("%d\n",stack[i]);
        }
    }
}


int main(int argc, const char * argv[])
{
    push();
    pop();
    peek();
    display();
    return 0;
}
