#include <stdio.h>
#include <string.h>

void input(char[]);
void reverse(char[]);
void firstAndLast(char[]);
int main()
{
    char str[100];
    input(str);
    printf("The length of the input string is %d\n", strlen(str));
    reverse(str);
    firstAndLast(str);
}

void input(char str[])
{
    fgets(str, 100, stdin);
    str[strlen(str) - 1] = '\0';
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

void firstAndLast(char str[])
{
    char first[100];
    char last[100];
    int start = 0;
    int end = strlen(str) - 1;
    while (str[start] != ' ')
    {
        first[start] = str[start];
        start++;
    }
    first[strlen(first)] = '\0';
    int index = 0;
    while (str[end] != ' ')
    {
        last[index] = str[end];
        index++;
        end--;
    }
    last[strlen(last) - 1] = '\0';
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
