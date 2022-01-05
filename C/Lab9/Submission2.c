#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int numerator;
    int denominator;
} fraction;

void enterData();
void readData(fraction[], int *);
int gcd(int, int);
void simplify(fraction[], int, int[], int[]);
double sumFrac(fraction[], int);
void findMax(int[], int[], int, double *);
void listMax(double, fraction[], int);
void sortAsc(fraction[], int);
int main()
{
    int n;
    fraction frac[1000];
    int numera[1000];
    int denomi[1000];
    enterData();
    readData(frac, &n);
    simplify(frac, n, numera, denomi);
    printf("\nSum of fractions = %lf\n", sumFrac(frac, n));
    double largestFrac;
    findMax(numera, denomi, n, &largestFrac);
    listMax(largestFrac, frac, n);
    sortAsc(frac, n);
}

void enterData()
{
    FILE *finput = fopen("PS.txt", "w");
    int n;
    scanf("%d", &n);
    fprintf(finput, "%d\n", n);
    int i;
    char fraction[100];
    for (i = 0; i < n; i++)
    {
        scanf("%s", fraction);
        fprintf(finput, "%s\n",fraction);
    }
    fclose(finput);
}

void readData(fraction frac[], int *n)
{
    FILE *finput = fopen("PS.txt", "r");
    fscanf(finput, "%d", n);
    char line[1024];
    int row = 0;
    int col = 0;
    int index = 0;
    while (fgets(line, 1024, finput))
    {
        col = 0;
        row++;
        if (row == 1)
            continue;
        char *colValue = strtok(line, "/");
        while (colValue)
        {
            if (col == 0)
            {
                frac[index].numerator = atoi(colValue);
            }
            else if (col == 1)
            {
                frac[index].denominator = atoi(colValue);
            }
            colValue = strtok(NULL, "/");
            col++;
        }
        index++;
    }
    int i;
    for (i = 0; i < *n; i++)
    {
        printf("%d/%d ", frac[i].numerator, frac[i].denominator);
    }
    printf("\n");
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void simplify(fraction frac[], int n, int numera[], int denomi[])
{
    FILE *fout = fopen("PS1.txt", "w");
    int i;
    for (i = 0; i < n; i++)
    {
        int x = frac[i].numerator;
        int y = frac[i].denominator;
        numera[i] = x / gcd(x, y);
        denomi[i] = y / gcd(x, y);
    }
    for (i = 0; i < n; i++)
    {
        fprintf(fout, "%d/%d ", numera[i], denomi[i]);
    }
    fprintf(fout, "\n");
    fclose(fout);
}

double sumFrac(fraction frac[], int n)
{
    FILE *fout = fopen("PS1.txt", "a");
    int i;
    double sum = 0.0;
    for (i = 0; i < n; i++)
    {
        int x = frac[i].numerator;
        int y = frac[i].denominator;
        sum = sum + (double)x / y;
    }
    fprintf(fout, "Sum of fraction = %lf\n", sum);
    fclose(fout);
    return sum;
}

void findMax(int numera[], int denomi[], int n, double *largestFrac)
{
    FILE *fout = fopen("PS1.txt", "a");
    double max = ((double)numera[0]) / denomi[0];
    int maxNumera = numera[0];
    int maxDenomi = denomi[0];
    int i;
    for (i = 0; i < n; i++)
    {
        int x = numera[i];
        int y = denomi[i];
        double frac = (double)x / y;
        if (frac > max)
        {
            max = frac;
            maxNumera = x;
            maxDenomi = y;
        }
    }
    *largestFrac = max;
    fprintf(fout, "Largest fraction is %d/%d\n", maxNumera, maxDenomi);
    fclose(fout);
}

void listMax(double largestFrac, fraction frac[], int n)
{
    FILE *fout = fopen("PS1.txt", "a");
    int i;
    fprintf(fout, "Largest fraction(s) list: \n");
    for (i = 0; i < n; i++)
    {
        int x = frac[i].numerator;
        int y = frac[i].denominator;
        double fract = (double)x / y;
        if (fract == largestFrac)
        {
            fprintf(fout, "%d/%d ", frac[i].numerator, frac[i].denominator);
        }
    }
    fprintf(fout, "\n");
    fclose(fout);
}

void sortAsc(fraction frac[], int n)
{
    FILE *fout = fopen("PS1.txt", "a");
    int smallestIndex;
    int i;
    fraction temp;
    for (i = 0; i < n; i++)
    {
        int x = frac[i].numerator;
        int y = frac[i].denominator;
        double fract = (double)x / y;
        smallestIndex = i;
        int j;
        for (j = i + 1; j < n; j++)
        {
            int k = frac[j].numerator;
            int q = frac[j].denominator;
            double cmpfract = (double)k / q;
            if (cmpfract < fract)
            {
                smallestIndex = j;
            }
        }
        temp = frac[i];
        frac[i] = frac[smallestIndex];
        frac[smallestIndex] = temp;
    }
    for (i = 0; i < n; i++)
    {
        fprintf(fout, "%d/%d ", frac[i].numerator, frac[i].denominator);
    }
    fclose(fout);
}