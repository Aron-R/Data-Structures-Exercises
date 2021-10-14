//
//  main.c
//  Lab-5-3
//
//  Created by Aaron R on 24/09/21.
//  Queues using Stacks

#include <stdio.h>
#include <stdlib.h>
int n;
int top1=-1, top2=-1;
int count=0;

void push1(int data,int stack1[])
{
    if(top1==n-1)
        printf("Queue Overflow.\n");
    else
    {
        // increment the top variable of the first stack
        top1++;

        // Add data
        stack1[top1] = data;
    }

}

void push2(int data,int stack2[])
{
    if(top2==n-1)
        printf("Queue Overflow.\n");
    else
    {
        // increment the top variable of the second stack
        top2++;

        // Add data
        stack2[top2] = data;
    }

}

int pop1(int stack1[])
{
    // store the top variable
    int temp = stack1[top1];

    // decrement the top variable
    top1 = top1-1;

    // return the top variable
    return temp;
}

int pop2(int stack2[])
{
    // store the top variable
    int temp = stack2[top2];

    // decrement the top variable
    top2 = top2-1;

    // return the top variable
    return temp;
}


void enqueue(int data,int stack1[])
{
    // push data into first stack
    push1(data,stack1);
    // Increment the count variable that keeps track of the queue length
    count++;
}

int dequeue(int stack1[], int stack2[])
{
    int result;
    // If the queue is empty
    if ((top1==-1)&& (top2==-1))
        printf("The queue is empty. Queue underflow.\n");

    // If the queue is not empty
    else
    {
        for (int i=0; i<count; i++)
            push2(pop1(stack1),stack2);

        result = pop2(stack2);

        count--;

        for (int i=0; i<count; i++)
            push1(pop2(stack2),stack1);
    }
    
    return result;
}

void display(int stack1[])
{
    if (top1==-1)
    {
        printf("queue is empty\n");
    }
    else
    {
        for (int i=0; i<=top1; i++)
            printf("%d ",stack1[i]);
        printf("\n");
    }
}

void peek(int stack1[])
{
    printf("%d\n",stack1[0]);
}

void empty(int stack1[],int stack2[])
{
    for (int i=0; i<count; i++)
    {
        pop1(stack1);
    }
}

int main(int argc, const char * argv[])
{
    printf("Enter n: ");
    scanf("%d",&n);
    int * stack1;
    int * stack2;
    stack1 = (int*) malloc(n * sizeof(int));
    stack2 = (int*) malloc(n * sizeof(int));
    
    // inputting data
    for (int i=0; i<n; i++)
    {
        int data;
//        printf("Enter data: ");
        scanf("%d",&data);
        
        enqueue(data, stack1);
    }
    
    // Display queue
    display(stack1);
    n = n+1;
    stack1 = realloc(stack1, n * sizeof(int));
    stack2 = realloc(stack2, n * sizeof(int));

    int data;
//    printf("Enter data: ");
    scanf("%d",&data);
    
    enqueue(data, stack1);
    
    // Display queue
    display(stack1);
    
    // Dequeue top element
    printf("%d\n",dequeue(stack1,stack2));
    
    display(stack1);
    
    peek(stack1);
    
    display(stack1);
    
    empty(stack1,stack2);
    
    display(stack1);
    
    
    
    
    return 0;
}
