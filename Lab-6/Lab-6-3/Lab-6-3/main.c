//
//  main.c
//  Lab-6-3
//
//  Created by Aaron R on 17/10/21.
//  Binary search

#include <stdio.h>
#include <stdlib.h>

void input_values(int arr[],int n)
{
    // #### Function to input values into an array ####
    for (int i=0; i<n; i++)
    {
        printf("Enter element %d: ",i+1);
        scanf("%d",&arr[i]);
    }
}
int binary_search(int arr[] ,int end, int search)
{
    int start=0;
    // While the start index is less than or equal to the end index
    while (start <= end)
    {
        // Middle = floor value of the mid point between start and end
        int middle = start + (end- start )/2;
        
        // If the element in the middle = the element to be searched, the element is found
        if (arr[middle] == search)
            return middle;
        
        // If the element to be searched is greater than the element in the middle,
        // update start to middle +1

        else if (search > arr[middle] )
            start = middle + 1;

        // If the element to be searched is less than the element in the middle,
        // update end to middle - 1
        else
            end = middle - 1;
    }
    
    // If the start index is greater than the end index, element is not present
    return -1;
}
int main(int argc, const char * argv[]) {
    // Inputting values of the array
    int * array;
    printf("Enter number of elements in array: ");
    int n;
    scanf("%d",&n);
    array = (int *) calloc(n, sizeof(int));
    input_values(array,n);
    
    int search;
    printf("Enter element to search: ");
    scanf("%d",&search);
    
    binary_search(array, n, search);
    
    
    return 0;
}
