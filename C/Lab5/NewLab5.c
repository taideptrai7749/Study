#include <stdio.h>
#include <string.h>

void input(char[]);
void inputName(char[]);
void reverse(char[]);
void normalize(char[]);
void check_two();
void substringCheck();
void insertStrings(char[], char[], int);
int main()
{
    char str[100];
    input(str);
    reverse(str);
    char name[100];
    printf("Enter a new name: ");
    inputName(name);
    normalize(name);
    check_two();
    substringCheck();
    char new1[100];
    char new2[100];
    char k;
    int n;
    printf("Enter the insert position: ");
    scanf("%d", &n);
    scanf("%c", &k);
    printf("Enter string 1: ");
    input(new1);
    printf("Enter string 2: ");
    input(new2);
    insertStrings(new1, new2, n);
}

void input(char str[])
{
    fgets(str, 100, stdin);
    str[strlen(str) - 1] = '\0';
}

void inputName(char name[])
{
    fgets(name, 100, stdin);
    name[strlen(name) - 1] = '\0';
}

void reverse(char str[])
{
    char reversed[100];
    int i;
    for (i = 0; i < strlen(str); i++)
    {
        reversed[i] = str[strlen(str) - 1 - i];
    }
    reversed[strlen(reversed)] = '\0';
    printf("%s\n", reversed);
}

void normalize(char name[])
{
    while (name[strlen(name) - 1] == ' ')
    {
        name[strlen(name) - 1] = '\0';
    }
    while (name[0] == ' ')
    {
        stpcpy(&name[0], &name[1]);
    }
    int i;
    for (i = 0; i < strlen(name); i++)
    {
        if (name[i] == ' ' && name[i + 1] == ' ')
        {
            stpcpy(&name[i], &name[i + 1]);
            i--;
        }
    }
    for (i = 0; i < strlen(name); i++)
    {
        if (name[i] >= 'A' && name[i] <= 'Z')
        {
            name[i] = name[i] + 32;
        }
    }
    name[0] = name[0] - 32;
    for (i = 0; i < strlen(name); i++)
    {
        if (name[i] == ' ' && name[i + 1] != ' ')
        {
            name[i + 1] = name[i + 1] - 32;
        }
    }
    printf("%s\n", name);
}

void check_two()
{
    char newString[100];
    printf("Enter a new string: ");
    input(newString);
    printf("Enter a character: ");
    char c;
    char k;
    scanf("%c", &c);
    scanf("%c", &k);
    int i;
    int yes = 0;
    printf("The first postion the character appear (-1 for not appearing): ");
    for (i = 0; i < strlen(newString); i++)
    {
        if (c == newString[i])
        {
            yes = 1;
            printf("%d ", i);
            break;
        }
    }
    if (yes == 0)
        printf("%d", -1);
    printf("\n");
}

void insertStrings(char new1[], char new2[], int n)
{
    int index1;
    int index2 = 0;
    int i;
    for (i = 0; i < strlen(new2); i++)
    {
        for (index1 = strlen(new1) + 1; index1 >= n; index1--)
        {
            new1[index1] = new1[index1 - 1];
        }
        new1[n] = new2[i];
        n = n + 1;
    }
    printf("%s\n", new1);
}

void substringCheck()
{
    char newString1[100];
    char newString2[100];
    printf("Enter string 1: ");
    gets(newString1);
    printf("Enter string 2: ");
    gets(newString2);
    int i;
    int condition = 0;
    for (i = 0; i < strlen(newString1); i++)
    {
        if (newString2[condition] == newString1[i])
        {
            condition++;
        }
        else
        {
            if (condition > 0)
            {
                i = i - condition;
            }
            condition = 0;
        }
        if (condition == strlen(newString2))
        {
            break;
        }
    }
    if (condition == strlen(newString2))
    {
        printf("%d\n", i - condition + 1);
    }
    else
        printf("%d\n", -1);
}