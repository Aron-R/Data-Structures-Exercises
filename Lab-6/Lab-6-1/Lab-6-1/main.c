//
//  main.c
//  Lab-6-1
//
//  Created by Aaron R on 01/10/21.
//

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Inputting n and using malloc to assign memory
    int n, *p, *rm_duplicates,counter=0;
    printf("Enter n: ");
    scanf("%d",&n);
    p = (int *) calloc(n, sizeof(int));
    rm_duplicates = (int *) malloc(n * sizeof(int));
    int zero_counter=0;
    
    
    // inputting the values for the array
    for (int i=0;i<n;i++)
    {
        printf("Enter the value %d of array",i+1);
        scanf("%d",(p+i));
    }
    
    
    // checking to see if there are duplicates
    for (int i=0; i<n; i++)
    {
        int condition = 0;
        for (int j=0; j<n; j++)
        {
            
            if (*(p+i) == *(rm_duplicates+j) && (*(p+i)!=0))
            {
                condition = 1;
                break;
                
            }
        }
        if (condition==0)
        {
            if (*(p+i)==0)
            {
                // error handling of 0's being in the inputted array
                if (zero_counter==0)
                {
                    zero_counter+=1;
                    *(rm_duplicates+counter) = *(p+i);
                    counter+=1;
                }
            }
            else
            {
                *(rm_duplicates+counter) = *(p+i);
                counter+=1;
            }
        }
        
    }
    
    if (counter!=n)
    {
        // reducing the size of rm_duplicates
        rm_duplicates = realloc(rm_duplicates, counter*sizeof(int));
    }
    

    int * indices;
    for (int i=0; i<counter; i++)
    {
        indices = (int *) malloc(n * sizeof(int));
        int duplicate_count = 0;
        for (int j=0; j<n; j++)
        {
            if (*(rm_duplicates+i)==*(p+j))
            {
                *(indices+duplicate_count) = j;
                duplicate_count+=1;
            }
        }
        if (duplicate_count!=1)
        {
            printf("%d ",*(rm_duplicates+i));
            for (int k=0; k<duplicate_count; k++)
                printf("%d ",*(indices+k));
            printf("\n");
        }
        
    }
    
    return 0;
}
