#ifndef _SINGLY_LINKEDLIST_FUNCTIONS_H_
#define _SINGLY_LINKEDLIST_FUNCTIONS_H_

/**
 * getNewPatient - Add New Patients to Waiting List.
 * @name: Name of new patient to add.
 * @counter: Position of the new patient added
 *
 * Description: This function basically adds new patient to the waiting list
 * using the singly linkedlist algorithm concept.
 *
 * Return: This function returns a struct pointer upon successful execution.
 */
struct Patient *getNewPatient(char *name, char counter)
{
	struct Patient *newPatient;

	newPatient = (struct Patient *)malloc(sizeof(struct Patient));
	strcpy(newPatient->patientName, name);

	newPatient->patientPosition = counter;
	newPatient->nextPatient = NULL;

	return (newPatient);
}

/**
 * printPatients - Prints all the Content of the Waiting List.
 * @startList: The struct that starts the waiting list ie the first patient on
 * the list.
 *
 * Description: This function basically prints all the contents of the waiting
 * list starting from the first patient on the list.
 */
void printPatients(struct Patient *startList)
{
	while (startList != NULL)
	{
		printf("\n Name of patient: %s | Position on waiting list: %d\n",
			startList->patientName, startList->patientPosition);

		startList = startList->nextPatient;
	}
}

/**
 * deletePatients - Deletes all the Patients on the Waiting List.
 * @startDelete: The struct that starts the deleting point on waiting list ie
 * the first patient on the list.
 *
 * Description: This function basically deletes and frees the memory associated
 * with all the patients on the waiting list starting from the first patient on
 * the list.
 */
void deletePatients(struct Patient *startDelete)
{
	struct Patient *deleteHelper;
	char patientStatus[13] = "Memory Freed";

	while (startDelete != NULL)
	{
		printf("\n Name of patient: %s | Status: %s\n",
			startDelete->patientName, patientStatus);

		deleteHelper = startDelete->nextPatient;
		free(startDelete);
		startDelete = deleteHelper;
	}
}

#endif /* _SINGLY_LINKEDLIST_FUNCTIONS_H_ */
