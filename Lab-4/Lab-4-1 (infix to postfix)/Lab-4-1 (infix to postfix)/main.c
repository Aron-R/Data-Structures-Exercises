//
//  main.c
//  Lab-4-1 (infix to postfix)
//
//  Created by Aaron R on 03/09/21.
//

#include<stdio.h>
#include<stdlib.h>

char op[50];

struct node
{
    char data;
    struct node *next;
} *l1=NULL;

void push(char x)         // pushes char into the linkedlist
{
    if(l1==NULL)
    {
        l1=(struct node *)malloc(sizeof(struct node));
        l1->data=x;
        l1->next=NULL;
    }
    else
    {
        struct node *p;
        p=(struct node *)malloc(sizeof(struct node));
        p->data=x;
        p->next=l1;
        l1=p;
    }
}

char pop()           // pops char outof linkedlist
{
    char c;
    struct node *p;
    if (l1==NULL)
    {
        printf("the stack is empty\n");
        // exit(1);
    }
    else
    {
        c=l1->data;
        p=l1->next;
        free (l1);
        l1=p;
    }
    return c;
}

void display(struct node *start)
{
    {
        //int i=0;
        struct node *p;
        p=start;
        if(p==NULL)
            printf("Empty list");
        else
        {
            while(p!=NULL)
            {
                printf("%c->",p->data);
                p=p->next;
            }
            printf("NULL\n");
        }
    }
}


int prior(char s, char c)
{
    if ( (c=='^' && s=='+') || s=='-' ||s=='/' || s=='*')
        return 1;
    else if( c=='*' || c=='/')
    {
        if(s=='+' || s=='-' )
            return 1;
        else
            return 0;
    }
    else if( c=='+' || c=='-' )
        return 0;
  return -1;
}

void cnvrt(char s[], int n)       // convert infix to postfix
{
    //char g;
    int i,j;//,x;
    for(i=0,j=0;i<n;i++)
    {

        if ((s[i]>='0'&&s[i]<='9') || (s[i]>='a' && s[i]<='z')|| (s[i]>='A' && s[i]<='Z'))
        {
            op[j]=s[i];
            j++;
        }
        else if(s[i]=='(')
        {
            push(s[i]);
        }
        else if (s[i]=='+' || s[i]=='/' || s[i]=='-' || s[i]=='*' || s[i]=='^')
        {

            if( l1==NULL)
                push(s[i]);
            else if(l1->data=='(')
                push(s[i]);
            else if(prior(l1->data, s[i] )!=1)
                push(s[i]);
            else
            { op[j]=pop();
                j++;
                push(s[i]);
            }
        }
        else if(s[i]==')')
        {
            while(l1!=NULL && l1->data!='(')
            {
                op[j]=pop();
                j++;
            }
            pop();
        }
    }
    while(l1!=NULL)
    {
        op[j]=pop();
        j++;
    }
}


int main()
{
    int i,n;
    char c[50];
    printf(" enter the no of characters in infix string\n ");
    scanf("%d",&n);
    fflush(stdin);
    printf(" enter the infix string\n");
    scanf("%[^\n]",c);

    cnvrt(c,n);
    printf("the postfix string is \n");
    for(i=0;i<n;i++)
    {
        printf("%c",op[i]);
    }
    return 0;
}
