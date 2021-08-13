//
//  main.cpp
//  Lab-1-5
//
//  Created by Aaron R on 11/08/21.
//  Find the first and the second largest element in an array of ‘n’ numbers.

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

void array_sort(int arr[], int n)
{
    // sorting the array
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (arr[j] < arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
}

int main(int argc, const char * argv[])
{
    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    
    int arr[n];
    // input the array eleemnts
    get_data(arr, n);
    
    // sort the array in descending order
    array_sort(arr, n);
 
    cout<<"First largest element in the array: "<<arr[0]<<"\n";
    cout<<"Second largest element in the array: "<<arr[1]<<"\n";
    return 0;
}
