#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//This function is to delete record of a employee
int count()
{
	int count_line=0;
	char c;
	FILE *p;
	p = fopen("records.txt","r");
	for(c=getc(p); c != EOF ;c=getc(p))
	{
		if (c =='\n')
			count_line+=1;
	}
	return count_line;
}

void delete_record()
{
    typedef struct
    {
	char ID[15];
	char first_name[25];
	char last_name[25];
	int age;
	int salary;
	int yoj;
	char designation[25];
    }RECORD;

    int x=1;
    while(x==1){
      char ID[15];
      printf("Enter ID to be deleted: ");
      scanf("%s",ID);
      int n,i;
      n = count();
      RECORD s[n];
      FILE *ptr;
      ptr = fopen("records.txt","r");
      for(i=0;i<n;i++)
	    fscanf(ptr,"%s %s %s %d %d %d %s\n",s[i].ID,s[i].first_name,s[i].last_name,&s[i].age,&s[i].salary,&s[i].yoj,s[i].designation);
      fclose(ptr);
      for(i=0;i<n;i++){
	    if (!(strcmp(s[i].ID,ID)))
		    break;
      }
      if(i==n){
	    printf("\nThe ID entered does not exist\n");
	    printf("\nPress 1 to delete record or press 0 to exit.\nEnter your choice :  ");
	    scanf("%d",&x);

      }
      else{
    	   FILE *temp;
    	   temp = fopen("Temp.txt","w");
    	   for(i=0;i<n;i++){
	      if (strcmp(s[i].ID,ID))
	        fprintf(temp,"%s %s %s %d %d %d %s\n",s[i].ID,s[i].first_name,s[i].last_name,s[i].age,s[i].salary,s[i].yoj,s[i].designation);
     	   }
     	   fclose(temp);
     	   remove("records.txt");
     	   rename("Temp.txt","records.txt");
	   printf("\nRecord deleted successfully.\nPress 1 to Delete another record or press 0 to return back.\nEnter your choice : ");
	   scanf("%d",&x);
      }
    }
 }
//Delete function ends


//This function is to Display record of employee joined in specific year

int count_lines()
{
        int count=0;
        char c;
        FILE *p;
        p = fopen("records.txt","r");
        for(c=getc(p); c != EOF ;c=getc(p))
        {
                if (c =='\n')
                        count+=1;
        }
        return count;
}


void specific_year()
{
	typedef struct
	{
		char ID[15];
		char first_name[25];
		char last_name[25];
		int age;
		int salary;
		int yoj;
		char designation[25];
	}RECORD;
         
	int x=1;
	while(x==1){
	  int year;
          printf("Enter year number to check record of employes joined in that year: ");
          scanf("%d",&year);
	  int n,i;
	  n = count_lines();
	  RECORD s[n];
	  FILE *ptr;
	  ptr = fopen("records.txt","r");
	  for(i=0;i<n;i++)
		fscanf(ptr,"%s %s %s %d %d %d %s",s[i].ID,s[i].first_name,s[i].last_name,&s[i].age,&s[i].salary,&s[i].yoj,s[i].designation);
      fclose(ptr);
	  for(i=0;i<n;i++){
		  if (s[i].yoj==year)
			  break;
	  }

	  if(i==n){
		  printf("\nNo employee joined in this year.\nPress 1 to search in other year or press 0 to exit.\nEnter your choice : ");
		  scanf("%d",&x);
	  }
	  else{
		  printf("\nThe following employees joined in the year %d.\n",year);
	     for(i=0;i<n;i++)
		 {
	      if (s[i].yoj == year)
		 	 printf("\n%s  %s %s  %d  %d  %d  %s\n",s[i].ID,s[i].first_name,s[i].last_name,s[i].age,s[i].salary,s[i].yoj,s[i].designation);
	     }
	    printf("\nPress 1 to try with another year or press 0 to return back.\nEnter your choice : ");
	    scanf("%d",&x);
	  }
	}
}
//Function to search record of specific year ends.

  
		

