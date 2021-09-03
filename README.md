# Problem: BAKUNA (contributed by F.R. Salvador)
## Let's apply what you learned on structures, arrays and strings by developing some functions for a program that can be used for scheduling people for COVID-19 vaccination.

### Your task is to edit the accompanying skeleton file *LASTNAME-BAKUNA.c* and implement the 5 functions below:
+ *int Search_by_Name(nameType name_key, vaccineeType VACCINEE[], int n)* 
  + Implement a linear search algorith to search the *VACCINEE[]* list if there is a matching element corresponding to the *name_key*
  + If there is a match, returh the corresponding array index where it was found in the list
  + Otherwise, return a value of -1 to indicate NOT FOUND!

+ *void Set_Priority(vaccineeType *ptr_vaccinee)*
  + Implement *Set_Priority()* which will determine and store the value of the structure member *priority*
  + Note that you'll need to access the structure members *indirectly* via the structure pointer *ptr_vaccinee*

+ *void Count_Per_Category(vaccineeType VACCINEE[], int n)*
  + Implement *Count_Per_Category()* which will count and *printf()* the number of vaccinees per category/priority

+ *void Schedule_Vaccinee(schedType *ptr_sched, vaccineeType VACCINEE[], int n)*
  + Vaccinees are scheduled based on priority 
  + Tie breaker: vaccinees with the same priority will be sequenced based on their ID number
    + person with lower ID number will be scheduled first 
  + This function will updated the contents of the *sched* structure indirectly via formal parameter *ptr_sched*

+ *int Search_Schedule(nameType name, schedType sched, vaccineeType VACCINEE[], int n)*
  + Implement *Search_Schedule()* to determine if a person was scheduled for vacination
    + if yes, what is the corresponding sequence number?
    + if the name of the person does not exist, return a value of -1
