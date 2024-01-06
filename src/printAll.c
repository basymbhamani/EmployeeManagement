#include "../include/headerA3.h"

void printAll (struct employee * headLL) {

    int count = 0;
    struct employee *current = headLL;
    while (current != NULL) {
        count++;
        printf("\n");
        printf("Employee # %d :\n", count);
        printf("\tEmployee id: %d\n", current->empId);
        printf("\tFirst name: %s\n", current->fname);
        printf("\tLast name: %s\n", current->lname);
        printf("\tDependents [%d]: ", current->numDependents);
        for (int i = 0; i < current->numDependents; i++) {
            printf("%s", current->dependents[i]);
            if (i != current->numDependents - 1) {
                printf(", ");
            }
        }
        printf("\n");
        current = current->nextEmployee;
    }

    if (count == 1) {
        printf("Currently, there is 1 employee.\n");
    } else {
        printf("\nCurrently, there are %d employees.\n", count);
    }
}