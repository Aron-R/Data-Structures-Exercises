//
//  main.c
//  Lab-3-6
//
//  Created by Aaron R on 03/09/21.
//  Write a program to convert any given Infix expression to a prefix form.
//  Example:
//  Infix: A * (B + C) * D
//  Prefix: **A+BCD

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int top = -1;
void push(char x,char stack[])
{
    
    if (top==100-1)
        printf("Overflow\n");
    else
    {
        top++;
        stack[top] = x;
    }
}

char pop(char stack[])
{
    char item;
    if (top==-1) {
        printf("Underflow\n");
        exit(0);
    }
    else
    {
        item = stack[top];
        top--;
        printf("popped: %c\n",item);
        return item;
    }
    
}

int precedence(char op)
{
    //To check the precedence
    
    char operators[7] = {'^', '*', '/', '+', '-'};
    int p=0;
    for(int i = 0; i<7; i++)
    {
        if(op == operators[i])
        {
            p = i+1;
        }
    }
    
    if (p==1)
        return 3;
    else if (p==2||p==3)
        return 2;
    else if (p==4||p==5)
        return 1;
    return 0;
}

void reverse(char exp[], char reverse[])
{
    // To reverse string
    
    int revExpLen = 0;
    for(int i=(int)strlen(exp)-1; i>=0; i--)
    {
        if(exp[i]=='(')
        {
            reverse[revExpLen] = ')';
            reverse++;
        }
        else if(exp[i]==')')
        {
            reverse[revExpLen] = '(';
            revExpLen++;
        }
        else
        {
            reverse[revExpLen] = exp[i];
            revExpLen+=1;
        }
    }
}

void InfixToPrefix(char string[], char stack[], char prefix[], char temp1[], char result[])
{
    
    // To convert infix to prefix
    
    reverse(string, temp1);
    
    int prefixLen = 0;
    int top = 0;
    for(int i = 0; i<strlen(temp1); i++)
    {
        
        if(((int)temp1[i]>=65 && (int)temp1[i]<=122) || ((int)temp1[i]>=48 && (int)temp1[i]<=57))
        {
            prefix[prefixLen] = temp1[i];
            prefixLen += 1;
        }
        else
        {
            if(temp1[i] == '(')
            {
                top+=1;
                stack[top-1] = temp1[i];
                stack[top] = '\0';
            }
            else{
                if(top != 0 && temp1[i]!=')' && temp1[i]!='(' && stack[top-1]!='('){
                                        if(precedence(temp1[i])>precedence(stack[top-1]))
                    {
                        top++;
                        stack[top-1] = temp1[i];
                    }
                    
                    else if (precedence(temp1[i])<=precedence(stack[top-1]))
                    {
                        
                        while((precedence(stack[top-1])>=precedence(temp1[i]) || temp1[i]!='(')&&top>0&&stack[top-1]!=temp1[i])
                        {
                            prefixLen += 1;
                            prefix[prefixLen-1] = stack[top-1];
                            stack[top-1] = '\0';
                            top -= 1;
                        }
                    
                        stack[top] = temp1[i];
                    }
                }
                else if(top == 0 && temp1[i]!=')'){
                    stack[top] = temp1[i];
                    top+=1;
                }
                
                
                else if(top != 0 && temp1[i]==')'){
                    while(stack[top-1]!='('){
                        prefixLen+=1;
                        prefix[prefixLen-1] = stack[top-1];
                        stack[top-1] = '\0';
                        top-=1;
                    }
                    stack[top-1] = '\0';
                    top-=1;
                }
                else{
                    top+=1;
                    stack[top-1] = temp1[i];
                }
            }
        }
    }
    
    if(top!=0)
    {
        while(top>=0)
        {
            prefixLen += 1;
            prefix[prefixLen-1] = stack[top];
            stack[top] = '\0';
            top -= 1;
        }
    }
    else
    {
        prefixLen += 1;
        prefix[prefixLen-1] = stack[top];
        stack[top] = '\0';
        top -= 1;
    }

    reverse(prefix, result);
}

int main()
{
    char string[50], stack[50], prefix[50], temp1[50], result[50];
    printf("Enter the infix expression: ");
    scanf("%[^\n]", string);
    
    InfixToPrefix(string, stack, prefix, temp1, result);
    printf("Prefix Expression: %s\n", result);
}
