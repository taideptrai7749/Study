#include <stdio.h>
#include <string.h>

struct Employee
{
    char id[100], name[100], sex[10], phoneNumber[12];
    int birthYear, salary;
};
void input(struct Employee[], int *);
void output(struct Employee[], int);
void find(struct Employee[], char[], int);
void countSex(struct Employee[], int);
void sortBirthYear(struct Employee[], int);
void sortSalary(struct Employee[], int);
void findMax(struct Employee[], int);
void findYoungest(struct Employee[], int);
void delEmployee(struct Employee[], char[], int *);
int main()
{
    struct Employee employees[10];
    int n;
    input(employees, &n);
    output(employees, n);
    find(employees, "33", n);
    countSex(employees, n);
    sortBirthYear(employees, n);
    sortSalary(employees, n);
    findMax(employees, n);
    findYoungest(employees, n);
    delEmployee(employees, "34", &n);
    output(employees, n);
}

void input(struct Employee employees[], int *n)
{
    scanf("%d", n);
    int i;
    for (i = 0; i < *n; i++)
    {
        gets(employees[i].id);
        gets(employees[i].id);
        gets(employees[i].name);
        gets(employees[i].sex);
        gets(employees[i].phoneNumber);
        scanf("%d%d", &employees[i].birthYear, &employees[i].salary);
    }
}

void output(struct Employee employees[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%s\t%s\t%s\t%s\t%d\t%d\n", employees[i].id, employees[i].name, employees[i].sex, employees[i].phoneNumber, employees[i].birthYear, employees[i].salary);
    }
}

void find(struct Employee employees[], char id[], int n)
{
    int i;
    printf("Employee with id %s: ", id);
    for (i = 0; i < n; i++)
    {
        if (!strcmp(id, employees[i].id))
        {
            printf("%s\t%s\t%s\t%s\t%d\t%d\n", employees[i].id, employees[i].name, employees[i].sex, employees[i].phoneNumber, employees[i].birthYear, employees[i].salary);
            break;
        }
    }
}

void countSex(struct Employee employees[], int n)
{
    int countMale = 0;
    int countFemale = 0;
    int i;
    for (i = 0; i < n; i++)
    {
        if (!strcmp("Male", employees[i].sex))
        {
            countMale++;
        }
        else if (!strcmp("Female", employees[i].sex))
        {
            countFemale++;
        }
    }
    printf("Number of male: %d\nNumber of female: %d\n", countMale, countFemale);
}

void sortBirthYear(struct Employee em[], int n)
{
    int i;
    struct Employee temp;
    for (i = 0; i < n - 1; i++)
    {
        int smallestIndex = i;
        int j;
        for (j = i + 1; j < n; j++)
        {
            if (em[smallestIndex].birthYear > em[j].birthYear)
            {
                smallestIndex = j;
            }
        }
        temp = em[smallestIndex];
        em[smallestIndex] = em[i];
        em[i] = temp;
    }
    output(em, n);
}

void sortSalary(struct Employee em[], int n)
{
    int i;
    struct Employee temp;
    for (i = 0; i < n - 1; i++)
    {
        int smallestIndex = i;
        int j;
        for (j = i + 1; j < n; j++)
        {
            if (em[smallestIndex].salary > em[j].salary)
            {
                smallestIndex = j;
            }
        }
        temp = em[i];
        em[i] = em[smallestIndex];
        em[smallestIndex] = temp;
    }
    output(em, n);
}

void findMax(struct Employee em[], int n)
{
    int maxSalary = em[0].salary;
    int i;
    for (i = 1; i < n; i++)
    {
        if (maxSalary < em[i].salary)
            maxSalary = em[i].salary;
    }
    for (i = 0; i < n; i++)
    {
        if (em[i].salary == maxSalary)
        {
            printf("%s\t%s\t%s\t%s\t%d\t%d\n", em[i].id, em[i].name, em[i].sex, em[i].phoneNumber, em[i].birthYear, em[i].salary);
        }
    }
}

void findYoungest(struct Employee em[], int n)
{
    int youngest = em[0].birthYear;
    int i;
    for (i = 1; i < n; i++)
    {
        if (em[i].birthYear > youngest)
        {
            youngest = em[i].birthYear;
        }
    }
    for (i = 0; i < n; i++)
    {
        if (em[i].birthYear == youngest)
        {
            printf("%s\t%s\t%s\t%s\t%d\t%d\n", em[i].id, em[i].name, em[i].sex, em[i].phoneNumber, em[i].birthYear, em[i].salary);
        }
    }
}

void delEmployee(struct Employee em[], char id[], int *n)
{
    int i;
    for (i = 0; i < *n; i++)
    {
        if (!strcmp(id, em[i].id))
        {
            int j;
            for (j = i; j < *n - 1; j++)
            {
                em[j] = em[j + 1];
            }
            *n = *n - 1;
            break;
        }
    }
}