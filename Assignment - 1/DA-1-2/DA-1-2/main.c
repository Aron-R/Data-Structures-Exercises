//
//  main.c
//  DA-1-2
//
//  Created by Aaron R on 23/09/21.
//  Assume you are preparing a coin price calculating machine. Prepare an Algorithm for calculating the total price of given coins (#Coins = n) of different Values (1 Rupee, 2 Rupee, 5 Rupee and 10 Rupee)). And compute the time and space complexity of your algorithm
//  Ex- For coin price 30 how many coins of each of the above are needed considering the constraint that minimum number of coins are used.

#include <stdio.h>

int main(int argc, const char * argv[])
{
    int price;
    printf("Enter the coin price: ");
    scanf("%d",&price);
    
    int temp_price = price;
    int count[]={0,0,0,0};
    
    while (temp_price!=0)
    {
        if (10<=temp_price)
        {
            count[3]+=1;
            temp_price -= 10;
        }
        else if (5<=temp_price)
        {
            count[2]+=1;
            temp_price -= 5;
        }
        else if (2<=temp_price)
        {
            count[1]+=1;
            temp_price -=2;
        }
        else if (1<=temp_price)
        {
            count[0]+=1;
            temp_price -=1;
        }
        
    }
    printf("\n#### Distribution #### \n1 Rupee coin(s): %d\n2 Rupee coin(s): %d\n5 Rupee coin(s): %d\n10 Rupee coin(s): %d\n-------------------------\n",count[0],count[1],count[2],count[3]);
    
    printf("Minimum number of coins needed: %d\n",count[0]+count[1]+count[2]+count[3]);
    return 0;
}
