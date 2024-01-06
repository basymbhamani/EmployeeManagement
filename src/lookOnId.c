#include "../include/headerA3.h"

int lookOnId (struct employee * headLL, int whichEmpId) {
    int count = 0;
    struct employee *current = headLL;
    while (current != NULL) {
        count++;
        if (current->empId == whichEmpId) {
            return count;
        }
        current = current->nextEmployee;
    }
    return -1;
}
