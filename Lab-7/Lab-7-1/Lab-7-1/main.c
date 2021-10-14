//
//  main.c
//  Lab-7-1
//
//  Created by Aaron R on 08/10/21.
//  Bubble sort

#include <stdio.h>

void input_values(int input[], int n)
{
    // #### To input values into an array ####
    for (int i=0; i<n; i++)
    {
        printf("Enter element %d: ",i+1);
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

void bubble_sort(int input[],int n)
{
    // #### Bubble Sort ####
    // Bubble sort algorithm to arrange in descending order
    for (int i=0; i<n-1; i++)
    {
        for (int j=0; j<(n-i-1); j++)
            if (input[j]<input[j+1])
            {
                int temp = input[j];
                input[j] = input[j+1];
                input[j+1] = temp;
                
            }
        display(input, n);
    }
        
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
    printf("Enter n: ");
    int n;
    scanf("%d",&n);
    int input[n];
    input_values(input,n);
    
    // #### Bubble sort ####
    bubble_sort(input, n);
    
    // Input value to be searched
    printf("Enter value to be searched: ");
    int search;
    scanf("%d",&search);
    
    // Bincary search to find the value
    printf("%d %d\n",search,binary_search(input, 0, n, search));
    
    return 0;
}


