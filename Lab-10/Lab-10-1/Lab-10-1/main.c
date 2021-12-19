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

#include<stdio.h>



int main()
{
    int temp_1=0;
    int temp_2=0;
    int temp_3=1;
    int Vertices;
    int start;
    int visited_nodes[100]={0};
    int cost=0;
    
    
    //Input no. of vertices
    scanf("%d",&Vertices);
    scanf("%d",&start);   //Input start vertex for the MST
    int adjacencyMatrix[Vertices][Vertices];
    visited_nodes[start]=1;
    
    
    //Input adjacency matrix
    for(int i=0;i<Vertices;i++)
    {
        for(int j=0;j<Vertices;j++)
        {   scanf("%d",&adjacencyMatrix[i][j]);
            if(adjacencyMatrix[i][j]==0)
            {
                // __INT_MAX__ = infinity
                adjacencyMatrix[i][j]=__INT_MAX__;
            }
        }
    }
    
    //prim's algorithm
    while(temp_3 < Vertices)
    {
        int least = __INT_MAX__;
        for(int i=0; i<=Vertices; i++)
            for(int j=0; j<Vertices; j++)
                if(adjacencyMatrix[i][j]< least)
                
                    if(visited_nodes[i]!=0)
                    {
                        least=adjacencyMatrix[i][j];
                        temp_1 = i;
                        temp_2 = j;
                    }
                    if(visited_nodes[temp_1]==0 || visited_nodes[temp_2]==0)
                    {
                        temp_3++;
                        cost += least;
                        visited_nodes[temp_2] = 1;
                        printf("Edge %d: (%d %d) Distance: %d \n", temp_3-1, temp_1, temp_2, least);
                    }
            adjacencyMatrix[temp_2][temp_1] = __INT_MAX__;
            adjacencyMatrix[temp_1][temp_2] = __INT_MAX__;
            
    }
    printf("Minimun Spanning Tree Cost: %d",cost*150);
    return 0;
}
