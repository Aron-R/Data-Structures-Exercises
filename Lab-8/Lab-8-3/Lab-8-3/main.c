//
//  main.c
//  Lab-8-3
//
//  Created by Aaron R on 15/10/21.
//  Given a circular sorted array of six integers, find the number of times the array is rotated. Assume that there are no duplicate elements in the array and that the array is rotated only in the anti-clockwise direction.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void input_values(int arr[],int n)
{
    // #### Function to input values into an array ####
    for (int i=0; i<n; i++)
    {
        printf("Enter element %d: ",i+1);
        scanf("%d",&arr[i]);
    }
}

bool isSorted(int arr[],int n)
{
    // #### Function to check if the array is sorted ####
    bool condition = true;
    
    for (int i=0; i<n-1; i++)
        if (arr[i]>arr[i+1])
        {
            condition=false;
            break;
        }
    return condition;
}

void rotate(int arr[], int n)
{
    // #### Function to rotate an array in anti-clockwise direction
    int temp=arr[0];
    for (int i=0; i<n-1; i++)
        arr[i] = arr[i+1];
    arr[n-1] = temp;
}

int main(int argc, const char * argv[])
{
    // Inputting values of the array
    int * array;
    printf("Enter number of elements in array: ");
    int n;
    scanf("%d",&n);
    array = (int *) calloc(n, sizeof(int));
    input_values(array,n);
    
    // Determining the number of turns it takes to sort
    int turns=0;
    while (!isSorted(array, n))
    {
        rotate(array, n);
        turns++;
    }
    
    printf("Array is rotated %d times.\n",turns);
    free(array);

    return 0;
}

