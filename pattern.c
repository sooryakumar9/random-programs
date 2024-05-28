#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int i,j,s,k;
    for(i = 0;i <= 5;i++)
    {
        for(k = 0;k <= 5-i;k++)
            printf(" ");
        for(j = i;j >= 0;j--)
        {
            printf("* ");
        }
        printf("\n");
    }
    for(i = 4;i >= 0;i--)
    {
        for(k = 5;k >= i;k--)
            printf(" ");
        for(j = i;j >= 0;j--)
        {
            printf("* ");
        }
        printf("\n");
    }
}