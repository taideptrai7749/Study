#include <stdio.h>

void bubbleSort(int[], int);
void selectionSort(int[], int);
int find(int, int[], int);
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
    bubbleSort(arr, n);
    int size;
    scanf("%d", &size);
    int a[10000];
    for (i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }
    selectionSort(a, size);
    int newSize;
    scanf("%d", &newSize);
    int b[10000];
    for (i = 0; i < newSize; i++)
    {
        scanf("%d", &b[i]);
    }
    int k;
    scanf("%d", &k);
    selectionSort(b, newSize);
    printf("%d", find(newSize, b, k));
}

void bubbleSort(int arr[], int n)
{
    int i;
    int sortTime;
    for (sortTime = n - 1; sortTime > 0; sortTime--)
    {
        for (i = 0; i < sortTime; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int a[], int size)
{
    int i;
    int smallestIndex;
    for (i = 0; i < size; i++)
    {
        smallestIndex = i;
        int j;
        for (j = i + 1; j < size; j++)
        {
            if (a[j] < a[smallestIndex])
                smallestIndex = j;
        }
        int temp = a[i];
        a[i] = a[smallestIndex];
        a[smallestIndex] = temp;
    }
    for (i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int find(int n, int b[], int k)
{
    int start = 0;
    int end = n - 1;
    int middle = (start + end) / 2;
    while (start <= end)
    {
        if (k == b[middle])
            return middle;
        else if (k > b[middle])
            start = middle + 1;
        else
            end = middle - 1;
        middle = (start + end) / 2;
    }
    return -1;
}