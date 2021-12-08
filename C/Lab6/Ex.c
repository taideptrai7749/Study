#include <stdio.h>
#include <math.h>

int isPrime(int, int);
int factorial(int);
int powerOf(int);
int xPowerOf(int, int);
int countDigits(int);
int questionA(int, int);
double questionB(int, int);
int questionC(int, int);
double questionD(int, int);
int questionE(int, int);
int main()
{
    int n;
    scanf("%d", &n);
    if (isPrime(n, 2))
    {
        printf("This is a prime number\n");
    }
    else
    {
        printf("This is not a prime number\n");
    }
    printf("Factorial = %d\n", factorial(n));
    printf("2 to the power of %d = %d\n", n, powerOf(n));
    int x;
    printf("Enter x: ");
    scanf("%d", &x);
    printf("%d to the power of %d = %d\n", x, n, xPowerOf(x, n));
    printf("Enter a positive number (larger than 0): ");
    int number;
    scanf("%d", &number);
    printf("%d is the number of digits of %d\n", countDigits(number), number);
    int num;
    printf("Enter number for question 6: ");
    scanf("%d", &num);
    printf("a/ S = %d\n", questionA(num, 1));
    printf("b/ S = %f\n", questionB(num, 1));
    printf("c/ S = %d\n", questionC(num, 1));
    printf("d/ S = %f\n", questionD(num, 1));
    printf("e/ S = %d\n", questionE(num, 1));
}

int isPrime(int n, int i)
{
    if (n < 2)
        return 0;
    if (n == 2)
        return 1;
    if (i >= n)
        return 1;
    if (n % i == 0)
        return 0;
    return isPrime(n, i + 1);
}

int factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

int powerOf(int n)
{
    if (n == 0)
        return 1;
    return 2 * powerOf(n - 1);
}

int xPowerOf(int x, int n)
{
    if (n == 0)
        return 1;
    return x * xPowerOf(x, n - 1);
}

int countDigits(int number)
{
    if (number == 0)
        return 0;
    return 1 + countDigits(number / 10);
}

int questionA(int num, int i)
{
    if (i == num)
        return (2 * i + 1);
    return (2 * i + 1) + questionA(num, i + 1);
}

double questionB(int num, int i)
{
    if (i == num)
        return i / 2.0;
    return (i / 2.0) + questionB(num, i + 1);
}

int questionC(int num, int i)
{
    if (i == num)
        return factorial(i);
    return factorial(i) + questionC(num, i + 1);
}

double questionD(int num, int i)
{
    if (i == num)
        return sqrt(i);
    return sqrt(i) + questionD(num, i + 1);
}

int questionE(int num, int i)
{
    if (i == num)
        return factorial(i);
    return factorial(i) * questionE(num, i + 1);
}