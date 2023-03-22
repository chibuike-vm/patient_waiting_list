#ifndef _SINGLY_LINKEDLIST_VARIABLES_H_
#define _SINGLY_LINKEDLIST_VARIABLES_H_

/**
 * struct Patient - Declaration for Patient Details
 *
 * @patientName: Name of the patient.
 * @patientPosition: Position of the patient on the waiting list.
 * @nextPatient: Struct pointer pointing to the next patient on the list.
 */
struct Patient
{
	char patientName[20];
	char patientPosition;
	struct Patient *nextPatient;
};

#endif /* _SINGLY_LINKEDLIST_VARIABLES_H_ */
