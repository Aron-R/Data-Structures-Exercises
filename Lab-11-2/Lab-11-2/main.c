//
//  main.c
//  Lab-11-2
//
//  Created by Aaron R on 27/11/21.
//  Floyd Warshall Algorithm All Pair Shortest Path algorithm

#include <stdio.h>

void copy(int n,int arr1[][n], int arr2[][n])
{
    // #### Function to Copy a 2d array into another ####
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            arr1[i][j] = arr2[i][j];
}

void display(int n,int temp[][n])
{
    // #### Function to display 2d array ####
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            printf("%d ",temp[i][j]);
        
        printf("\n");
    }
}

void input(int n, int adj[][n])
{
    // #### Function to input into 2d array ####
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
        {
            printf("Enter element [%d][%d] of adjacency matrix: ",i,j);
            scanf("%d",&adj[i][j]);
        }
}

void Floyd_Warshall(int n, int temp[][n])
{
//    #### Function to carry out Floyd Warshall's Algorithm ####
    for (int i=0; i<n; i++)
    {
        int d[n][n];
        for (int j=0; j<n; j++)
            for (int k=0; k<n; k++)
            {
                if (j==k||j==i||k==i)
                    d[j][k]=temp[j][k];
    
                else if(temp[j][k] < temp[j][i] + temp[i][k])
                    d[j][k] = temp[j][k];
                
                else if(temp[j][k] > temp[j][i] + temp[i][k])
                    d[j][k] = temp[j][i] + temp[i][k];
            }
        
        copy(n, temp, d);
    }
}

int main(int argc, const char * argv[])
{
    // Inputting n
    printf("Enter n: ");
    int n;
    scanf("%d",&n);
    
    // Inputting adjacency matrix
    int adj[n][n];
    input(n, adj);
    
    // Initialising the matrix
    int temp[n][n];
    copy(n, temp, adj);
    
    Floyd_Warshall(n, temp);
    
    // Displaying the final answers
    display(n, temp);
    return 0;
}
