#include "../include/headerA3.h"
int main()
{
    a3Emp * headLL = NULL;
    loadEmpData(&headLL, "proFile.txt");
    int loop = 1;
    int ID;
    int x = 0;
    int whichEmpId = 0;
    char fullname[100];
    while(loop) 
    {
        int choice = 0;
        printf("Enter Task Number 1-9: ");
        scanf("%d",&choice);
        getchar();
        switch(choice)
        {
            case(1):
                //Task 1: Add a New Employee
                printf("Task 1\n");
                recruitEmployee (&headLL);
                //printAll(headLL);
                break;
            case(2):
                //Task 2: Print All Employees
                printAll(headLL);
                break;
            case(3):
                //Task 3: Print One Employee
                printf("\nEnter a position: ");
                scanf("%d", &x);
                printOne(headLL, x);
                break;
            case(4):
                //Task 4: Find Employee by ID
                
                printf("\nEnter an employee ID: ");
                scanf("%d", &whichEmpId);
                ID = lookOnId(headLL, whichEmpId);
                printOne(headLL,ID);
                break;
            case(5):
                //Task 5: Look by Full Name
                printf("Enter the full name of the employee: ");
                
                fgets(fullname,100,stdin);
                fullname[strcspn(fullname, "\n")] = 0;
                printOne(headLL, lookOnFullName(headLL, fullname));
                break;
            case(6):
                //Task 6: Count Employees
                printf("Total number of employees: %d\n",countEmployees (headLL));
                break;
            case(7):
                //Task 7: Sort Employees by ID
                sortEmployeesId (headLL);
                printAll(headLL);
                break;
            case(8):
                printf("There are %d employees currently.\n", countEmployees(headLL));
                fireOne(&headLL, 1);
                printAll(headLL);
                break;
            case(9):
                //Task 9: Fire All Employees
                fireAll(&headLL);
                printAll(headLL);
                free(headLL);
                break;
            default:
                loop = 0;
                break;
        }
    }
    a3Emp *temp = NULL;
    while((headLL)!= NULL)
    {
        temp = headLL;
        headLL = headLL->nextEmployee;
        for(int i = 0; i <= temp->numDependents;i++)
        {
            free(temp->dependents[i]);
        }
        free(temp->dependents);
        free(temp);
    }
    free(headLL);
    return 0;
}