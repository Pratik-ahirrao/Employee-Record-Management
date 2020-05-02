#include"chirag.h"
#include"deepesh.h"
#include"gagan.h"
#include"pratik.h"
#include"sarvesh.h"
#include"sandeep.h"
#include<stdio.h>
#include<stdlib.h>


void display_options()
{
    printf("1. List all Employees.\n2. Add an Employee.\n3. Remove an Employee.\n4. Modify the records of an Employee.\n5. Display a Particular employee based on ID.\n6. Display employees based on year of joining.\n7. Display Newest and Oldest Employee(s).\n8. Display employees who joined in a specific year range.\n9. Display employees based on their Designation.\n10. Display employees whose salary is in a given range.\n11. Display Employees in an alphabetical order of their names.\n12. Display Employees in an ascending order of their salaries.\n0. Quit\n-1. Display the Options\n");
}
void start()
{
    printf("\n\t\t\tWelcome to the Software Company Employee Records Management System.\n");
    display_options();
}

int main()
{
    start();
    int n = 100;
while ( n != 0 )
{
    int next;
    printf("Enter an option: ");
    scanf("%d",&next);
    n = next;
    if (n == 1)
        list_employees();//deepesh
    else if (n==2)
        add_record();//pratik
    else if (n==3)
        delete_record();//chirag
    else if (n==4)
        modify_record();//deepesh
    else if (n==5)
        display_id(); //sandeep
    else if (n==6)
        specific_year();//chirag
    else if (n==7)
        new_old_employee();//pratik
    else if (n==8)
        display_range();//sandeep
    else if (n==9)
        disp_designation();//gagan
    else if (n==10)
        salary_range();//gagan
    else if (n==11)
        asc_name();//sarvesh
    else if (n==12)
        asc_sal();//sarvesh
    else if (n==0)
        {
            int m = 0;
            
            
            printf("Are you sure you want to exit?(1/0): ");
            while(m == 0){
            int inp;
            scanf("%d",&inp);
            if (inp==1){
            system("clear");
            printf("\n\t\t\t\t\tThanks for using this system!\n\n");
            exit(-1);
            }
            else if (inp == 0)
             {
                 n = 100;
                 break;
             }
             else 
             {
                 printf("Enter a valid Choice(1/0) : ");

             }
            }
        }
    else if(n==-1)
        display_options();
    else
        printf(" Please enter a valid option no. ");
} 
    return 0;
}
