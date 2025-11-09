#include <stdio.h>

void main()
{
    int n, a[100], i, even = 0, odd = 0;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter the element %d: ", i+1);
        scanf("%d", &a[i]);
    }

    printf("\nThe array: ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    for(i = 0; i < n; i++)
    {
        if(i % 2 == 0)
        {
            even = even + a[i];
        }
        if(i % 2 != 0)
        {
            odd = odd + a[i];
        }
    }

    printf("\nThe sum of even index elements is %d", even);
    printf("\nThe sum of odd index elements is %d", odd);
}