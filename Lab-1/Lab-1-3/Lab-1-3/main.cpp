//
//  main.cpp
//  Lab-1-3
//
//  Created by Aaron R on 08/08/21.
//  Program to print all indices of a user given number ‘X’ in an array.

#include <iostream>
using namespace std;

void get_data(int arr[], int n)
{
    // input data
    for (int i=0; i<n; i++)
    {
        cout<<"Enter the element at index "<<i<<": ";
        cin>>arr[i];
    }
}

void find_indices(int arr[], int n)
{
    // input the element to search
    cout<<"Enter number 'X' to search: ";
    int find;
    cin>>find;
    
    // search for the user inputted element
    int counter=0;
    for (int i=0; i<n; i++)
        if (arr[i]==find)
        {
            cout<<"Element is present at index "<<i<<endl;
            counter+=1;
        }
    
    if (counter==0)
        cout<<"Element not present in array\n";
}

int main(int argc, const char * argv[])
{
    cout<<"Enter the number of elements: ";
    int n;
    cin>>n;
    
    int arr[n];
    // input the array eleemnts
    get_data(arr, n);
    
    // input the element to search and print all the indices it's present in
    find_indices(arr, n);
    
    return 0;
}
