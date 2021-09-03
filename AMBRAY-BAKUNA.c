/*
        Do NOT forget to include your name and section below.

        LASTNAME, FIRSTNAME: AMBRAY, ALEXIS       SECTION: S11

        DO NOT define a main() function in this file.  The main() function
   definition is already given in the accompanying main.c file.

        Note that if you compile JUST this file only, you will get an error that
   says "undefined reference to WinMain" (for DEVCPP users).

        You'll have to include this file first in main.c via #include, and then
   it is the main.c that you you should compile to produce the main.exe file.

    Violation of any of the RESTRICTIONS or non-compliance with the
   specifications will result to point deductions.
*/

/* DO NOT CHANGE THE #include below.  You are NOT allowed to include other
 * files. */
#include <stdio.h>
#include <string.h>

#include "bakuna.h"

/*
        RESTRICTION: Do not use any library function not discussed in our class
   or Course Notes. You are limited to using only four string functions,
   specifically:

                        strlen(), strcpy(), strcat() and strcmp()

        A solution that does not comply with this restriction will be considered
   an incorrect solution, and therefore, the score for the required function
   will be zero.
*/

/*
        You may define any number of helper functions that you deem necessary
   below this comment. You are free to decide on the function return type, name,
   and parametrization of your helper functions.
*/

/*
        TO DO #1: Implement Search_by_Name() as described in the problem specs.

        name_key is the search key (containing the last name and first name of
   the person to be searched) VACCINEE[] is the array of structures (containing
   info about people who will be scheduled for vaccination) n is the actual
   number of elements in VACCINEE[] where n <= MAXSIZE.
*/
int Search_by_Name(nameType name_key, vaccineeType VACCINEE[], int n) {
  /*
          Declare your own local variables.
          Do NOT call printf() or scanf() in this function.
  */
  int i;

  for (i = 0; i < n; i++)

    if (strcmp(name_key.first, VACCINEE[i].name.first) == 0 &&
        strcmp(name_key.last, VACCINEE[i].name.last) == 0)
      return i;

  return -1;  // not found
}

/*
        TO DO #2: Implement Set_Priority() as described in the problem specs.

        You'll have to acccess the structure members indirectly via the formal
        structure pointer parameter ptr_vaccine.

        NOTE: Set_Priority() is called inside the Prioritize() function.  See
   test_functions.c.
*/
void Set_Priority(vaccineeType* ptr_vaccinee) {
  /*
          Declare your own local variables.
          Do NOT call printf() or scanf() in this function.
  */

  if (ptr_vaccinee->bool_frontliner == 1)
    ptr_vaccinee->priority = 1;

  else if (ptr_vaccinee->age >= 60)
    ptr_vaccinee->priority = 2;

  else if (ptr_vaccinee->bool_comorbidity == 1)
    ptr_vaccinee->priority = 3;
  else
    ptr_vaccinee->priority = 4;
}

/*
        TO DO #3: Implement Count_Per_Category() as described in the problem
   specs.
*/
void Count_Per_Category(vaccineeType VACCINEE[], int n) {
  /*
          Declare your own local variables.
          Do NOT call scanf() in this function.
  */
  int i;
  int priority_count[4] = {0, 0, 0, 0};

  /* 	Do NOT delete the following printf() statement. */
  printf("PRIORITY  COUNT\n");

  for (i = 0; i < n; i++) {
    if (VACCINEE[i].priority == 1)
      priority_count[0] = priority_count[0] + 1;
    else if (VACCINEE[i].priority == 2)
      priority_count[1] = priority_count[1] + 1;
    else if (VACCINEE[i].priority == 3)
      priority_count[2] = priority_count[2] + 1;
    else if (VACCINEE[i].priority == 4)
      priority_count[3] = priority_count[3] + 1;
  }

  // Use printf() after this comment to print the values for the PRIORITY and
  // COUNT column there should be at least one space between values on the same
  // line of output
  printf("PRIORITY  COUNT");
  for (i = 0; i < 4; i++)
    printf("%d\t\t\t%d\n", i + 1, priority_count[i]);
}

/*
        TO DO #4: Implement Schedule_Vaccinee() as described in the problem
   specs.

        You must acccess the sched structure members indirectly via the formal
        structure pointer parameter ptr_sched.
*/
void Schedule_Vaccinee(schedType* ptr_sched, vaccineeType VACCINEE[], int n) {
  /*
          Declare your own local variables.
          Do NOT call printf() or scanf() in this function.
  */
  int i, j;
  int cnt_slot = 0;
  for (i = 1; i <= 4; i++) {
    for (j = 0; j < n; j++) {
      if (VACCINEE[j].priority == i) {
        ptr_sched->VID[cnt_slot] = VACCINEE[j].ID;
        cnt_slot = cnt_slot + 1;
      }
    }
  }
  ptr_sched->n_slots_taken = cnt_slot;
}

/*
        TO DO #5: Implement Search_Schedule() as described in the problem specs.
*/
int Search_Schedule(nameType name,
                    schedType sched,
                    vaccineeType VACCINEE[],
                    int n) {
  /*
          Declare your own local variables.
          Do NOT call printf() or scanf() in this function.
  */

  /*
          HINT: call Search_by_Name().
  */

  int index = Search_by_Name(name, VACCINEE, n);
  int i;

  for (i = 0; i < sched.n_slots_taken; i++)
    if (sched.VID[i] == VACCINEE[index].ID)
      return i;

  return -1;  // not found
}

/*******************************************************************************
    WARNING!!!   WARNING!!!   WARNING!!!

        YOU ARE NOT ALLOWED TO DEFINE the main() function in this file.

    The main() is in the accompanying main.c source file.

        VIOLATION OF THIS RESTRICTION WILL RESULT TO A DEDUCTION OF 10 points!
********************************************************************************/
