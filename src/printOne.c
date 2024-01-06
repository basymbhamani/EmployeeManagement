#include "../include/headerA3.h"

void printOne (struct employee * headLL, int whichOne) {

    if (headLL == NULL) {
        printf("There are no employees in the list\n");
        return;
    }
    struct employee *current = headLL;

    if (whichOne <= 0 || whichOne > countEmployees(headLL)) {
        return;
    }
    
    for (int i = 0; i < whichOne-1; i++) {
        current = current->nextEmployee;
    }

    printf("\n");
    printf("Employee id: %d\n", current->empId);
    printf("First name: %s\n", current->fname);
    printf("Last name: %s\n", current->lname);
    printf("Dependents [%d]: ", current->numDependents);
    for (int i = 0; i < current->numDependents; i++) {
        printf("%s", current->dependents[i]);
        if (i != current->numDependents - 1) {
            printf(", ");
        }
    }
    printf("\n");
}