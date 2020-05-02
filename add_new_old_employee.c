#include<stdio.h>
#include<string.h>
#include<stdlib.h>
# define MAX 100

void add_record()
{
 FILE *fp;
 int output;
 output=1;
 int i=0;
 char arr[100][100];
 fp=fopen("records.txt","a+");
 char id[100];
 char first_name[100];
 char last_name[100];
 int age;
 int salary;
 int yoj;
 char designation[100];
 int flag=0;
 int j=0;
while(!feof(fp))
 {
   fscanf(fp,"%s %s %s %d %d %d %s \n",id,first_name,last_name,&age,&salary,&yoj,designation);
   strcpy(arr[i],id);
   i++;
 }

 char id1[100];
   printf("Enter Employee ID:");
   scanf("%s",id1);
   printf("\nEnter first name:");
   scanf("%s",first_name);
   printf("\nEnter last name:");
   scanf("%s",last_name);
   printf("\nEnter age:");
   scanf("%d",&age);
   printf("\nEnter salary:");
   scanf("%d",&salary);
   printf("\nEnter yoj:");
   scanf("%d",&yoj);
   printf("\nEnter designation:");
   scanf("%s",designation);
   while(j<i)
   {
    if(strcmp(id1 ,arr[j])==0)
    {
     int m;
     printf("ID has already been taken!!\n");
     flag=1;
     printf("\nEnter '1' to continue to add or '0' to return back to the menu: ");
     scanf("%d",&m);
    if (m==1)
      add_record();
    else
    {
      break;
    }
    }
    j++;
   }
if (flag !=1)
{
  fprintf(fp,"%s %s %s %d %d %d %s %c",id1,first_name,last_name,age,salary,yoj,designation,'\n');
  printf("\nRecord added successfully!!\n");
}
 fclose(fp);
}


void new_old_employee()
{
  FILE *fp;
  fp = fopen("records.txt","r");
  int output[MAX];
  int i=0;
  char id[100];
  char first_name[100];
  char last_name[100];
  int age;
  int salary;
  int yoj;
  char designation[100];
  while(!feof(fp))
  {
    fscanf(fp,"%s %s %s %d %d %d %s \n",id,first_name,last_name,&age,&salary,&yoj,designation);
    output[i] = yoj;
    i++;
  }

  int min = output[0];
    for (int j = 1; j < i; j++)
    {
        if (output[j] < min)
        {
           min = output[j];
        }
    }



    fseek(fp,1,SEEK_SET);
    int k =0 ;
    while(!feof(fp))
    {
      fscanf(fp,"%s %s %s %d %d %d %s \n",id,first_name,last_name,&age,&salary,&yoj,designation);
      if(yoj == min)
      {
        if (k ==0)
          printf("Oldest Employee(s) by year of joining :\n");
        printf("%s %s %s %d %d %d %s \n",id,first_name,last_name,age,salary,yoj,designation);
        k++;
      }

    }
    fseek(fp,1,SEEK_SET);

    int max = output[0];

    for (int j = 1; j < i; j++)
    {
      if (output[j] > max)
      {
        max = output[j];
      }
    }


    fseek(fp,1,SEEK_SET);
    int m =0;
    while(!feof(fp))
    {
     fscanf(fp,"%s %s %s %d %d %d %s \n",id,first_name,last_name,&age,&salary,&yoj,designation);
     if(yoj == max)
     {
       if (m == 0)
          printf("\nNewest Employee(s) by year of joining :\n");
       printf("%s %s %s %d %d %d %s \n",id,first_name,last_name,age,salary,yoj,designation);
       m++;
     }

    }
    fclose(fp);
}

