//
//  main.c
//  pat-2-1
//
//  Created by Aaron R on 19/11/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int n;
void input_values(int arr[],int n)
{
    // #### Function to input values into an array ####
    for (int i=0; i<n; i++)
    {
        printf("Enter element %d: ",i+1);
        scanf("%d",&arr[i]);
    }
}


void display(int arr[],int n)
{
    // #### Function to display the values of an array ####
    for (int i=0; i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
    
}

bool initial_condition = true;

int partition (int a[], int lower_bound, int higher_bound)
{
    // #### Function to partition the array ####
    
    if(lower_bound>=higher_bound)
        return 0;
    
    // Choose a pivot value
    int mid = (lower_bound+higher_bound)/2;
    int pivot = a[mid];
    
    if(initial_condition)
        {
            printf("%d\n",pivot);
            initial_condition=false;
        }
    
    // Initialize left and right pointers at extremes
    int start = lower_bound;
    int end = higher_bound;
    
    while (start<end)
    {
        // Starting at the left pointer and moving to the right, find the first element which is greater than or equal to the pivot value
        while((start<end) && (a[start]<=pivot))
        {
            start++;
        }
        
        // Starting at the right pointer and moving to the left, find the first element, which is smaller than pivot value
        while ((a[end]>pivot))
        {
            end = end - 1;
        }
        
        // Swap the elements found
        if (start<end)
        {
            int temp = a[start];
            a[start] = a[end];
            a[end] = temp;
        }
    }
    
    int temp = a[mid];
    a[end] = a[mid];
    a[end] = temp;
    return mid;
    
}

void quicksort(int a[],int lower_bound,int higher_bound)
{
    // ## Quick sort using middle element as pivot
    if (lower_bound<higher_bound)
    {
        display(a, n);
        int location = partition(a, lower_bound, higher_bound);
        printf("%d\n",location);
        quicksort(a, lower_bound, location-1);
        quicksort(a, location+1, higher_bound);
    }
}

int main(int argc, const char * argv[])
{
    
    printf("Enter n: ");
    scanf("%d", &n);
    int * array;
    array = (int *) calloc(n, sizeof(int));
    input_values(array, n);
    

    quicksort(array, 0, n-1);

    display(array, n);
    
    return 0;
}

