#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct person{
    char ID[15];
    char first_name[25];
    char last_name[25];
    int age;
    int salary;
    int yoj;
    char designation[25];

};

void salary_range()
{
    int start,end;
    int count=0;
    printf("Enter the range values: ");
    scanf("%d %d",&start,&end);
    if (start<end)
    {FILE *fp;
    fp = fopen("records.txt","r");
    struct person details[100];
    int i=0;
    while(!feof(fp))
    {
        fscanf(fp,"%s %s %s %d %d %d %s\n",details[i].ID,details[i].first_name,details[i].last_name,&details[i].age,&details[i].salary,&details[i].yoj,details[i].designation);
        i++;
    }


    for(int k =0; k<i;k++)
    {
        if(details[k].salary >= start && details[k].salary <= end)
        {
            printf("%s %s %s %d %d %d %s\n",details[k].ID,details[k].first_name,details[k].last_name,details[k].age,details[k].salary,details[k].yoj,details[k].designation);
            count++;
        }
    }
    if (count ==0)
    {
        int b;
        printf("The given range of values does not encompass any employee's salary.\nTo try again with new range values type '1' and to return back type '0':");
        scanf("%d",&b);
        if (b==1)
            salary_range();
    }
    fclose(fp);
    }
    else{
        int c;
        printf("Enter a valid range,To try again with new range values type '1' and to return back type '0':");
        scanf("%d",&c);
        if (c==1)
            salary_range();
    }
}

void disp_designation()
{
    int count = 0;
    printf("Possible Designations : Project Manager(PM) Project Leader(PL) Senior Testing Officer(STO) Senior Software Engineer(SSE) Software Engineer(SE) Software Developer(SD) Junior Developer(JD) Quality Testing Officer(QTO)\nEnter a designation: ");
    char input[50];
    scanf("%s",input);  
    FILE *fp;
    fp = fopen("records.txt","r");
    struct person details[100];
    int i=0;
    while(!feof(fp))
    {
        fscanf(fp,"%s %s %s %d %d %d %s\n",details[i].ID,details[i].first_name,details[i].last_name,&details[i].age,&details[i].salary,&details[i].yoj,details[i].designation);
        i++;
    }

    for(int k =0; k<i;k++)
    {
        if(strcmp(details[k].designation,input)==0)
        {
            printf("%s %s %s %d %d %d %s\n",details[k].ID,details[k].first_name,details[k].last_name,details[k].age,details[k].salary,details[k].yoj,details[k].designation);
            count++;
        }
    }

    if (count == 0){
        int a;
    printf("The entered designation does not correspond to any employee of the company.\nTo try again with a new designation type '1' and to return back type '0': ");   
    scanf("%d",&a);
    if (a==1)
        disp_designation();
    }
    fclose(fp);
}
