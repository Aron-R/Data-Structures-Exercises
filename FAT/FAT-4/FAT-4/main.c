//
//  main.c
//  FAT-1
//
//  Created by Aaron R on 10/12/21.
//

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* right;
    struct node* left;
   
};

struct node* insert(struct node* root_node,int values[], int n, int start)
{
    // #### Function to insert into BST ####
    if (start<n)
    {
        struct node* temp;
        temp = malloc(sizeof(struct node));
        
        temp->data = values[start];
        root_node = temp;
        
        int left =2*start+1;
        int right = 2*start + 2;
        root_node->left = insert(root_node->left,values, n, left);
        root_node->right = insert(root_node->right,values,n,right);
    }
    return root_node;
}

int total = 0;
int root_to_leaf_sum(struct node* current_node)
{
    // #### Function to calculate the sum of the string of numbers from root to leaf ####
    static int current_sum = 0;
    
    if (current_node == NULL)
        return 0;
    
    else if (current_node->left==NULL && current_node->right==NULL)
    {
        current_sum = current_sum*10 + current_node->data;
        total += current_sum;
    }
    
    else
    {
        current_sum = current_sum*10 + current_node->data;
        root_to_leaf_sum(current_node->left);
        root_to_leaf_sum(current_node->right);
    }
    
    current_sum /= 10;
    return total;
}

int main()
{
    // input n
    int n;
    
//    printf("Enter n: ");
    scanf("%d\n", &n);
    
    // Input the values
    int inputs[n];
    for(int i=0; i<n; i++)
    {
//        printf("Enter data: ");
        scanf("%d", &inputs[i]);
    }
    // Insert into binary tree
    struct node* binary_tree = NULL;
    binary_tree = insert(binary_tree,inputs,n,0);
    
    // Calculate and display the sum
    printf("%d", root_to_leaf_sum(binary_tree));

    return 0;
}


