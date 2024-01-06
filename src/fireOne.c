#include "../include/headerA3.h"


void fireOne (a3Emp ** headLL, int whichOne) {

    if (whichOne > countEmployees(*headLL) || whichOne < 1) {
        return;
    }

    if (*headLL == NULL) {
        printf("There are no employees in the list\n");
    }

    a3Emp *temp = *headLL;
    a3Emp *previous;

    if (whichOne == 1) {
        *headLL = (*headLL)->nextEmployee;
        free (temp);
        return;
    }
    else {
        for (int i = 0; i < whichOne-1; i++) {
            previous = temp;
            temp = temp->nextEmployee;
        }

        previous->nextEmployee = temp->nextEmployee;

        free(temp);
    }

}