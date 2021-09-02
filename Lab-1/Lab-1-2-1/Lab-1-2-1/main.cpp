//
//  main.cpp
//  Lab-1-2
//
//  Created by Aaron R on 06/08/21.
//

#include <iostream>
using namespace std;

// global arrays
char a[100];
char b[100];
char temp[100];

void copyA(int i, char ch)
{
    // function to copy elements into variable a
    a[i] = ch;
}
void copyB(int i, char ch)
{
    // function to copy elements into variable b
    b[i] = ch;
}

void copyT(int i,char ch)
{
    // function to copy elements into variable temp
    temp[i] = ch;
}

int main(int argc, const char * argv[])
{
    // inputting the two strings
    cout<<"Enter a: ";
    cin>>a;
    cout<<"Enter b: ";
    cin>>b;
    
    // display a and b
    cout<<"a: "<<a<<endl;
    cout<<"b: "<<b<<endl;
    
    // copying a to temp
    for (int i=0; i<strlen(a); i++)
        copyT(i, a[i]);
    
    // swapping
    if (strlen(a)>strlen(b))
    {
        for (int i=0; i<strlen(a); i++)
            copyA(i, b[i]);
        
        for (int i=0; i<strlen(temp); i++)
            copyB(i, temp[i]);
    }
    
    else
    {
        for (int i=0; i<strlen(b); i++)
            copyA(i,b[i]);
        for (int i=0; i<strlen(b); i++)
            copyB(i, temp[i]);
    }
    
    cout<<"\nAfter swapping..\n";
    // displaying a and b
    cout<<"a: "<<a<<endl;
    cout<<"b: "<<b<<endl;
    
    return 0;
}
