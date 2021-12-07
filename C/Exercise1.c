#include <stdio.h>

int main()
{
    int n;
    printf("Nhap so n: ");
    scanf("%d", &n);
    if (n % 16 == 0)
    {
        n = n + 18;
        printf("%d", n);
    }
    else
    {
        n = n / 2;
        n = n + 9;
        printf("%d", n);
    }
    return 0;
}