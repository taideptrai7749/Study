#include <stdio.h>
#include <string.h>

void input(char[]);
void inputName(char[]);
void reverse(char[]);
void firstAndLast(char[]);
void normalize(char[]);
void concatenate(char[], char[]);
int check();
void check_two();
void check_three();
void substringCheck();
void insertStrings(char[], char[], int);
void deleteCharacter();
int main()
{
    char str[100];
    input(str);
    printf("The length of the input string is %d\n", strlen(str));
    reverse(str);
    char name1[100];
    printf("Enter your name: ");
    input(name1);
    firstAndLast(name1);
    char name[100];
    printf("Enter a new name: ");
    inputName(name);
    normalize(name);
    char str1[100];
    char str2[100];
    printf("Enter string one: ");
    input(str1);
    printf("Enter string two: ");
    input(str2);
    concatenate(str1, str2);
    if (check())
    {
        printf("Character does appear in the string.\n");
    }
    else
    {
        printf("The character doesn't appear in the string\n");
    }
    check_two();
    check_three();
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
    deleteCharacter();
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

void firstAndLast(char name1[])
{
    char first[100];
    char last[100];
    int start = 0;
    int end = strlen(name1) - 1;
    while (name1[start] != ' ')
    {
        first[start] = name1[start];
        start++;
    }
    first[strlen(first)] = '\0';
    int index = 0;
    while (name1[end] != ' ')
    {
        last[index] = name1[end];
        index++;
        end--;
    }
    last[strlen(last)] = '\0';
    int i;
    for (i = 0; i < strlen(last) / 2; i++)
    {
        char temp = last[i];
        last[i] = last[strlen(last) - 1 - i];
        last[strlen(last) - 1 - i] = temp;
    }
    printf("%s\n", first);
    printf("%s\n", last);
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

void concatenate(char str1[], char str2[])
{
    char str3[100];
    int index = 0;
    while (str1[index] != '\0')
    {
        str3[index] = str1[index];
        index++;
    }
    int secondIndex = index;
    index = 0;
    while (str2[index] != '\0')
    {
        str3[secondIndex] = str2[index];
        secondIndex++;
        index++;
    }
    printf("%s\n", str3);
}

int check()
{
    char newString[100];
    printf("Enter a new string: ");
    input(newString);
    printf("Enter a character: ");
    char k;
    char c;
    scanf("%c", &c);
    scanf("%c", &k);
    int i;
    for (i = 0; i < strlen(newString); i++)
    {
        if (c == newString[i])
        {
            return 1;
            break;
        }
    }
    return 0;
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

void deleteCharacter()
{
    int n;
    int position;
    char string[100];
    printf("Enter string: ");
    fgets(string, 100, stdin);
    string[strlen(string) - 1] = '\0';
    printf("Enter the number of characters to delte: ");
    scanf("%d", &n);
    printf("Enter the starting position to delete: ");
    scanf("%d", &position);
    int index;
    int i;
    for (i = 0; i < n; i++)
    {
        for (index = position; index < strlen(string); index++)
        {
            string[index] = string[index + 1];
        }
    }
    printf("%s\n", string);
}

void check_three()
{
    char text[100];
    char c;
    printf("Enter a string: ");
    input(text);
    printf("Enter a character: ");
    scanf("%c", &c);
    char k;
    scanf("%c", &k);
    int i;
    for (i = 0; i < strlen(text); i++)
    {
        if (text[i] == c)
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}