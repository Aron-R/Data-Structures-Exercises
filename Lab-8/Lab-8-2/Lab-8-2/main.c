//
//  main.c
//  Lab-8-2
//
//  Created by Aaron R on 15/10/21.
//  You are given some integers and have been asked to sort them in a particular fashion. In this approach, every time you choose an integer from the given list and place it at a position you make sure that all the numbers left to it are either less than or equal to that number and all the elements right of it are greater than that number. Proceed in this way and finally write a code that sorts the given list in ascending order.

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


void display(int arr[],int n)
{
    // #### Function to display the values of an array ####
    for (int i=0; i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
    
}

int partition (int a[], int lower_bound, int higher_bound)
{
    int pivot = a[lower_bound];
    int start = lower_bound;
    int end = higher_bound;

    while (start<end)
    {
        while((start < end) && (a[start] <= pivot) )
        {
            start++;
        }
        while (a[end]>pivot)
        {
            end = end - 1;
        }

        if (start<end)
        {
            int temp = a[start];
            a[start] = a[end];
            a[end] = temp;
        }
    }
    int temp = a[lower_bound];
    a[lower_bound] = a[end];
    a[end] = temp;
    return end;
}

void quicksort(int a[],int lower_bound,int higher_bound)
{
    if (lower_bound<higher_bound)
    {
        int location = partition(a, lower_bound, higher_bound);
        quicksort(a, lower_bound, location-1);
        quicksort(a, location+1, higher_bound);
    }
}

int main(int argc, const char * argv[])
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int * array;
    array = (int *) calloc(n, sizeof(int));
    input_values(array, n);
    

    quicksort(array, 0, n-1);

    display(array, n);
    
    return 0;
}
