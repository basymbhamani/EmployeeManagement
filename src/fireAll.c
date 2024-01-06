#include "../include/headerA3.h"

// void fireAll(a3Emp * head) {
//     while (head != NULL) {
//     a3Emp * temp = head;
//     head = temp->nextEmployee;
//     free(temp);
//     }
//     free(head);
// }

void fireAll(a3Emp **head)
{

    if (*head = NULL) {
        printf("There are no employees in the list\n");
        return;
    }

    a3Emp *current = *head;
    a3Emp *next;

    while (current != NULL) {
        next = current->nextEmployee; // Store the next node pointer before deleting the current node
        free(current); // Free the memory of the current node
        current = next; // Move to the next node
    }

    *head = NULL;
}


