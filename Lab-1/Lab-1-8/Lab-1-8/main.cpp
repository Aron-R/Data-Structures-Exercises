//
//  main.cpp
//  Lab-1-8
//
//  Created by Aaron R on 11/08/21.
//  Get the details of a student and display them using structures.i.e. Student name, roll no, marks, cgpa and date of birth.

#include <iostream>
using namespace std;

struct student
{
    string name;
    int roll,marks;
    float cgpa;
};

void get_info(struct student arr[], int n)
{
    // function to input the data of the students
    for (int i=0; i<n; i++)
    {
        cout<<"Enter name: ";
        cin>>arr[i].name;
        
        cout<<"Enter roll no: ";
        cin>>arr[i].roll;
        
        cout<<"Enter marks: ";
        cin>>arr[i].marks;
        
        cout<<"Enter cgpa: ";
        cin>>arr[i].cgpa;
    }
        
}

void display(struct student arr[], int n)
{
    // function to display the data of the students
    for (int i=0; i<n; i++)
    {
        cout<<"Student "<<i+1<<endl;
        cout<<"Name: "<<arr[i].name<<endl;
        cout<<"Roll no: "<<arr[i].roll<<endl;
        cout<<"Marks: "<<arr[i].marks<<endl;
        cout<<"cgpa: "<<arr[i].cgpa<<"\n\n";
    }
        
}

int main(int argc, const char * argv[])
{
    
    cout << "Enter the number of students: ";
    int n;
    cin>>n;
    
    struct student arr[n];
    
    // inputting the data
    get_info(arr,n);
    
    // displaying the data
    display(arr, n);
    
    return 0;
}
