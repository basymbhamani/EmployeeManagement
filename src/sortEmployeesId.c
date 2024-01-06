#include "../include/headerA3.h"
//#include "../src/helperA3.c"


void sortEmployeesId (struct employee * headLL) {

    if (headLL == NULL) {
        printf("There are no employees in the list. Unable to sort.\n");
    }
    int swapped;
    struct employee *ptr1;
    struct employee *ptr2 = NULL;

    if (headLL == NULL) {
        return;
    }

    do {
        swapped = 0;
        ptr1 = headLL;

        while (ptr1->nextEmployee != ptr2) 
        { 
            if (ptr1->empId > ptr1->nextEmployee->empId) 
            { 
                swap(ptr1, ptr1->nextEmployee); 
                swapped = 1; 
            } 
            ptr1 = ptr1->nextEmployee; 
        } 
        ptr2 = ptr1; 
    } while (swapped); 
}
