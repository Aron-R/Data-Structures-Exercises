//
//  main.cpp
//  Lab-10-2
//
//  Created by Aaron R.
//

#include<stdio.h>


int findIndex(int i, int arr[])
{
    // To find the index
    while(arr[i])
        i=arr[i];
    return i;
}

int union_set(int i,int j,int arr[])
{
    // To perform union operation
    if(i!=j)
    {
        arr[j]=i;
        return 1;
    }
    return 0;
}

int main()
{
    int arr[10],vertices,i, j,a=0, b=0,init_index_a=0, init_index_b=0,count = 1,min,total_cost=0;
    
    scanf("%d",&vertices);
    int costs[100][100];
    for(i=0;i<vertices;i++){
        for(j=0;j<vertices;j++)
        {
            scanf("%d",&costs[i][j]);
            if(costs[i][j]==0)
                costs[i][j]=__INT_MAX__;}
        }
    while(count<vertices)
    {
        for(i=0,min=__INT_MAX__;i<vertices;i++){
            for(j=0;j<vertices;j++)
            {
                if(costs[i][j] < min)
                {
                    min=costs[i][j];
                    init_index_a = a=i;
                    init_index_b = b=j;
                }
            }
        }
        
        a=findIndex(a,arr);
        b=findIndex(b,arr);
        if(union_set(a,b,arr))
        {
            printf("Edge %d: (%d %d) Distance: %d \n",count++, init_index_b,init_index_a,min);
            total_cost +=min;
        }
        costs[init_index_a][init_index_b]=costs[init_index_b][init_index_a]=__INT_MAX__;
    }
    printf("Minimun Spanning Tree Cost: %d\n",total_cost*150);
    return 0;
}

