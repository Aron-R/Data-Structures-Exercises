//
//  main.c
//  Lab-11-1
//
//  Created by Aaron R on 26/11/21.
//

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define infinity 2147483646

struct node
{
    int data;
    struct node * link;
};

void insert_head(struct node ** head,int data)
{
    struct node * current;
    // Function to insert node at the head
    current = (struct node *) malloc(sizeof(struct node));
    
    // Input the node's data
//    printf("Enter the data: ");
//    scanf("%d",&(*current)->data);
    (current)->data = data;
    
    // The address part of the new node points to the previous head
    (current)->link = *head;
    
    // The head variable is updated to the current one
    *head = current;
    
}

void insert_end(struct node ** head, int data)
{
    struct node * current;
    // Function to insert node at the end
    current = (struct node *) malloc(sizeof(struct node));
    // Input the node's data
//    printf("Enter the data: ");
//    scanf("%d",&(current)>data);
    
    (current)->data = data;
    // The link of the new node is NULL
    (current)->link = NULL;
    if (*head==NULL)
    {
        insert_head(head,data);
    }
    else
    {
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

int length (struct node *temp)
{
    // Function to count the number of elements in the linked list
    
    // If head is NULL, the linked list is empty
    if (temp==NULL)
        return 0;
    else
    // Else, count it's elements
    {
        int count = 0;
        while ((temp)!=NULL)
        {
            count++;
            temp = (temp)->link;
        }
        return count;
    }
}

bool isPresent(struct node *temp, int search)
{
    // To check if an element is present in the Linked list
    while ((temp)!=NULL)
    {
        if (temp->data == search)
        {
            return true;
        }
        temp = (temp)->link;
    }
    return false;
}

int next_node(int arr[],int n, struct node * queue)
{
    // #### Function to return the index of the minimum element
    int index = 0;
    int min=infinity+1;
    
    for(int i=0;i<n;i++)
    {
        if(arr[i]<min && (!(isPresent(queue, i))))
        {
            index = i;
            min = arr[i];
        }
    }
    return index;
}

int main(int argc, const char * argv[])
{
    // Input the number of vertices
//    printf("Enter numebr of vertices: ");
    int n;
    scanf("%d",&n);
    
    // Input the source
//    printf("Enter source: ");
    int source;
    scanf("%d",&source);
    
    // Input the adjacency matrix
    int adj[n][n];
    for (int i=0; i<n; i++)
        for(int j=0;j<n;j++)
        {
//            printf("Enter element [%d][%d] of adjacency matrix: ",i,j);
            scanf("%d",&adj[i][j]);
        }
    
    // Initialising total costs to reach each node
    int costs[n];
    costs[source] = 0;
    for (int i=0; i<n; i++)
        if(i!=source)
            costs[i]=infinity;
    
    
    int prev[n];
    for (int i=0; i<n; i++)
        prev[i] = -1;
    
    struct node * queue;
    queue = NULL;
    insert_end(&queue, source);
    int current = source;
    int next = next_node(costs, n, queue);
    
    while (length(queue)<=n)
    {
        // Traversing to check all adjascent nodes of current node
        for (int i=0; i<n; i++)
        {
            if(adj[current][i]!=0)
            {
                // Updating costs
                if(costs[current]+adj[current][i] < costs[i])
                {
                    costs[i] = costs[current] + adj[current][i];
                    prev[i] = current;
                }
            }
        }
        
        // Moving on to the next node
        current = next;
        next = next_node(costs, n, queue);
        insert_end(&queue, next);

    }
    
//    display(costs, n);
    
    for (int i=1; i<n; i++)
    {
        if(i!=source)
        {
            char str[100];
            strcpy(str, "");
            int target = i;
            while(prev[target]!=-1)
            {
                char str1[10];
                sprintf(str1, "%d", target);
                target = prev[target];
                strcat(str, str1);
                strcat(str, "<-");
            }
            strcat(str, "0");
            printf("<%d,%d> : Path =%s : Distance=%d\n",source,i,str,costs[i]);
        }
        
    }
    return 0;
}
