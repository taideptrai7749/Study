#include <stdio.h>

void printArray(int[], int);
int comparisionCount(int[], int, int);
int binaryCount(int[], int, int);
void selectionSort1(int[], int);
void selectionSort2(int[], int);
void bubbleSort1(int[], int);
void bubbleSort2(int[], int);
int main()
{
    int arr1[5] = {3, 4, 2, 5, 7};
    printArray(arr1, 5);
    printf("The number of comparision needed to find 8 in the array 1 is: %d\n", comparisionCount(arr1, 5, 8));
    int arr2[5] = {8, 4, 2, 1, 0};
    printArray(arr2, 5);
    printf("The number of comparision needed to find 1 in the array 2 with the binary method is: %d\n", binaryCount(arr2, 5, 1));
    int arr3[5] = {7, 8, 5, 6, 9};
    printArray(arr3, 5);
    selectionSort1(arr3, 5);
    int arr4[6] = {3, 5, 7, 2, 1, 4};
    printArray(arr4, 6);
    selectionSort2(arr4, 6);
    int arr5[5] = {4, 3, 6, 1, 5};
    printArray(arr5, 5);
    bubbleSort1(arr5, 5);
    int arr6[5] = {3, 4, 2, 6, 1};
    printArray(arr6, 5);
    bubbleSort2(arr6, 5);
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

int comparisionCount(int arr[], int n, int k)
{
    int count = 0;
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == k)
        {
            count++;
            return count;
        }
        count++;
    }
    return count;
}

int binaryCount(int arr[], int n, int k)
{
    int start = 0;
    int end = n - 1;
    int mid = (start + end) / 2;
    int count = 0;
    while (start <= end)
    {
        if (arr[mid] == k)
        {
            count++;
            return count;
        }
        else if (arr[mid] > k)
        {
            start = mid + 1;
            count++;
        }
        else
        {
            end = mid - 1;
            count++;
        }
        mid = (start + end) / 2;
    }
    return count;
}

void selectionSort1(int arr[], int n)
{
    int i;
    int j;
    int k = 1;
    int q;
    int smallestIndex;
    for (i = n - 1; i > 0; i--)
    {
        smallestIndex = i;
        for (j = i - 1; j >= 0; j--)
        {
            if (arr[j] < arr[smallestIndex])
            {
                smallestIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[smallestIndex];
        arr[smallestIndex] = temp;
        printf("Step %d : ", k);
        for (q = 0; q < n; q++)
        {
            printf("%d ", arr[q]);
        }
        k++;
        printf("\n");
    }
}

void selectionSort2(int arr[], int n)
{
    int i;
    int j;
    int k = 1;
    int q;
    int largestIndex;
    for (i = 0; i < n - 1; i++)
    {
        largestIndex = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[largestIndex])
            {
                largestIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[largestIndex];
        arr[largestIndex] = temp;
        printf("Step %d : ", k);
        for (q = 0; q < n; q++)
        {
            printf("%d ", arr[q]);
        }
        k++;
        printf("\n");
    }
}

void bubbleSort1(int arr[], int n)
{
    int i;
    int k = 1;
    int j;
    int q;
    for (i = n-1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        printf("Step %d: ", k);
        for (q = 0; q < n; q++)
        {
            printf("%d ", arr[q]);
        }
        k++;
        printf("\n");
    }
}

void bubbleSort2(int arr[], int n)
{
    int i;
    int j;
    int k = 1;
    int q;
    for (i = n-1; i > 0; i--)
    {
        for (j = i; j > 0; j--)
        {
            if (arr[j] > arr[j - 1])
            {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
        printf("Step %d: ", k);
        for (q = 0; q < n; q++)
        {
            printf("%d ", arr[q]);
        }
        k++;
        printf("\n");
    }
}