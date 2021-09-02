//
//  main.cpp
//  Lab-1-4
//
//  Created by Aaron R on 08/08/21.
//  Find the number of occurrences of elements in an array in descending order i.e. the element having highest number of occurrences should be displayed first and the element having least number of occurrences would be displayed last.
//Example: An array containing {13, 15, 11, 18, 13, 15, 15}
//Output:
//    15 present 3 times
//    13 present 2 times
//    11 present 1 times
//    18 present 1 times


#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct element
{
    int number, count;
};

void get_info(int p[],int n)
{
    // input the array elements
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter the element at index "<<i<<" ";
        cin>>p[i];
    }
}

void unique(int rm_duplicates[], int p[], int n, int &counter)
{
    // Function to get unique values from the array
    int zero_counter=0;
    for (int i=0; i<n; i++)
    {
        int condition = 0;
        for (int j=0; j<n; j++)
        {
            
            if (*(p+i) == *(rm_duplicates+j))
            {
                if ((*(p+i) == *(rm_duplicates+j))&&(*(p+i)==0)&&(zero_counter==0))
                {
                    *(rm_duplicates+counter) = 0;
                    zero_counter+=1;
                    counter +=1;
                    condition = 1;
                }
                else
                {
                    condition = 1;
                    break;
                }
            }
        }
    if (condition==0)
        {
                
            *(rm_duplicates+counter) = *(p+i);
            counter+=1;
        }
    }
    if (counter==n)
        cout<<"No Duplicates found"<<endl;
        
    else
    {
        // reducing the size of rm_duplicates
        rm_duplicates = (int *)realloc(rm_duplicates, counter*sizeof(int));
    }
}

void struct_info(struct element arr[],int rm_duplicates[],int p[],int counter,int n)
{
    // Function to store the elements and their frequency in teh form of a struct
    for (int i=0; i<counter; i++)
    {
        arr[i].number = rm_duplicates[i];
        
        int frequency=0;
        for (int j=0; j<n; j++)
            if(rm_duplicates[i]==p[j])
                frequency+=1;
        
        arr[i].count=frequency;
    }
}

void display_struct(struct element arr[],int counter)
{
    // Display the struct info
    for (int i=0; i<counter; i++)
        cout<<arr[i].number<<" is present "<<arr[i].count<<" times"<<endl;
}

void struct_sort(struct element arr[], int counter)
{
    // Sort the struct array in descending order
    for (int i=0; i<counter-1; i++)
    {
            for (int j = 0; j < counter-i-1; j++)
            {
                if (arr[j].count<arr[j+1].count)
                    {
                        struct element temp;
                        temp.count = arr[i].count;
                        temp.number = arr[i].number;

                        arr[i].number = arr[i+1].number;
                        arr[i].count = arr[i+1].count;
                        
                        arr[i+1].number = temp.number;
                        arr[i+1].count = temp.count;
                    }
            }
    }
}

int main(int argc, const char * argv[])
{
    int n, *p, *rm_duplicates,counter=0;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    p = (int *) malloc(n * sizeof(int));
    rm_duplicates = (int *) malloc(n * sizeof(int));

    
    // inputting the values for the array
    get_info(p,n);
    
    // checking to see if there are duplicates
    unique(rm_duplicates,p,n,counter);
    
    struct element arr[counter];
    // Storing the information in a structure array
    struct_info(arr,rm_duplicates,p,counter, n);

    // Displaying the information in the structure array
    display_struct(arr,counter);
    
    // sorting the structure in descending order
    struct_sort(arr, counter);
    
    // Displaying in descending order of frequency
    cout<<"\nDescending order: \n";
    display_struct(arr, counter);
    
    return 0;
}

