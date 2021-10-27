//
//  main.c
//  Lab-8-1
//
//  Created by Aaron R on 15/10/21.
//

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

void merge(int set1[],int set2[], int n1, int n2, int * final)
{
    // #### Function to merge the two sorted arrays ####
    int i=0,j=0,k=0;
    
    // To add the elements to the final array in the appropriate order
    for (;i<n1 && j<n2;k++)
    {
        // If the element of set 1 is less that set2
        if (set1[i]<=set2[j])
        {
            // Add it to the final list
            *(final+k) = set1[i];
            i++;
        }
        
        // Else add the element of set 2 to the final list
        else
        {
            *(final+k) = set2[j];
            j++;
        }
        
        display(final, n1+n2);
    }
    
    // If there are any remaining elements, add them to the final list
    if (j<n2)
    {
        while (j<n2)
        {
            *(final+k) = set2[j];
            j++;
            k++;
            display(final, n1+n2);
        }
    }
    else if (i<n1)
    {
        while (i<n1)
        {
            *(final+k) = set1[i];
            i++;
            k++;
            display(final, n1+n2);
        }
    }
}

int main(int argc, const char * argv[])
{
    // Inputting values of set1
    int * set1;
    printf("Enter number of elements in first array: ");
    int n1;
    scanf("%d",&n1);
    set1 = (int *) calloc(n1, sizeof(int));
    input_values(set1,n1);
    
    // Inputting values of set
    int * set2;
    printf("Enter number of elements in second array: ");
    int n2;
    scanf("%d",&n2);
    set2 = (int *) calloc(n2, sizeof(int));
    input_values(set2, n2);
    
    // Function call to merge
    int * final;
    final = (int *) calloc(n1 + n2, sizeof(int));
    merge(set1, set2, n1, n2,final);
    
    free(set1);
    free(set2);
    free(final);
    return 0;
}
