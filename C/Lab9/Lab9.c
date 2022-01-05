#include <stdio.h>
#include <string.h>

void inputFile(char[], int[], int *);
void sumFile(char[], int[], int);
void newInput(char[], char[]);
int countLines(char[]);
void searchProgram();
void sortArray(int[], int);
int binarySearch(int[], int, int);
int linearSearch(int[], int, int);

int main()
{
    int n;
    int arr[10000];
    inputFile("input01.txt", arr, &n);
    sumFile("output01.txt", arr, n);
    newInput("input02.txt", "output02.txt");
    searchProgram();
}

void searchProgram()
{
    char fileName[100];
    printf("Enter a file name: ");
    gets(fileName);
    FILE *finput = fopen(fileName, "r");
    int func;
    printf("1. Linear search\n2.Binary search\nChoose one of these algorithms: ");
    scanf("%d", &func);
    while (func != 1 && func != 2)
    {
        printf("Wrong input, try again: ");
        scanf("%d", &func);
    }
    int n;
    printf("Enter a number to search for: ");
    scanf("%d", &n);
    int arr[1000];
    int size;
    fscanf(finput, "%d", &size);
    int i;
    for (i = 0; i < size; i++)
    {
        fscanf(finput, "%d", &arr[i]);
    }
    if (func == 1)
    {
        int pos = linearSearch(arr, size, n);
        if (pos == -1)
        {
            printf("not found");
        }
        else
        {
            printf("%d", pos);
        }
    }
    else
    {
        printf("Sorted array: \n");
        sortArray(arr, size);
        for (i = 0; i < size; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
        int pos = binarySearch(arr, size, n);
        if (pos == -1)
        {
            printf("not found");
        }
        else
        {
            printf("%d", pos);
        }
    }
}

void sortArray(int arr[], int n)
{
    int i;
    int smallestIndex;
    for (i = 0; i < n - 1; i++)
    {
        smallestIndex = i;
        int j;
        for (j = i + 1; j < n; j++)
        {
            if (arr[smallestIndex] > arr[j])
            {
                smallestIndex = j;
            }
        }
        int temp = arr[smallestIndex];
        arr[smallestIndex] = arr[i];
        arr[i] = temp;
    }
}

int binarySearch(int arr[], int n, int k)
{
    int end = n - 1;
    int start = 0;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == k)
            return mid;
        else if (arr[mid] > k)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}

int linearSearch(int arr[], int n, int k)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == k)
        {
            return i;
        }
    }
    return -1;
}

void inputFile(char input[], int arr[], int *n)
{
    FILE *inputf = fopen(input, "r");
    fscanf(inputf, "%d", n);
    int i;
    for (i = 0; i < *n; i++)
    {
        fscanf(inputf, "%d", &arr[i]);
    }
    fclose(inputf);
}

void sumFile(char output[], int arr[], int n)
{
    FILE *outputf = fopen(output, "w");
    int sum = 0;
    int i;
    for (i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    fprintf(outputf, "%d", sum);
    fclose(outputf);
}

void newInput(char input[], char output[])
{
    FILE *finput = fopen(input, "r");
    FILE *foutput = fopen(output, "w");
    int line = countLines(input);
    int i = 0;
    char str[1000];
    while (!feof(finput))
    {
        fgets(str, 1000, finput);
        if (i != line - 1)
        {
            str[strlen(str) - 2] = '\0';
        }
        fprintf(foutput, "%d\n", strlen(str));
        i++;
    }
    fclose(finput);
    fclose(foutput);
}

int countLines(char input[])
{
    FILE *finput = fopen(input, "r");
    int count = 0;
    while (!feof(finput))
    {
        char c = fgetc(finput);
        if (c == '\n' || c == EOF)
        {
            count++;
        }
    }
    fclose(finput);
    return count;
}