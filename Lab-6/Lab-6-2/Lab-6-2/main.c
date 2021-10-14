//
//  main.c
//  Lab-6-2
//
//  Created by Aaron R on 01/10/21.
//

#include <stdio.h>
#include <stdlib.h>

int binary_search(int arr[] , int start, int end, int search)
{
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

int main(int argc, const char * argv[])
{
    // Inputting data
    int n;
    // printf("Enter n: ");
    scanf("%d" ,&n);

    int * input;
    input = (int *) calloc(n, sizeof(int));
    for (int i = 0 ; i < n ;i++)
    {
        // printf("Enter the element %d: ",i+1);
        scanf("%d",(input+i));
    }
    
    // If the first 3 elements have same increment, then the missing element is not in the first 3
    int increment;
    if (((*(input+1)) - (*input)) == ((*(input+2))-(*(input+2))))
        increment = (*(input+1)) - (*input);
    
    // else, make the increment as the difference between the last 2 elements
    else
        increment = (*(input+(n-1))) - (*(input+(n-2)));
    
    // Initialise data with the first element of input array
    int data = *input;

    // To find missing element, if the binary search returns -1 then display the missing element
    for (int i = 0 ; i <= n; i++)
    {
        if (binary_search(input,0,n,data) != -1)
        {
            data += increment;
            continue;
        }
        else
        {
            printf("%d", data);
            break;
        }
        
    }

    free(input);

    return 0;
}
