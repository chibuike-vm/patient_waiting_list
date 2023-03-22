#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../variables/singly_linkedlist_variables.h"
#include "../functions/singly_linkedlist_functions.h"

/**
 * main - Program Entry Point
 *
 * Desciption: This function basically runs by calling other functions to
 * mainipulate data using the singly list algorithm concept.
 *
 * Return: This function returns zero upon successful execution.
 */
int main(void)
{
	struct Patient *firstPatient, *incomingPatient;
	char counter = 0, sscanfChecker;

	firstPatient = NULL;
	incomingPatient = NULL;

	while (1)
	{
		counter++;

		char name[20], reply[20], *replyPtr;

		printf("\n\n************ WELCOME TO LIFEJACKET PHARMACY ************\n\n\n");

		printf(" Note: There's a FIFO queue system of patients.\n\n");
		printf(" Do you wish to join the patient waiting list queue?");
		printf("\n Please, kindly indicate by entering 'yes' or 'no': ");
		replyPtr = fgets(reply, 20, stdin);
		sscanfChecker = sscanf(replyPtr, "%s", reply);

		/* To check for the success of the sscanf function */
		(sscanfChecker == 0) ? printf("\nsscanf failed.\n") : counter;

		if (strcmp(reply, "yes") == 0)
		{
			printf("\n Please, enter your name to join the waiting list: ");
			replyPtr = fgets(reply, 20, stdin);
			sscanfChecker = sscanf(replyPtr, "%s", name);

			/* To check for the success of the sscanf function */
			(sscanfChecker == 0) ? printf("\nsscanf failed.\n") : counter;

			if (firstPatient == NULL)
			{
				firstPatient = getNewPatient(name, counter);
				incomingPatient = firstPatient;

				printf("\n Hurray! Dear %s, you are number %d On the waiting list",
					firstPatient->patientName, firstPatient->patientPosition);
			}
			else
			{
				incomingPatient->nextPatient = getNewPatient(name, counter);
				incomingPatient = incomingPatient->nextPatient;

				printf("\n Dear %s, you are number %d on the waiting list.",
					incomingPatient->patientName, incomingPatient->patientPosition);
			}

		}
		else if ((strcmp(reply, "no") == 0))
		{
			char action[10], *actionPtr;

			if (counter >= 2)
			{
				printf("\n\n Do you wish to print the content of the waiting list?");
				printf("\n Please kindly indicate by entering 'yes' or 'no': ");
				actionPtr = fgets(action, 10, stdin);
				sscanfChecker = sscanf(actionPtr, "%s", action);

				/* To check for the success of the sscanf function */
				(sscanfChecker == 0) ? printf("\nsscanf failed.\n") : counter;

				if (strcmp(action, "yes") == 0)
				{
					printf("\n\n Printing patient waiting list...\n\n");
					printPatients(firstPatient);
					break;
				}
				else
				{
					printf("\n\n Succesfully declined to print waiting list.\n\n");
					break;
				}
			}
			else if (counter == 1)
			{
				printf("\n\n Please, its a civic responsibility to be organized.\n");
				printf(" Kindly reconsider and join the queue. Thank you.\n\n");
				break;
			}
		}
		else
		{
			printf("\n Please, follow the instruction and enter a valid response.\n\n");
			break;
		}

		printf("\n\n\n******** POWERED BY SINGLY LINKEDLIST ALGORITHM ********\n\n");
	}

	printf("\n\n Freeing Memory...\n\n");
	deletePatients(firstPatient);

	printf("\n\n******** POWERED BY SINGLY LINKEDLIST ALGORITHM ********\n\n");

	return (0);
}

