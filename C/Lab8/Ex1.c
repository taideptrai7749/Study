#include <stdio.h>

struct Employee
{
    int id;
    char name[100];
    char sex[100];
    int birthYear;
    int phoneNumber;
    int salary;
    void show()
    {
        printf("ID = %d\n", employee.id);
        printf("name = %s\n", employee.name);
        printf("sex = %s\n", employee.sex);
        printf("YOB = %d\n", employee.birthYear);
        printf("Phone = %d\n", employee.phoneNumber);
        printf("Salary = %d\n", employee.salary);
    }
};

int main()
{
    struct Employee employees[10];
    int i;
    for (i = 0; i < 10; i++)
    {
    }
}
