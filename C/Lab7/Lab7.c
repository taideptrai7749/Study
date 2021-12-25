#include <stdio.h>

int linearSearch(int[], int, int);
int binarySearch(int[], int, int);
void printArray(int[], int);
void selectionSort1(int[], int);
void selectionSort2(int[], int);
void bubbleSort1(int[], int);
void bubbleSort2(int[], int);
int main()
{
    int arr[5] = {5, 4, 6, 8, 3};
    printf("%d\n", linearSearch(arr, 3, 5));
    int arr2[5] = {4, 7, 8, 11, 12};
    printf("%d\n", binarySearch(arr2, 7, 5));
    int arr3[6] = {3, 1, 5, 4, 2, 8};
    printArray(arr3, 6);
    selectionSort1(arr3, 6);
    printArray(arr3, 6);
    int arr4[6] = {3, 5, 1, 6, 8, 2};
    printArray(arr4, 6);
    selectionSort2(arr4, 6);
    printArray(arr4, 6);
    int arr5[6] = {6, 5, 7, 2, 9, 1};
    printArray(arr5, 6);
    bubbleSort1(arr5, 6);
    printArray(arr5, 6);
    int arr6[6] = {3, 2, 1, 8, 7, 4};
    printArray(arr6, 6);
    bubbleSort2(arr6, 6);
    printArray(arr6, 6);
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int linearSearch(int arr[], int k, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == k)
            return i;
    }
    return -1;
}

int binarySearch(int arr[], int k, int n)
{
    int start = 0;
    int end = n - 1;
    int mid = (start + end) / 2;
    while (start <= end)
    {
        if (arr[mid] == k)
            return mid;
        else if (arr[mid] > k)
        {
            end = mid - 1;
        }
        else
            start = mid + 1;

        mid = (start + end) / 2;
    }
    return -1;
}

void selectionSort1(int arr[], int n)
{
    int i;
    int smallestIndex;
    int j;
    for (i = 0; i < n - 1; i++)
    {
        smallestIndex = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[smallestIndex] > arr[j])
            {
                smallestIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[smallestIndex];
        arr[smallestIndex] = temp;
    }
}

void selectionSort2(int arr[], int n)
{
    int i;
    int largerIndex;
    int j;
    for (i = n - 1; i >= 0; i--)
    {
        largerIndex = i;
        for (j = i - 1; j >= 0; j--)
        {
            if (arr[largerIndex] < arr[j])
            {
                largerIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[largerIndex];
        arr[largerIndex] = temp;
    }
}

void bubbleSort1(int arr[], int n)
{
    int i;
    int j;
    for (i = n-1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void bubbleSort2(int arr[], int n)
{
    int i;
    int j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = n - 1; j > 0; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
}
