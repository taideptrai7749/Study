#include <stdio.h>
#include <string.h>
struct Candidate
{
    char id[10], name[30], section[10], clfica[10];
    double math, physics, chem;
};

void input(struct Candidate can[], int *n)
{
    scanf("%d", n);
    gets(can[0].id);
    int i;
    for (i = 0; i < *n; i++)
    {
        gets(can[i].id);
        gets(can[i].name);
        scanf("%lf%lf%lf", &can[i].math, &can[i].physics, &can[i].chem);
        gets(can[i].section);
        gets(can[i].section);
        gets(can[i].clfica);
    }
}

void output(struct Candidate can[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%s\t%s\t%s\t%s\t%lf\t%lf\t%lf\n", can[i].id, can[i].name, can[i].section, can[i].clfica, can[i].math, can[i].physics, can[i].chem);
    }
}

int main()
{
    struct Candidate can[10];
    int n;
    input(can, &n);
    output(can, n);
}