#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    int date;
    int month;
    int year;
} dateOfBirth;

typedef struct
{
    char id[100];
    char firstName[50];
    char lastName[50];
    char gender[10];
    dateOfBirth dob;
    char classID[100];
    char country[100];
    double averageScore;
} students;

typedef struct
{
    char studentID[100];
    char subjectID[100];
    double subjectScore;
} score;

typedef struct
{
    char subjectID[100];
    char subjectName[100];
    int subjectCredit;
} subject;

void countLines();
void readData(students[], score[], subject[]);
int numberOfStudents();
int numberOfScore();
int numberOfSubject();
void listClass(students[], char[]);
void countSex(students[], char[]);
void countryList(students[], char[]);
void sortAsc(students[]);
void sortDesc(students[]);
void topN(students[], int);

int main()
{
    FILE *diem, *dsmh, *dssv, *ketqua, *error;
    diem = fopen("diem.csv", "r");
    dsmh = fopen("dsmh.csv", "r");
    dssv = fopen("dssv.csv", "r");
    ketqua = fopen("kq.txt", "w");
    error = fopen("error.txt", "w");
    if (diem == NULL || dsmh == NULL || dssv == NULL)
    {
        printf("Can't open one of the files");
        exit(1);
    }
    char func[1000];
    char mainFunc[100], subFunc[100];
    gets(func);
    int countSpace = 0;
    for (int i = 0; i < strlen(func); i++)
    {
        if (isspace(func[i]))
        {
            countSpace++;
        }
    }
    int count = 0;
    char *tok = strtok(func, " ");
    while (tok)
    {
        if (count == 0)
        {
            strcpy(mainFunc, tok);
        }
        else if (count == 1)
        {
            strcpy(subFunc, tok);
        }
        count++;
        tok = strtok(NULL, " ");
    }
    if (count > 2 || countSpace > 1 || countSpace == 0)
    {
        fprintf(error, "Invalid command");
    }
    else
    {
        int studentNumber = numberOfStudents();
        students student[studentNumber];
        int scoreList = numberOfScore();
        score studentScore[scoreList];
        int subjectList = numberOfSubject();
        subject subjects[subjectList];
        countLines();
        readData(student, studentScore, subjects);
        int i;
        char newMainFunc[100];
        for (i = 0; i < strlen(mainFunc); i++)
        {
            newMainFunc[i] = tolower(mainFunc[i]);
        }
        newMainFunc[strlen(mainFunc)] = '\0';
        char newSubFunc[100];
        for (i = 0; i < strlen(subFunc); i++)
        {
            newSubFunc[i] = tolower(subFunc[i]);
        }
        newSubFunc[strlen(subFunc)] = '\0';
        if (!strcmp("list", newMainFunc))
        {
            listClass(student, newSubFunc);
        }
        else if (!strcmp("count", newMainFunc))
        {
            countSex(student, newSubFunc);
        }
        else if (!strcmp("country", newMainFunc))
        {
            countryList(student, newSubFunc);
        }
        else if (!strcmp("sort", newMainFunc))
        {
            if (!strcmp("asc", newSubFunc))
            {
                sortAsc(student);
            }
            else if (!strcmp("desc", newSubFunc))
            {
                sortDesc(student);
            }
            else
            {
                fprintf(error, "Invalid command");
            }
        }
        else if (!strcmp("top", newMainFunc))
        {
            int j;
            int errorCheck = 0;
            for (j = 0; j < strlen(newSubFunc); j++)
            {
                if (isdigit(newSubFunc[j]) == 0)
                {
                    fprintf(error, "invalid command");
                    errorCheck++;
                    break;
                }
            }
            if (errorCheck == 0)
            {
                int n = atoi(newSubFunc);
                if (n <= 0)
                {
                    fprintf(error, "invalid command");
                }
                else
                {
                    topN(student, n);
                }
            }
        }
        else
        {
            fprintf(error, "Invalid command");
        }
    }
    fclose(diem);
    fclose(dsmh);
    fclose(dssv);
    fclose(ketqua);
    fclose(error);
}

void countLines()
{
    FILE *diem, *dsmh, *dssv, *ketqua;
    diem = fopen("diem.csv", "r");
    dsmh = fopen("dsmh.csv", "r");
    dssv = fopen("dssv.csv", "r");
    ketqua = fopen("kq.txt", "w");
    int count1 = 0;
    char c;
    while (!feof(dssv))
    {
        c = fgetc(dssv);
        if (c == '\n')
        {
            count1++;
        }
        else if (c == EOF)
        {
            count1++;
        }
    }
    int count2 = 0;
    while (!feof(dsmh))
    {
        c = fgetc(dsmh);
        if (c == '\n')
        {
            count2++;
        }
        else if (c == EOF)
        {
            count2++;
        }
    }
    int count3 = 0;
    while (!feof(diem))
    {
        c = fgetc(diem);
        if (c == '\n')
        {
            count3++;
        }
        else if (c == EOF)
        {
            count3++;
        }
    }
    fprintf(ketqua, "%d - %d - %d", count1, count2, count3);
    fclose(diem);
    fclose(dsmh);
    fclose(dssv);
    fclose(ketqua);
}

void readData(students student[], score studentScore[], subject subjects[])
{
    FILE *diem, *dsmh, *dssv, *ketqua;
    diem = fopen("diem.csv", "r");
    dsmh = fopen("dsmh.csv", "r");
    dssv = fopen("dssv.csv", "r");
    char line[1024];
    int row = 0;
    int col = 0;
    int index = 0;
    while (fgets(line, 1024, dssv))
    {
        col = 0;
        row++;
        if (row == 1)
            continue;
        char *colValue = strtok(line, ",/");
        while (colValue)
        {
            if (col == 0)
                strcpy(student[index].id, colValue);
            if (col == 1)
                strcpy(student[index].firstName, colValue);
            if (col == 2)
                strcpy(student[index].lastName, colValue);
            if (col == 3)
                strcpy(student[index].gender, colValue);
            if (col == 4)
                student[index].dob.date = atoi(colValue);
            if (col == 5)
                student[index].dob.month = atoi(colValue);
            if (col == 6)
                student[index].dob.year = atoi(colValue);
            if (col == 7)
                strcpy(student[index].classID, colValue);
            if (col == 8)
                strcpy(student[index].country, colValue);
            colValue = strtok(NULL, ",/");
            col++;
        }
        index++;
    }
    row = 0;
    col = 0;
    index = 0;
    while (fgets(line, 1024, diem))
    {
        col = 0;
        row++;
        if (row == 1)
            continue;
        char *colValue = strtok(line, ",");
        while (colValue)
        {
            if (col == 0)
            {
                strcpy(studentScore[index].studentID, colValue);
            }
            if (col == 1)
            {
                strcpy(studentScore[index].subjectID, colValue);
            }
            if (col == 2)
            {
                char *endp;
                studentScore[index].subjectScore = strtod(colValue, &endp);
            }
            col++;
            colValue = strtok(NULL, ",");
        }
        index++;
    }
    row = 0;
    col = 0;
    index = 0;
    while (fgets(line, 1024, dsmh))
    {
        col = 0;
        row++;
        if (row == 1)
            continue;
        char *colValue = strtok(line, ",");
        while (colValue)
        {
            if (col == 0)
            {
                strcpy(subjects[index].subjectID, colValue);
            }
            if (col == 1)
            {
                strcpy(subjects[index].subjectName, colValue);
            }
            if (col == 2)
            {
                subjects[index].subjectCredit = atoi(colValue);
            }
            col++;
            colValue = strtok(NULL, ",");
        }
        index++;
    }
    int i;
    int studentCount = numberOfStudents();
    int scoreCount = numberOfScore();
    for (i = 0; i < studentCount; i++)
    {
        double score = 0.0;
        double average;
        int count = 0;
        int j;
        for (j = 0; j < scoreCount; j++)
        {
            if (!(strcmp(student[i].id, studentScore[j].studentID)))
            {
                score = score + studentScore[j].subjectScore;
                count++;
            }
        }
        average = score / (1.0 * count);
        student[i].averageScore = average;
    }
    for (i = 0; i < studentCount - 1; i++)
    {
        student[i].country[strlen(student[i].country) - 2] = '\0';
    }
    fclose(diem);
    fclose(dsmh);
    fclose(dssv);
}

void listClass(students stu[], char class[])
{
    FILE *result;
    result = fopen("ketqua.csv", "w");
    int i;
    int newLine = 0;
    int numberStudent = numberOfStudents();
    for (i = 0; i < numberStudent; i++)
    {
        if (!strcmp(class, stu[i].classID))
        {
            newLine++;
            if (newLine == 1)
            {
                fprintf(result, "%s,%s,%s,%s,%.2d/%.2d/%.2d,%s,%s", stu[i].id, stu[i].firstName, stu[i].lastName, stu[i].gender, stu[i].dob.date, stu[i].dob.month, stu[i].dob.year, stu[i].classID, stu[i].country);
            }
            else
            {
                fprintf(result, "\n%s,%s,%s,%s,%.2d/%.2d/%.2d,%s,%s", stu[i].id, stu[i].firstName, stu[i].lastName, stu[i].gender, stu[i].dob.date, stu[i].dob.month, stu[i].dob.year, stu[i].classID, stu[i].country);
            }
        }
    }
    fclose(result);
}

void countSex(students stu[], char sex[])
{
    FILE *result;
    result = fopen("ketqua.csv", "w");
    int i;
    int numberStudent = numberOfStudents();
    int count = 0;
    char sexIdentify[100];
    for (i = 0; i < strlen(sex); i++)
    {
        if (i == 0)
        {
            sexIdentify[i] = toupper(sex[i]);
        }
        else
            sexIdentify[i] = tolower(sex[i]);
    }
    for (i = 0; i < numberStudent; i++)
    {
        if (!strcmp(sexIdentify, stu[i].gender))
        {
            count++;
        }
    }
    fprintf(result, "%d", count);
    fclose(result);
}

void countryList(students stu[], char country[])
{
    FILE *result;
    result = fopen("ketqua.csv", "w");
    int i;
    int newLine = 0;
    int numberStudent = numberOfStudents();
    char countryIdentify[100];
    for (i = 0; i < strlen(country); i++)
    {
        if (i == 0)
        {
            countryIdentify[i] = toupper(country[i]);
        }
        else
            countryIdentify[i] = tolower(country[i]);
    }
    for (i = 0; i < numberStudent; i++)
    {
        if (!strcmp(countryIdentify, stu[i].country))
        {
            newLine++;
            if (newLine == 1)
            {
                fprintf(result, "%s,%s,%s,%s,%.2d/%.2d/%.2d,%s,%s", stu[i].id, stu[i].firstName, stu[i].lastName, stu[i].gender, stu[i].dob.date, stu[i].dob.month, stu[i].dob.year, stu[i].classID, stu[i].country);
            }
            else
            {
                fprintf(result, "\n%s,%s,%s,%s,%.2d/%.2d/%.2d,%s,%s", stu[i].id, stu[i].firstName, stu[i].lastName, stu[i].gender, stu[i].dob.date, stu[i].dob.month, stu[i].dob.year, stu[i].classID, stu[i].country);
            }
        }
    }
    fclose(result);
}

void sortAsc(students stu[])
{
    FILE *result;
    result = fopen("ketqua.csv", "w");
    int i;
    int numberStudent = numberOfStudents();
    students temp;
    for (i = 0; i < numberStudent; i++)
    {
        int j;
        for (j = i + 1; j < numberStudent; j++)
        {
            if (!strcmp(stu[i].firstName, stu[j].firstName))
            {
                if (stu[i].dob.year > stu[j].dob.year)
                {
                    temp = stu[i];
                    stu[i] = stu[j];
                    stu[j] = temp;
                }
                else if (stu[i].dob.month > stu[j].dob.month)
                {
                    temp = stu[i];
                    stu[i] = stu[j];
                    stu[j] = temp;
                }
                else if (stu[i].dob.date > stu[j].dob.date)
                {
                    temp = stu[i];
                    stu[i] = stu[j];
                    stu[j] = temp;
                }
            }
            if (strcmp(stu[i].firstName, stu[j].firstName) > 0)
            {
                temp = stu[i];
                stu[i] = stu[j];
                stu[j] = temp;
            }
        }
    }
    int newLine = 0;
    for (i = 0; i < numberStudent; i++)
    {
        newLine++;
        if (newLine == 1)
        {
            fprintf(result, "%s,%s,%s,%s,%.2d/%.2d/%.2d,%s,%s", stu[i].id, stu[i].firstName, stu[i].lastName, stu[i].gender, stu[i].dob.date, stu[i].dob.month, stu[i].dob.year, stu[i].classID, stu[i].country);
            continue;
        }
        fprintf(result, "\n%s,%s,%s,%s,%.2d/%.2d/%.2d,%s,%s", stu[i].id, stu[i].firstName, stu[i].lastName, stu[i].gender, stu[i].dob.date, stu[i].dob.month, stu[i].dob.year, stu[i].classID, stu[i].country);
    }
    fclose(result);
}

void sortDesc(students stu[])
{
    FILE *result;
    result = fopen("ketqua.csv", "w");
    int i;
    int studentNumber = numberOfStudents();
    students temp;
    for (i = 0; i < studentNumber; i++)
    {
        int j;
        for (j = i + 1; j < studentNumber; j++)
        {
            if (!strcmp(stu[i].firstName, stu[j].firstName))
            {
                if (stu[i].dob.year < stu[j].dob.year)
                {
                    temp = stu[i];
                    stu[i] = stu[j];
                    stu[j] = temp;
                }
                else if (stu[i].dob.month < stu[j].dob.month)
                {
                    temp = stu[i];
                    stu[i] = stu[j];
                    stu[j] = temp;
                }
                else if (stu[i].dob.date < stu[i].dob.date)
                {
                    temp = stu[i];
                    stu[i] = stu[j];
                    stu[j] = temp;
                }
            }
            if (strcmp(stu[i].firstName, stu[j].firstName) < 0)
            {
                temp = stu[i];
                stu[i] = stu[j];
                stu[j] = temp;
            }
        }
    }
    int newLine = 0;
    for (i = 0; i < studentNumber; i++)
    {
        newLine++;
        if (newLine == 1)
        {
            fprintf(result, "%s,%s,%s,%s,%.2d/%.2d/%.2d,%s,%s", stu[i].id, stu[i].firstName, stu[i].lastName, stu[i].gender, stu[i].dob.date, stu[i].dob.month, stu[i].dob.year, stu[i].classID, stu[i].country);
            continue;
        }
        fprintf(result, "\n%s,%s,%s,%s,%.2d/%.2d/%.2d,%s,%s", stu[i].id, stu[i].firstName, stu[i].lastName, stu[i].gender, stu[i].dob.date, stu[i].dob.month, stu[i].dob.year, stu[i].classID, stu[i].country);
    }
    fclose(result);
}

void topN(students stu[], int number)
{
    FILE *result;
    result = fopen("ketqua.csv", "w");
    int i;
    int studentNumber = numberOfStudents();
    students temp;
    for (i = 0; i < studentNumber; i++)
    {

        int j;
        for (j = i + 1; j < studentNumber; j++)
        {
            if (stu[i].averageScore < stu[j].averageScore)
            {
                temp = stu[i];
                stu[i] = stu[j];
                stu[j] = temp;
            }
        }
    }
    int newLine = 0;
    for (i = 0; i < number; i++)
    {
        newLine++;
        if (newLine == 1)
        {
            fprintf(result, "%s,%s,%s,%s,%.2d/%.2d/%.2d,%s,%s", stu[i].id, stu[i].firstName, stu[i].lastName, stu[i].gender, stu[i].dob.date, stu[i].dob.month, stu[i].dob.year, stu[i].classID, stu[i].country);
            continue;
        }
        fprintf(result, "\n%s,%s,%s,%s,%.2d/%.2d/%.2d,%s,%s", stu[i].id, stu[i].firstName, stu[i].lastName, stu[i].gender, stu[i].dob.date, stu[i].dob.month, stu[i].dob.year, stu[i].classID, stu[i].country);
    }
    fclose(result);
}

int numberOfStudents()
{
    FILE *dssv;
    dssv = fopen("dssv.csv", "r");
    int count = 0;
    char c;
    while (!feof(dssv))
    {
        c = fgetc(dssv);
        if (c == '\n')
        {
            count++;
        }
    }
    fclose(dssv);
    return count;
}

int numberOfScore()
{
    FILE *diem;
    diem = fopen("diem.csv", "r");
    int count = 0;
    char c;
    while (!feof(diem))
    {
        c = fgetc(diem);
        if (c == '\n')
        {
            count++;
        }
    }
    fclose(diem);
    return count;
}

int numberOfSubject()
{
    FILE *dsmh;
    dsmh = fopen("dsmh.csv", "r");
    int count = 0;
    char c;
    while (!feof(dsmh))
    {
        c = fgetc(dsmh);
        if (c == '\n')
        {
            count++;
        }
    }
    fclose(dsmh);
    return count;
}