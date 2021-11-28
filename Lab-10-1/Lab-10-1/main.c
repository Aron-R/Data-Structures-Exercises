//
//  main.c
//  Lab-10-1
//
//  Created by Aaron R on 12/11/21.
//  The Tamil Nadu Generation and Distribution Corporation Limited wants to provide electricity to five villages from the current power transmission unit established at a village. The weights on the edges represent the distance in kms between the villages. The cost of the electricity cable per km is Rs.150 approximately. Write a C program to find a cost-effective way of laying the electric cable to provide electricity to all five villages. Calculate Minimum cost spanning tree using Prims Algorithm.

//  Input:
//  → No. Of Vertex
//  → Starting Vertex
//  → Adjacency matrix representation of graph
//
//  Output:
//  Eg:
//  Edge 1: (0 4) Distance: 21
//  ......
//  Minimun Spanning Tree Cost: 1000

#include <stdio.h>

int main(int argc, const char * argv[])
{
    printf("Enter no. of vertices: ");
    int n;
    scanf("%d",&n);
    int adj[n][n];
    
    printf("Enter starting vertex: ");
    int start;
    scanf("%d",&start);
    
    printf("Adjacency matrix\n");
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
        {
            printf("Enter element [%d][%d]: ",i,j);
            scanf("%d",&adj[i][j]);
        }
    
    
    return 0;
}
