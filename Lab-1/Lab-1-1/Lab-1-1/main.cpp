//
//  main.cpp
//  Lab-1-1
//
//  Created by Aaron R on 06/08/21.
//  Find a to the power b using function.

#include <iostream>
using namespace std;

long int power(int a, int b)
{
    // calculating a^b
    long int result = 1;
    for(int i=1;i<=b;i++)
        result*=a;
    return result;
}
int main(int argc, const char * argv[])
{
    // inputting a
    cout<<"Input a: ";
    int a;
    cin>>a;
    
    // inputting b
    cout<<"Input b: ";
    int b;
    cin>>b;
    
    // displaying result
    cout<<"a^b = "<<power(a,b)<<endl;
    
    return 0;
}
