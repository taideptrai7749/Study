#include <stdio.h>

int main()
{
    int n;
    int arr[100];
    FILE *openfile;
    openfile = fopen("input.txt", "r");
    fscanf(openfile, "%d", &n);
    int i;
    for (i = 0; i < n; i++)
    {
        fscanf(openfile, "%d", &arr[i]);
    }
    fclose(openfile);
    FILE *endfile;
    endfile = fopen("output.txt", "w");
    for (i = 0; i < n; i++)
    {
        fprintf(endfile, "Element number %d: %d\n", i + 1, arr[i]);
    }
    fclose(endfile);
    return 0;
}