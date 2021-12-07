#include <stdio.h>

int positive_element(int, int[]);

int main()
{
    int n;
    scanf("%d", &n);
    int arr[10000];
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("The number of positive elements is %d", positive_element(n, arr));
}

int positive_element(int n, int arr[])
{
    if (n == 0)
        return 0;
    if (arr[n - 1] > 0)
    {
        return 1 + positive_element(n - 1, arr);
    }
    else
        return positive_element(n - 1, arr);
}