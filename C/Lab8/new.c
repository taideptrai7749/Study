#include <stdio.h>
#include <string.h>

typedef struct
{
    char id[100];
    char name[100];
    double math, physics, chemistry;
    char kv[100];
    char loai[100];
} students;

void input(students[], int *);
void output(students[], int);
void studentScore(students[], int, double[], int[], int[]);
void printGrad(students[], double[], int);
void printValedictorian(students[], double[], int);
void printById(students[], double[], char[], int[], int[], int);
double gradPercentage(int, double[]);

int main()
{
    students student[100];
    int n;
    input(student, &n);
    output(student, n);
    double sumScore[n];
    int diemCong[n];
    int diemUuTien[n];
    studentScore(student, n, sumScore, diemCong, diemUuTien);
    printGrad(student, sumScore, n);
    printValedictorian(student, sumScore, n);
    printById(student, sumScore, "33", diemCong, diemUuTien, n);
    printf("The graduation percentage is %lf", gradPercentage(n, sumScore));
}

void input(students stu[], int *n)
{
    scanf("%d", n);
    int i;
    for (i = 0; i < *n; i++)
    {
        gets(stu[i].id);
        gets(stu[i].id);
        gets(stu[i].name);
        gets(stu[i].kv);
        scanf("%lf%lf%lf", &stu[i].math, &stu[i].physics, &stu[i].chemistry);
    }
    for (i = 0; i < *n; i++)
    {
        if (((stu[i].math + stu[i].chemistry + stu[i].physics) / 3.0) > 8)
        {
            strcpy(stu[i].loai, "Gioi");
        }
        else if (((stu[i].math + stu[i].chemistry + stu[i].physics) / 3.0) >= 7)
        {
            strcpy(stu[i].loai, "Kha");
        }
        else if (((stu[i].math + stu[i].chemistry + stu[i].physics) / 3.0) >= 5)
        {
            strcpy(stu[i].loai, "Trung Binh");
        }
        else
        {
            strcpy(stu[i].loai, "Yeu");
        }
    }
}

void output(students stu[], int n)
{
    int i;
    printf("Danh sach thi sinh: \n");
    for (i = 0; i < n; i++)
    {
        printf("%s\t%s\t%s\t%s\tMath: %.2lf\tPhysics: %.2lf\tChemistry: %.2lf\n", stu[i].id, stu[i].name, stu[i].kv, stu[i].loai, stu[i].math, stu[i].physics, stu[i].chemistry);
    }
}

void studentScore(students stu[], int n, double sumScore[], int diemCong[], int diemUuTien[])
{
    int i;
    for (i = 0; i < n; i++)
    {
        sumScore[i] = stu[i].math + stu[i].chemistry + stu[i].physics;
        if (!strcmp("Gioi", stu[i].loai))
        {
            diemCong[i] = 2;
            sumScore[i] = sumScore[i] + 2.0;
        }
        else if (!strcmp("Kha", stu[i].loai))
        {
            diemCong[i] = 1;
            sumScore[i] = sumScore[i] + 1.0;
        }
        if (!strcmp("kv3", stu[i].kv))
        {
            diemUuTien[i] = 2;
            sumScore[i] = sumScore[i] + 2.0;
        }
        else if (!strcmp("kv2", stu[i].kv))
        {
            diemUuTien[i] = 1;
            sumScore[i] = sumScore[i] + 1.0;
        }
    }
}

void printGrad(students stu[], double sumScore[], int n)
{
    int i;
    printf("DS thi sinh dau tot nghiep: \n");
    for (i = 0; i < n; i++)
    {
        if (sumScore[i] >= 15)
        {
            printf("%s\t%s\t%s\t%s\tMath: %.2lf\tPhysics: %.2lf\tChemistry: %.2lf\n", stu[i].id, stu[i].name, stu[i].kv, stu[i].loai, stu[i].math, stu[i].physics, stu[i].chemistry);
        }
    }
}

void printValedictorian(students stu[], double sumScore[], int n)
{
    int maxScore = sumScore[0];
    int i;
    for (i = 0; i < n; i++)
    {
        if (sumScore[i] >= maxScore)
        {
            maxScore = sumScore[i];
        }
    }
    printf("The valedictorians are: \n");
    for (i = 0; i < n; i++)
    {
        if (sumScore[i] == maxScore)
        {
            printf("%s\t%s\t%s\t%s\tMath: %.2lf\tPhysics: %.2lf\tChemistry: %.2lf\n", stu[i].id, stu[i].name, stu[i].kv, stu[i].loai, stu[i].math, stu[i].physics, stu[i].chemistry);
        }
    }
}

void printById(students stu[], double sumScore[], char id[], int diemCong[], int diemUuTien[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (!strcmp(id, stu[i].id))
        {
            printf("%s\t%lf\t%lf\t%lf\t%d\t%d\t%lf\n", stu[i].name, stu[i].math, stu[i].physics, stu[i].chemistry, diemCong[i], diemUuTien[i], sumScore[i]);
            break;
        }
    }
}

double gradPercentage(int n, double sumScore[])
{
    int i;
    int count = 0;
    for (i = 0; i < n; i++)
    {
        if (sumScore[i] >= 15)
        {
            count++;
        }
    }
    double percentage = count / (1.0 * n);
    return percentage;
}