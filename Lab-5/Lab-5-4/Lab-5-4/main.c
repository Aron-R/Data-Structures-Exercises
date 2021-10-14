//
//  main.c
//  Lab-5-4
//
//  Created by Aaron R on 26/09/21.
//

#include <stdio.h>
#include <stdlib.h>
 
int josephus(int n, int kill)
{
    int remainder = 0;
    for (int i = 1; i <= n; i++)
        remainder = (remainder + kill) % i;
    return remainder + 1;
}
 
int main()
{
    // Inputting data
    int n;
    scanf("%d",&n);
    int people[100];
    for (int i = 0; i < n ; i++)
        scanf("%d",&people[i]);
    
    // Deciding which position
    int k;
    scanf("%d",&k);
    printf("%d",people[josephus(n,k)-1]);
    return 0;
}
