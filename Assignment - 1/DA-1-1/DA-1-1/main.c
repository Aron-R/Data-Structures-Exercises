//s
//  main.c
//  DA-1-1
//
//  Created by Aaron R on 23/09/21.
//  Given two strings, return whether the first string is a subsequence of the second. For example, given tar and metaphor, you should return  true, given col and lockdown, you should return false.

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_subsequence(char str1[], char str2[])
{
    int temp_condition = 0;
    int j=0;
    
    for (int i=0; i<strlen(str1); i++)
        for (; j<strlen(str2); j++)
            if (str1[i]==str2[j])
            {
                temp_condition += 1;
                break;
                
            }
    
    if (temp_condition==strlen(str1))
        return true;
    else
        return false;
    
}

int main(int argc, const char * argv[])
{
    printf("Enter the first string: ");
    char str1[100];
    scanf("%[^\n]",str1);
    fflush(stdin);
    printf("Enter second string: ");
    char str2[100];
    scanf("%[^\n]",str2);
    
    if(is_subsequence(str1, str2))
        printf("The first string IS a subsequence of the second string\n");
    else
        printf("The first string is NOT a subsequence of the second string\n");
    return 0;
}
