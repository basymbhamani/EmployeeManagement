#include "../include/headerA3.h"

int countEmployees (a3Emp * headLL) {

    if (headLL == NULL) {
        printf("There are no employees in the list.\n");
        return 0;
    }
    int count = 0;
    struct employee *current = headLL;
    while (current != NULL) {
        count++;
        current = current->nextEmployee;
    }
    return count;
}