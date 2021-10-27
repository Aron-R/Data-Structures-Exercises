//
//  main.c
//  Lab-9-2
//
//  Created by Aaron R on 22/10/21.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* left, * right;
}Node;
int pairs=0;



Node* create(int data)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return (temp);
}

Node* node_insert(int arr[], Node* root, int n, int j)
{
    if (j < n)
    {
        Node* temp = create(arr[j]);
        root = temp;
        root->left = node_insert(arr, root->left, n,2*j+1);
        root->right = node_insert(arr, root->right, n, 2*j+2);
    }
    return root;
}

void search(int val, Node* root, int sum)
{
    
    if(root !=NULL)
    {
        if(root->data == val)
        {
            printf("%d %d ",sum-root->data,root->data);
            pairs++;
        }
        else
        {
            search(val,root->left,sum);
            search(val,root->right,sum);
        }
    }
}

void traverse(int val, Node* root)
{
    Node *temp=root;
    if (root != NULL)
    {
        int x = root->data;
        if(x<=val)
        {
            int y = val-root->data;
            search(y,temp,val);
        }
        traverse(val,root->left);
        traverse(val,root->right);
    }
}


int main(int argc, const char * argv[])
{
    int n,total,arr[100];
    scanf("%d ",&n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    
    Node* root=NULL;
    root = node_insert(arr, root, n, 0);
    
    scanf("%d",&total);
    traverse(total,root);
    
    if(pairs==0)
        printf("Pair not present\n");
    
}

 
