//
//  main.c
//  Lab-2-1
//
//  Created by Aaron R on 13/08/21.
//  Create a single linked list and insert a node at the beginning, end and any position
//  in between.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

int main(int argc, const char * argv[])
{
    struct node *head = NULL;
    struct node *current = NULL;
    
    
    
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 10;
    head->link = NULL;
    
    current = (struct node *)malloc(sizeof(struct node));
    current->data = 20;
    current->link = NULL;
    head->link = current;
    
    current = malloc(sizeof(struct node));
    current->data = 7;
    current->link = NULL;
    head->link->link = current;
    
    printf("%d, %d, %d",head->data,head->link->data,head->link->link->data);
    
    return 0;
}
