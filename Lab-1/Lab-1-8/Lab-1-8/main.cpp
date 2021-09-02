//
//  main.cpp
//  Lab-1-8
//
//  Created by Aaron R on 11/08/21.
//  Get the details of a student and display them using structures.
//  i.e. Student name, roll no, marks, cgpa and date of birth.

#include <iostream>
using namespace std;

struct student
{
    string name;
    int roll,marks[3],dd,mm,yyyy;
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
        for (int j=0; j<3; j++)
        {
            cout<<"Enter marks of subject"<<j+1<<": ";
            cin>>arr[i].marks[j];
        }
        cout<<"Enter cgpa: ";
        cin>>arr[i].cgpa;
        
        cout<<"Enter day of birth: ";
        cin>>arr[i].dd;
        cout<<"Enter month of birth: ";
        cin>>arr[i].mm;
        cout<<"Enter year of birth: ";
        cin>>arr[i].yyyy;
        
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
        
        for (int j=0; j<3; j++)
            cout<<"Enter marks of subject"<<j+1<<": "<<arr[i].marks[j]<<endl;
        
        cout<<"cgpa: "<<arr[i].cgpa<<"\n";
        cout<<"Date of Birth: "<<arr[i].dd<<"/"<<arr[i].mm<<"/"<<arr[i].yyyy<<"\n\n";
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
