// Program to perform selection sort on an array of integers

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, i, j, m, s;
    int arr[100];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements in the array: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Unsorted array is : \n");
    for (i = 0; i < n; i++)
        printf("%d \t", arr[i]);
    printf("\n");

    for (i = 0; i < n - 1; i++)
    {
        m = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[m])
                m = j;
        }
        if (m != i)
        {
            s = arr[m];
            arr[m] = arr[i];
            arr[i] = s; 
        }
    }

    printf("Sorted array is : \n");
    for (i = 0; i < n; i++)
        printf("%d \t", arr[i]);
    printf("\n");

    return 0;
}
