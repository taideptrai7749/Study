#include <stdio.h>
#include <math.h>

int factorial(int);
int xPowerOf(int, int);
int questionA(int, int);
int questionC(int, int);
int questionE(int, int);
int main()
{
    int n;
    scanf("%d", &n);
    printf("Factorial = %d\n", factorial(n));
    int x;
    printf("Enter x: ");
    scanf("%d", &x);
    printf("%d to the power of %d = %d\n", x, n, xPowerOf(x, n));
    printf("Enter a positive number (larger than 0): ");
    int num;
    printf("Enter number for question 6: ");
    scanf("%d", &num);
    printf("a/ S = %d\n", questionA(num, 1));
    printf("c/ S = %d\n", questionC(num, 1));
    printf("e/ S = %d\n", questionE(num, 1));
}

int factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

int xPowerOf(int x, int n)
{
    if (n == 0)
        return 1;
    return x * xPowerOf(x, n - 1);
}

int questionA(int num, int i)
{
    if (i == num)
        return (2 * i + 1);
    return (2 * i + 1) + questionA(num, i + 1);
}

int questionC(int num, int i)
{
    if (i == num)
        return factorial(i);
    return factorial(i) + questionC(num, i + 1);
}

int questionE(int num, int i)
{
    if (i == num)
        return factorial(i);
    return factorial(i) * questionE(num, i + 1);
}