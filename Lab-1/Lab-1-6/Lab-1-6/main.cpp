//
//  main.cpp
//  Lab-1-6
//
//  Created by Aaron R on 11/08/21.
//  Take a string as an argument and modifies the string so as to remove all consecutive duplicate characters, e.g. mississippi -> misisipi..

#include <iostream>
using namespace std;

void modify(char str1[], int &length)
{
    // To remove all consecutive duplicate characters
    for (int i=0; i<length-2; i++)
    {
        if (str1[i]==str1[i+1])
        {
            for (int j = i; j <length-1; ++j)
                str1[j] = str1[j + 1];
            length = length-1;
            str1[length] = '\0';
        }
    }
}

int main(int argc, const char * argv[])
{
    // inputting the string
    char str1[100];
    cout<<"Enter the string: ";
    cin>>str1;
    int length = (int)strlen(str1);
    
    // function call to remove consecutive duplicates
    modify(str1,length);
    
    // display modified string
    cout<<"New string: "<<str1<<endl;
    return 0;
}
