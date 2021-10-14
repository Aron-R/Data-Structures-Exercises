//
//  main.c
//  Lab-7-2
//
//  Created by Aaron R on 08/10/21.
//  Insertion sort

#include <stdio.h>

void input_values(int input[], int n)
{
    // #### To input values into an array ####
    for (int i=0; i<n; i++)
    {
        // printf("Enter element %d: ",i+1);
        scanf("%d",&input[i]);
    }
}
void display(int input[], int n)
{
    // #### To display the elements of the array ####
    for (int i=0; i<n; i++) {
        printf("%d ",input[i]);
    }
    printf("\n");
}

void insertion_sort(int input[],int n)
{
    // #### Insertion Sort ####
    // Insertion sort algorithm to arrange in descending order
    
    // Iterating from left to right in original array
    for (int i=1; i<n; i++)
    {
        // The unsorted element or the element being inserted in it's position
        // is stored in "unsorted_element" and it's current index in the array
        int unsorted_element = input[i];
        int unsorted_index = i-1;
        
        // While loop that starts from the current unsorted element and moves to the left
        while (unsorted_index>=0 && input[unsorted_index]<unsorted_element)
        {
            // If i is not less than 0
            // and the element in the array is greater that the unsorted element
            // Swap.
            input[unsorted_index+1] = input[unsorted_index];
            unsorted_index = unsorted_index - 1;
        }
        // Else, (insert the value in the unsorted_index + 1)'th position
        input[unsorted_index+1] = unsorted_element;
        display(input,n);
    }
    // display(input,n);
    
        
}

int binary_search(int arr[] , int start, int end, int search)
{
    // #### Binary Search ####
    
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

        else if (search < arr[middle] )
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
    // Inputting values
    // printf("Enter n: ");
    int n;
    scanf("%d",&n);
    int input[n];
    input_values(input,n);
    
    // #### Insertion sort ####
    insertion_sort(input, n);
    
    // Input value to be searched
    // printf("Enter value to be searched: ");
    int search;
    scanf("%d",&search);
    
    // Bincary search to find the value
    printf("%d %d\n",search,binary_search(input, 0, n, search));
    
    return 0;
}



