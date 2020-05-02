#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int count_no_lines()
{
    int count = 0;
    char c;
    FILE *p;
    p = fopen("records.txt", "r");
    c = fgetc(p);
    while (c != EOF)
    {
        if (c == '\n')
        {
            count += 1;
        }
        c = fgetc(p);
    }
    return count;
}

void list_employees()
{
    FILE *fp;
    fp = fopen("records.txt", "r");
    // printf("Employee ID   Name     Age  Salary YOJ Designation\n");
    char c = fgetc(fp);

    if (fp == NULL)
    {
        printf("The records could not be accessed");
    }
    if (c == EOF)
    {
        printf("There are no records to display");
    }
    while (c != EOF)
    {
        putchar(c);
        c = fgetc(fp);
    }
    fclose(fp);
}

int modify_record()
{
    struct details
    {
        char ID[15];
        char first_name[25];
        char last_name[25];
        int age;
        int salary;
        int yoj;
        char designation[25];
    };
    int n = count_no_lines();
    if (n == 0)
    {
        printf("There are no employees in the records");
        return 0;
    }
    char modify[20];
    printf("Enter the ID of the employee:");
    scanf("%s", modify);
    struct details emp[n];
    FILE *fp, *tp;
    fp = fopen("records.txt", "r");
    if (fp == NULL)
    {
        printf("The records could not be opened");
        return 0;
    }
    int i;
    for (i = 0; i < n; i++)
    {
        fscanf(fp, "%s %s %s %d %d %d %s", emp[i].ID, emp[i].first_name, emp[i].last_name, &emp[i].age, &emp[i].salary, &emp[i].yoj, emp[i].designation);
    }
    int rec, flag = 0;
    for (i = 0; i < n; i++)
    {
        if (strcmp(emp[i].ID, modify) == 0)
        {
            rec = i;
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("There is no employee with that ID");
        return 0;
    }
    else
    {
        int deep =0;
        char change[20];
        printf("\nWhat part of the employee's record do you want to change ('ID', 'first name', 'last name', 'age', 'salary', 'YOJ', 'designation' ):");
        scanf("%s", change);
        if (strcmp(change, "ID") == 0 || strcmp(change, "id") == 0)
        {
            char update[20];
            printf("\nEnter the new ID:");
            scanf("%s", update);
            for(int m=0;m<n;m++)
            {
                if(strcmp(update,emp[m].ID) == 0)
                {
                    deep = 1;
                    break;
                }
            }
            if(deep == 0)
            {
            strcpy(emp[rec].ID, update);
            }
            else
            {
                printf("That ID already exists\n");
                return 0;
            }
            
        }
        else if (strcmp(change, "first name") == 0)
        {
            char update[20];
            printf("\nEnter the new first name:");
            scanf("%s", update);
            strcpy(emp[rec].first_name, update);
        }
        else if (strcmp(change, "last name") == 0)
        {
            char update[20];
            printf("\nEnter the new last name:");
            scanf("%s", update);
            strcpy(emp[rec].last_name, update);
        }
        else if (strcmp(change, "age") == 0)
        {
            int update;
            printf("\nEnter the new age:");
            scanf("%d", &update);
            emp[rec].age = update;
        }
        else if (strcmp(change, "salary") == 0)
        {
            int update;
            printf("\nEnter the new salary:");
            scanf("%d", &update);
            emp[rec].salary = update;
        }
        else if (strcmp(change, "yoj") == 0 || strcmp(change, "YOJ") == 0)
        {
            int update;
            printf("\nEnter the new year of joining:");
            scanf("%d", &update);
            emp[rec].yoj = update;
        }
        else if (strcmp(change, "designation") == 0)
        {
            char update[20];
            printf("\nEnter the new designation:");
            scanf("%s", update);
            strcpy(emp[rec].designation, update);
        }
        else
        {
            printf("That information does not exist");
            return 0;
        }
        tp = fopen("temp.txt", "w");
        for (i = 0; i < n; i++)
        {
            fprintf(tp, "%s %s %s %d %d %d %s\n", emp[i].ID, emp[i].first_name, emp[i].last_name, emp[i].age, emp[i].salary, emp[i].yoj, emp[i].designation);
        }
        fclose(fp);
        fclose(tp);
        remove("records.txt");
        rename("temp.txt", "records.txt");
        if(deep == 0)
        {
            printf("*************************************************************");
            printf("\nThe record has been modified\n");
        }
    }
}
