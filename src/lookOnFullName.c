#include "../include/headerA3.h"

int lookOnFullName (struct employee * headLL, char whichName [100]) {
    int count = 0;
    struct employee *current = headLL;
    while (current != NULL) {
        count++;
        char firstName[100];
        char lastName[100];

        sscanf(whichName, "%s %s", firstName, lastName);
        
        if (strcmp(current->fname, firstName) == 0 && strcmp(current->lname, lastName) == 0) {
            return count;
        }
        current = current->nextEmployee;
    }
    return -1;
}