#include<stdio.h>
#include<string.h>
struct emp
	{
		char roll[50];
		char f_name[50];
		char l_name[50];
		int age, sal, yoj;
		char desg[50];
	};
void asc_sal()
{
	struct emp p[50];		// creating an array of structures containing details of indivisual employes
	int i = 0, n;
	FILE *fp;
	fp = fopen("records.txt","r");
	while(!feof(fp))
	{
		fscanf(fp, "%s %s %s %d %d %d %s", p[i].roll, p[i].f_name, p[i].l_name, &p[i].age, &p[i].sal, &p[i].yoj, p[i].desg); 
					//reading each detail in seperate variables
		i++;

	}
	struct emp temp;
	for(int x = 0; x < i-1; x++)	// sorting the array based on salary in ascending order
	{
		for(int y = 0;y < i-x-1; y++)
		{
			if(p[y].sal > p[y+1].sal)
			{
				temp = p[y];
				p[y] = p[y+1];
				p[y+1] = temp;
			}
		}
	}
	printf("The list in ascending order of salary is:\n");
	for(int x = 1; x<i; x++)
		printf("%s %s %s %d %d %d %s\n", p[x].roll, p[x].f_name, p[x].l_name, p[x].age, p[x].sal, p[x].yoj, p[x].desg);

	fclose(fp);
}
void asc_name()
{
	struct emp p[50];	// creating an array of structures containing details of indivisual employes
	int i = 0, n;
	FILE *fp;
	fp = fopen("records.txt","r");
	while(!feof(fp))
	{
		fscanf(fp, "%s %s %s %d %d %d %s", p[i].roll, p[i].f_name, p[i].l_name, &p[i].age, &p[i].sal, &p[i].yoj, p[i].desg);
				// reading each detail in seperate variables
		i++;

	}
	struct emp temp;
	for(int x = 0; x < i-1; x++)//sorting the array according to name in alphabetical order
	{
		for(int y = 0;y < i-x-1; y++)
		{
			if(strcmp(p[y].f_name, p[y+1].f_name) > 0)
			{
				temp = p[y];
				p[y] = p[y+1];
				p[y+1] = temp;
			}
		}
	}
	printf("The list in alphabetical order of names is:\n");
	for(int x = 1; x<i; x++)
		printf("%s %s %s %d %d %d %s\n", p[x].roll, p[x].f_name, p[x].l_name, p[x].age, p[x].sal, p[x].yoj, p[x].desg);
	fclose(fp);
}


