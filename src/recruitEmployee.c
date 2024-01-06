#include "../include/headerA3.h"
#include <time.h>

void recruitEmployee (struct employee ** headLL) {
    struct employee *newEmployee = (struct employee*) malloc(sizeof(struct employee));
    char dependent[MAX_LENGTH];
    char yesOrNo;

    printf("\nEnter the first name of the employee: ");
    scanf("%s", newEmployee->fname);
    printf("Enter the last name of the employee: ");
    scanf("%s", newEmployee->lname);

    newEmployee->numDependents = 0;
    newEmployee->dependents = malloc(sizeof(char *));
    do {
        newEmployee->numDependents++;
        printf("\nEnter name of dependent# %d: ", newEmployee->numDependents);
        scanf("%s", dependent);
        newEmployee->dependents = realloc (newEmployee->dependents, sizeof(char *) * newEmployee->numDependents);
        newEmployee->dependents[newEmployee->numDependents-1] = malloc(sizeof(char) * (strlen(dependent) + 1));
        strcpy(newEmployee->dependents[newEmployee->numDependents-1], dependent);
        printf("Do you have any more dependents? ");
        scanf(" %c", &yesOrNo);
    } while (yesOrNo == 'y' || yesOrNo == 'Y');

    printf("\nYou have %d dependents.\n", newEmployee->numDependents);

    newEmployee->empId = 0;
    for (int i = 0; i < strlen(newEmployee->fname); i++) {
        newEmployee->empId += newEmployee->fname[i];
    }
    newEmployee->empId += strlen(newEmployee->lname);
   

    newEmployee->nextEmployee = NULL;

    if (*headLL == NULL) {
        *headLL = newEmployee;
        return;
    }

    struct employee* last = *headLL;

    while (last->nextEmployee != NULL) {
        last = last->nextEmployee;
    }

    last->nextEmployee = newEmployee;

    int isUniqueId;

    do {
        isUniqueId = 1;
        struct employee* temp = *headLL;
        while (temp->nextEmployee != NULL) {
            if (temp->empId == newEmployee->empId) {
                isUniqueId = 0;
                srand (time (NULL));
                newEmployee->empId += ((rand () % 999) + 1);
                break;
            }
            temp = temp->nextEmployee;
        }
        
    } while (isUniqueId == 0);

     printf("\nYour computer-generated empid is %d\n", newEmployee->empId);

}