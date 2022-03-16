/*                                      --Welcome--
                        ----SMALL USER MANAGEMENT PROGRAM---
*/

//Header file section
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Function declaration

int date,month,year,id,id1;
char name[200],sex[200];
int choice,age,currentyear = 2020;
float salary,salary1;
char name1[200];
char sex1[200];
int date1,month1,year1,age1,choice1,main_exit;

//Main function

int main()
{

    int result;
    char password[200];
    int main_exit1;
    char code[200] = "pavan";

    //Password for this program is "pavan"

    printf("\n\n\n\t\t ENTER THE PASSWORD FOR LOGIN TO PAVANS PROGRAMM: ");
    scanf(" %s",password);

    result = strcmp(password,code);

    //check whether given password to unlock program is right or wrong

    if (result == 0)
    {
        printf(" \n\t PASSWORD MATCH!");
        printf(" \n\t PLEASE WAIT LOADING: ");

        //code for loading sensation

        for(int i=0;i<=6;i++)
        {
            printf(".");
            for(int il = 0;il<99999999;il++);
        }
        disply();
    }
    else {
             system("cls");
        printf(" \n\n\tINVALID PASSWORD");

        printf(" \n\n\t\tenter 0 to login again and 1 to exit: ");
        scanf(" %d",&main_exit1);

        if( main_exit1 == 0)
        {
            system("cls");

            main();
        }
        if( main_exit1 == 1)
        {
            close();
        }
    }

return 0;
}

//display function

void disply(void)
{
        system("cls");

    printf("\n\n\n\n\n \t\t\t\t welcome to small user management program");
    printf("\n\n\t\t\t\t\t\t by pavan");
    printf("\n\t\t1. add employee\n\t\t2. update existing employee details\n\t\t3. view employee list\n\t\t4. delete employee\n\t\t5. exit\n\n");
    scanf(" %d",&choice);

    //menu for update,add view and delete data of the employees

    switch(choice)
    {
        case 1: addemployee();//function calling
        break;

        case 2: updateemployee();
        break;

        case 3: employeedetails();
        break;

        case 4: de();//delete employee
        break;

        case 5: close();
        break;

        default : printf("enter a valid choice!");

         printf(" \n\nenter 0 to go to main menu and 1 to exit: ");
         scanf(" %d",&main_exit);

        //exiting the program

        if (main_exit == 0)
        {
            disply();
        }
        if (main_exit == 1)
        {
            close();
        }

    }

return;
}

//Function to add employee details

void addemployee(void)    /*if we use void addemployee() we need to inilaize void addemployee(); at top
                             or if we use void addemloyee(void) we noneed to inilaize */
{
    int idd;
    int it1;
    system("cls");
    int main_exit2;

printf(" \n\tenter employee ID: ");
scanf(" %d",&idd);

if(2>1)
{

    FILE *zz;
zz = fopen("employeedetails.txt","r");

// scanning employee id, employee name , epmloyee sex,date,month,year age and salary

while(fscanf(zz,"%d %s %s %d/%d/%d %d %f",&id,name,sex,&date,&month,&year,&age,&salary)!=EOF)
    {
        if(idd == id)
        {
            printf(" \n\tthe employee id already in use");
            fclose(zz);//calling closing function
            printf(" \n\n\tto view employee list enter 0 and 1 to goto main menu : ");
scanf(" %d",&it1);

  if(it1 == 0)
  {
      employeedetails();
  }

  if(it1 == 1)
  {
      disply();
  }
        }

}

}


printf(" \n\twhat is your name: ");//scanning employee name
scanf(" %s",name);

printf(" \n\tenter your sex: ");//scanning employee sex
scanf(" %s",sex);

printf("\n\tenter your date of birth (in the format dd/mm/yyyy): ");//employee data birth
scanf(" %d/%d/%d",&date,&month,&year);

age = currentyear - year;

printf("\n\t enter the employee salary: ");//scanning employee salary
scanf(" %f",&salary);

printf("\n\n\t\t EMPLOYEE REGISTRED SUCESFULLY");
puts("\n\n");

FILE * empdet;
empdet = fopen("employeedetails.txt","a+");
fprintf(empdet," \n%d %s %s %d/%d/%d %d %f",idd,name,sex,date,month,year,age,salary);

fclose(empdet);

printf(" \n\tenter '1' to main menu and '0' to exit: ");
scanf(" %d",&main_exit2);
if (main_exit2 == 1 )
{
    system("cls");
    disply();
}

if (main_exit2 == 0)
{
    close();
}

return;
}

//function to update salary

void updateemployee(void)
{
    system("cls");
    int main_exit3;
    FILE * updtemp;
    FILE * temp;
    updtemp = fopen("employeedetails.txt","r");
    temp = fopen("employeetemp.txt","a+");
    printf("\n\t enter the employee id that you want to change information ");
     printf("\n\n\t if you do not remember you id enter '0' to view employee list: ");
     scanf(" %d",&id1);
        if (id1 == 0)
        {
            employeedetails();
        }
    while(fscanf(updtemp,"%d %s %s %d/%d/%d %d %f",&id,name,sex,&date,&month,&year,&age,&salary)!=EOF)//scanning employee details to be updated
    {
        if(id1 == id)
    {

        printf("\n\nwhich information do you want to change:");
    printf("\n\n\t 1.NAME \n\n\t 2. SEX \n\n\t 3. DATE OF BIRTH \n\n\t 4. SALARY\n");
    scanf(" %d",&choice1);
     //to update name
     if(choice1 == 1)
    {
        printf(" \nENTER THE NEW NAME: ");
        scanf(" %s",&name1);

        fprintf(temp," \n%d %s %s %d/%d/%d %d %f",id,name1,sex,date,month,year,age,salary);

    }
    //to update sex
    if (choice1 == 2)
    {
        printf(" \nENTER THE SEX: ");
        scanf(" %s",&sex1);
        fprintf(temp," \n%d %s %s %d/%d/%d %d %f",id,name,sex1,date,month,year,age,salary);



    }

    // to update date of birth

    if ( choice1 == 3)
    {
        printf(" \nENTER THE DATE OF BIRTH (DD/MM/YYYY): ");
        scanf(" %d/%d/%d",&date1,&month1,&year1);
            age1 = currentyear - year1;

            fprintf(temp," \n%d %s %s %d/%d/%d %d %f",id,name,sex,date1,month1,year1,age1,salary);

    }

    //to update salary

     if (choice1 == 4)
    {
        printf(" \nENTER THE NEW SALARY: ");
        scanf(" %f",&salary1);

        fprintf(temp," \n%d %s %s %d/%d/%d %d %f",id,name,sex,date,month,year,age,salary1);

    }

    }else {
             fprintf(temp," \n%d %s %s %d/%d/%d %d %f",id,name,sex,date,month,year,age,salary);
    }
    }
        fclose(updtemp);
        fclose(temp);

        remove("employeedetails.txt");
        rename("employeetemp.txt","employeedetails.txt");//changing file name

        printf(" \n\n\t CHANGED SUCSESFULLY");
        puts("\n\n");

    printf(" \n\tenter '1' to main menu \n\n enter '2' to go back and '0' to exit: ");
scanf(" %d",&main_exit3);
if (main_exit3 == 1 )
{
    system("cls");
    disply();
}

if (main_exit3 == 2)
{
    updateemployee();
}

if (main_exit3 == 0)
{
    close();
}
    }

//to display employee details

void employeedetails(void)
{
    system("cls");
    int main_exit4;
    FILE* rempdet;
    rempdet = fopen("employeedetails.txt","r");
       printf("\n | ID |   NAME     |   SEX   | DATE OF BIRTH |   AGE   |   SALARY   |");
    while(fscanf(rempdet,"%d %s %s %d/%d/%d %d %f",&id,name,sex,&date,&month,&year,&age,&salary)!= EOF)
    {
    printf("\n   %d",id);
    printf("      %s",name);
    printf("      %s",sex);
    printf("    %d/%d/%d",date,month,year);
    printf("         %d",age);
    printf("        %.2f",salary);

    }
    fclose(rempdet);
    puts("\n\n");

printf(" \n\tenter '1' to main menu and '0' to exit: ");
scanf(" %d",&main_exit4);
if (main_exit4 == 1 )
{
    system("cls");
    disply();
}

if (main_exit4 == 0)
{
    close();
}


return;
}

//closing function

void close(void)
{

    printf("\n\n\n\n\t\tThis is c mini employee manegement program by pavan!");

    puts("\n\n");
    getch();
    return;

}

//function to delete employee data

void de(void)
{
    int del;

    FILE *empdel;
    FILE * emptemp;
    int main_exit5;
    empdel = fopen("employeedetails.txt","r");
    emptemp = fopen("employeetemp.txt","a+");
        printf("\t enter the employee id to delete ");
        printf("\n\nif you do not remember you id enter '0' to view employee list: ");
        scanf(" %d",&del);
        if (del == 0)
        {
            employeedetails();
        }
    while(fscanf(empdel,"%d %s %s %d/%d/%d %d %f",&id,name,sex,&date,&month,&year,&age,&salary)!=EOF)
    {
        if (del != id)
        {
            fprintf(emptemp," \n%d %s %s %d/%d/%d %d %f",id,name,sex,date,month,year,age,salary);
        }


    }   fclose(empdel);
        fclose(emptemp);
        remove("employeedetails.txt");
        rename("employeetemp.txt","employeedetails.txt");

                printf(" \n\n\t REMOVED SUCSESFULLY");
                puts("\n\n");

printf(" \n\tenter '1' to main menu and '0' to exit: ");
scanf(" %d",&main_exit5);
if (main_exit5 == 1 )
{
    system("cls");
    disply();
}

if (main_exit5 == 0)
{
    close();
}
    return;
}
