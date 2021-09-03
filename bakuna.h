/*
    Header file for BAKUNA problem.
    
    Do NOT change this file.
*/


/* CONCENTRATE only on Lines 14 to 75; you need not be concerned with the other lines. */

#ifndef THIS_HEADER_FILE 

	#define THIS_HEADER_FILE (1)

	// DO NOT change the two #defines below
	#define MAXSIZE  100
	#define MAXSLOTS 100
	
	// DO NOT change the following typedef
	typedef char String[11];

	// date structure data type
	struct dateTag {
		int month;
		int day;
		int year;
	};

	typedef struct dateTag dateType;

	// schedule structure data type
	struct schedTag {
		dateType date;
		int n_slots_taken;  // number of slots already taken
		int VID[MAXSLOTS];	// VID means Vaccinee ID.  VID[i] stores the ID number of the person to be vaccinated
	    	                // ex. VID[0] = 102  
							//     means that the 1st person to be vaccinated during
							//     schedule is the person with ID number 102.
	};

	typedef struct schedTag schedType;

	// name structure data type
	struct nameTag {
		String last;
		String first;
	};

	typedef struct nameTag nameType;

	// vaccinee structure data type
	struct vaccineeTag {
		int ID;                 // ID number of the vaccinee, note that this number is system-generated (i.e., not a user input)
		nameType name;          // name of vacinee
		int age;                // age of vacinee
		int bool_frontliner;    // 0 means not frontliner, 1 means frontliner
		int bool_comorbidity;   // 0 means no comorbidity, 1 means with comorbiditity 
		int priority;           // 0 means priority not yet set, 1 to 4 means priority is set 
		                        //   where 1 is the highest priority and 4 is the lowest priority
	};

	typedef struct vaccineeTag vaccineeType;

	// function protoypes -- the functions are already given
	int Read_Data(vaccineeType VACCINEE[], int *ptr_systemID);	
	void Print_Data(vaccineeType VACCINEE[], int n);
	int Search_by_ID(int id_key, vaccineeType VACCINEE[], int n);
	void Print_Sched_Info(schedType sched, vaccineeType VACCINEE[], int n);
	void Prioritize(vaccineeType VACCINEE[], int n);  // note: this is already defined

	// function prototypes for the functions that the student need to define in the source file LASTNAME_BAKUNA.c
	int Search_by_Name(nameType name_key, vaccineeType VACCINEE[], int n);
	void Set_Priority(vaccineeType *ptr_vaccinee);
	void Count_Per_Category(vaccineeType VACCINEE[], int n);
	void Schedule_Vaccinee(schedType *ptr_sched, vaccineeType VACCINEE[], int n);
	int Search_Schedule(nameType name, schedType sched, vaccineeType VACCINEE[], int n);

#endif
