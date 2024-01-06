#include "../include/headerA3.h"

a3Emp *createEmpDataFromFile(FILE *filePtr)
{ // helper func

   a3Emp *tempPtr = NULL;

   char oneRecord[100]; // assume that an employee record cannot
                        // be more than 99 characters long

   char tempFname[MAX_LENGTH], tempLname[MAX_LENGTH];
   char tempDependents[2][MAX_LENGTH];

   strcpy(oneRecord, "");
   strcpy(tempFname, "");
   strcpy(tempLname, "");
   for (int i = 0; i < 2; i++)
   {
      strcpy(tempDependents[i], "");
   }
   int tempId = 0, tempNumD = 0;

   fgets(oneRecord, 100, filePtr);

   oneRecord[strlen(oneRecord) - 1] = '\0';

   int numRead = sscanf(oneRecord, "%s %s %d%d %s %s", tempFname, tempLname, &tempId, &tempNumD, tempDependents[0], tempDependents[1]);

   tempPtr = malloc(sizeof(a3Emp));

   strcpy(tempPtr->fname, tempFname);
   strcpy(tempPtr->lname, tempLname);

   tempPtr->empId = tempId;
   tempPtr->numDependents = tempNumD;

   tempPtr->dependents = malloc(sizeof(char *) * 2);

   tempPtr->dependents[0] = malloc(sizeof(strlen(tempDependents[0]) + 1));
   strcpy(tempPtr->dependents[0], tempDependents[0]);

   tempPtr->dependents[1] = malloc(sizeof(strlen(tempDependents[1]) + 1));
   strcpy(tempPtr->dependents[1], tempDependents[1]);

   tempPtr->nextEmployee = NULL;

   if (numRead == 6)
   {
      printf("Creating emp records from File.. %s\n", tempPtr->fname);
      return tempPtr;
   }
   else
   {
      for (int i = 0; i < 2; i++)
      {
         free(tempPtr->dependents[i]);
      }
      free(tempPtr->dependents);
      free(tempPtr);
      return NULL;
   }
}

void loadEmpData(struct employee **headLL, char fileName[MAX_LENGTH])
{

   FILE *filePtr;

   a3Emp *node;
   a3Emp *tempPtr = *headLL;
   int count = 0;

   filePtr = fopen(fileName, "r");

   if (filePtr == NULL)
   {
      printf("Problem opening the given file \n");
      return;
   }

   if (tempPtr != NULL)
   {
      while (tempPtr->nextEmployee != NULL)
      {
         tempPtr = tempPtr->nextEmployee;
      }
   }

   while (!feof(filePtr))
   {

      node = createEmpDataFromFile(filePtr);

      if (node != NULL)
      {

         count++;

         if (tempPtr == NULL)
         {
            *headLL = node;
            tempPtr = node;
         }
         else
         {
            tempPtr->nextEmployee = node;
            tempPtr = tempPtr->nextEmployee;
         }
      }
   }
   fclose(filePtr);
}


void swap(struct employee *a, struct employee *b) 
{
   int tempEmpId;
   char tempFirstName [MAX_LENGTH];
   char tempLastName [MAX_LENGTH];
   int tempNumDependents;
   //char ** tempDependents;

   tempEmpId = a->empId;
   a->empId = b->empId;
   b->empId = tempEmpId;

   strcpy(tempFirstName, a->fname);
   strcpy(a->fname, b->fname);
   strcpy(b->fname, tempFirstName);

   strcpy(tempLastName, a->lname);
   strcpy(a->lname, b->lname);
   strcpy(b->lname, tempLastName);

//    tempDependents = malloc(sizeof(char*) * a->numDependents);
//    for (int i = 0; i < a->numDependents; i++) {
//       tempDependents[i] = malloc(sizeof(char) * (strlen(a->dependents[i]) + 1));
//       strcpy(tempDependents[i], a->dependents[i]);
//    }

//    a->dependents = realloc(a->dependents, sizeof(char*) * b->numDependents);
//    for (int i = 0; i < b->numDependents; i++) {
//       a->dependents[i] = realloc(a->dependents[i], sizeof(char) * (strlen(b->dependents[i]) + 1));
//       strcpy(a->dependents[i], b->dependents[i]);
//    }

//    b->dependents = realloc(b->dependents, sizeof(char*) * a->numDependents);
//    for (int i = 0; i < a->numDependents; i++) {
//       b->dependents[i] = realloc(b->dependents[i], sizeof(char) * (strlen(tempDependents[i]) + 1));
//       strcpy(b->dependents[i], tempDependents[i]);
//    }

    
    tempNumDependents = a->numDependents;
    a->numDependents = b->numDependents;
    b->numDependents = tempNumDependents;

    char **tempDependents = a->dependents;
    a->dependents = b->dependents;
    b->dependents = tempDependents;
}
