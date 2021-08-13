//
//  main.cpp
//  Lab-1-2-2

//  Swap strings using call by reference
//  Created by Aaron R on 08/08/21.
//

#include <iostream>
using namespace std;

void swap(string * ptra, string * ptrb)
{
    // function to swap using call by reference
    string * temp;
    temp = ptra;
    *ptra = *ptrb;
    *ptrb = *temp;
}

int main(int argc, const char * argv[])
{
    // inputting strings a and b
    string a,b;
    cout<<"Enter a: ";
    cin>>a;
    cout<<"Enter b: ";
    cin>>b;
    
    // display values in a and b
    cout<<"a: "<<a<<endl<<"b: "<<b<<endl;
    
    // function call
    swap(a, b);
    
    // display values in a and b
    cout<<"a: "<<a<<endl<<"b: "<<b<<endl;
    return 0;
}
