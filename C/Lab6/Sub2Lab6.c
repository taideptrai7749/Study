#include <stdio.h>
#include <math.h>

int isPrime(int, int);
int powerOf(int);
int countDigits(int);
double questionB(int, int);
double questionD(int, int);
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
    printf("2 to the power of %d = %d\n", n, powerOf(n));

    printf("Enter a positive number (larger than 0): ");
    int number;
    scanf("%d", &number);
    printf("%d is the number of digits of %d\n", countDigits(number), number);

    int num;
    printf("Enter number for question 6: ");
    scanf("%d", &num);
    printf("b/ S = %f\n", questionB(num, 1));
    printf("d/ S = %f\n", questionD(num, 1));
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

int powerOf(int n)
{
    if (n == 0)
        return 1;
    return 2 * powerOf(n - 1);
}

int countDigits(int number)
{
    if (number == 0)
        return 0;
    return 1 + countDigits(number / 10);
}

double questionB(int num, int i)
{
    if (i == num)
        return i / 2.0;
    return (i / 2.0) + questionB(num, i + 1);
}

double questionD(int num, int i)
{
    if (i == num)
        return sqrt(i);
    return sqrt(i) + questionD(num, i + 1);
}
