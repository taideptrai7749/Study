#include <stdio.h>
#include <math.h>

int findSmallest(int[], int);
void largestIndex(int[], int);
int sumOfThree(int[], int);
int isPrime(int);
void printPrime(int[], int);
int isSquareNum(int);
void printSquareNum(int[], int);

int main()
{
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    int arr[10000];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("%d is the smallest element in the array\n", findSmallest(arr, n));
    largestIndex(arr, n);
    printf("%d is the sum of all elements that are divisible by 3\n", sumOfThree(arr, n));
    printPrime(arr, n);
    printSquareNum(arr, n);
    return 0;
}

int findSmallest(int arr[], int n)
{
    int min = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= min)
        {
            min = arr[i];
        }
    }
    return min;
}

void largestIndex(int arr[], int n)
{
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= max)
        {
            max = arr[i];
        }
    }
    printf("Index of the largest element(s): ");
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == max)
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int sumOfThree(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 3 == 0)
        {
            sum = sum + arr[i];
        }
    }
    return sum;
}

int isPrime(int n)
{
    if (n < 2)
        return 0;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

void printPrime(int arr[], int n)
{
    printf("Prime elements: ");
    for (int i = 0; i < n; i++)
    {
        if (isPrime(arr[i]))
            printf("%d ", arr[i]);
    }
    printf("\n");
}

int isSquareNum(int n)
{
    int squareOfNum = sqrt(n);
    while (squareOfNum * squareOfNum <= n)
    {
        if (squareOfNum * squareOfNum == n)
        {
            return 1;
        }
        squareOfNum++;
    }
    return 0;
}

void printSquareNum(int arr[], int n)
{
    printf("Square numbers elements: ");
    for (int i = 0; i < n; i++)
    {
        if (isSquareNum(arr[i]))
            printf("%d ", arr[i]);
    }
    printf("\n");
}